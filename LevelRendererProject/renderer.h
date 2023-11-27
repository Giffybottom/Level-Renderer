#include <d3dcompiler.h>	// required for compiling shaders on the fly, consider pre-compiling instead
#include "FSLogo.h"
#include "load_data_oriented.h"
#pragma comment(lib, "d3dcompiler.lib")
using namespace std::chrono;

void PrintLabeledDebugString(const char* label, const char* toPrint)
{
	std::cout << label << toPrint << std::endl;
#if defined WIN32 //OutputDebugStringA is a windows-only function 
	OutputDebugStringA(label);
	OutputDebugStringA(toPrint);
#endif
}

// Creation, Rendering & Cleanup
class Renderer
{
	// proxy handles
	GW::SYSTEM::GWindow win;
	GW::GRAPHICS::GDirectX11Surface d3d;
	// what we need at a minimum to draw a triangle
	Microsoft::WRL::ComPtr<ID3D11Buffer>		vertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer>		indexBuffer; // Part 2G
	Microsoft::WRL::ComPtr<ID3D11Buffer>		constantSceneBuffer; // Part 2C
	Microsoft::WRL::ComPtr<ID3D11Buffer>		constantMeshBuffer; // Part 2C
	Microsoft::WRL::ComPtr<ID3D11Buffer>		constantIDBuffer;
	Microsoft::WRL::ComPtr<ID3D11VertexShader>	vertexShader;
	Microsoft::WRL::ComPtr<ID3D11PixelShader>	pixelShader;
	Microsoft::WRL::ComPtr<ID3D11InputLayout>	vertexFormat;

	struct Scene_Data
	{

		GW::MATH::GMATRIXF _viewMatrix;       //(float * 4)^4 bytes
		GW::MATH::GMATRIXF _projectionMatrix; //(float * 4)^4 bytes
		GW::MATH::GVECTORF _lightDirection;   //lighting info
		GW::MATH::GVECTORF _lightColor;       //lighting info
		GW::MATH::GVECTORF _lightAmbient;
		GW::MATH::GVECTORF _cameraPos;
	};

	struct Mesh_Data
	{
		GW::MATH::GMATRIXF _worldMatrix[200];   //world space transform
		H2B::ATTRIBUTES _material[200];           //material information (color, reflectivity, emissiveness, ets...)
	};

	//h2bs save locations/index of the arrays and materials.
	//mesh has its own material
	//h2bs know what index to pull from
	//these ids are the indexes to point to the information
	//these ids x and y will point to the world and material information from the h2b files
	struct Data_for_IDs
	{
		GW::MATH::GVECTORF transforms;
	};

	// Cameras
	std::vector<GW::MATH::GMATRIXF> cameras;

	// Viewports
	D3D11_VIEWPORT viewports[2];

	Level_Data dataOrientedLoader;

	Scene_Data _sceneData;
	Mesh_Data _meshData;
	Data_for_IDs _idData;
	GW::MATH::GMatrix _mathLibrary;
	GW::MATH::GMATRIXF _world;
	GW::MATH::GMATRIXF _view;
	GW::MATH::GMATRIXF _projection;
	GW::MATH::GMATRIXF identity;
	GW::MATH::GMATRIXF cameraMatrix;

	//directional light
	GW::MATH::GVECTORF lightDir;
	GW::MATH::GVECTORF lightColor;

	//ambient light
	GW::MATH::GVECTORF _ambientLight;

	//Input Utility
	GW::INPUT::GInput input;
	GW::INPUT::GController controller;

	steady_clock steadyClock;
	time_point<steady_clock> begin;
	time_point<steady_clock> update;

	// Screen Info
	unsigned int screen_height = 0;
	unsigned int screen_width = 0;

	struct File_Info
	{
		const char* gameLevelTxt;
		const char* assetFile;
	};

	File_Info AllLevelFiles[2];

public:
	Renderer(GW::SYSTEM::GWindow _win, GW::GRAPHICS::GDirectX11Surface _d3d)
	{
		win = _win;
		d3d = _d3d;

		// Swap Level Info
		AllLevelFiles[0] = { "../GameLevel.txt", "../Assets1" };
		AllLevelFiles[1] = { "../GameLevel2.txt", "../Assets1" };

		//Set Screen Width/Height
		_win.GetHeight(screen_height);
		_win.GetWidth(screen_width);

		// Used for controller and keyboard input
		input.Create(win);
		controller.Create();

		_mathLibrary.Create();
		_mathLibrary.IdentityF(_world);
		_mathLibrary.IdentityF(_view);
		_mathLibrary.IdentityF(_projection);
		_mathLibrary.IdentityF(identity);

		GW::MATH::GVECTORF translateWorld;
		translateWorld.x = 0.0f;
		translateWorld.y = 0.0f;
		translateWorld.z = 0.0f;
		GW::MATH::GVECTORF rotateWorld;
		rotateWorld.x = 0.0f;
		rotateWorld.y = 0.5f;
		rotateWorld.z = 0.0f;
		rotateWorld.w = 0.0f;
		_mathLibrary.TranslateGlobalF(_world, translateWorld, _world);

		GW::MATH::GVECTORF translateView;
		translateView.x = 0.75f;
		translateView.y = 0.25f;
		translateView.z = -2.5f;
		_mathLibrary.TranslateLocalF(_view, translateView, _view);
		GW::MATH::GVECTORF up;
		GW::MATH::GVECTORF lookAtMe;
		up.x = 0.0f;
		up.y = 1.0f;
		up.z = 0.0f;
		lookAtMe.x = 0.15f;
		lookAtMe.y = 0.75f;
		lookAtMe.z = 0.0f;
		_mathLibrary.LookAtLHF(translateView, lookAtMe, up, _view);

		_mathLibrary.InverseF(_view, _view);
		_sceneData._cameraPos = _view.row4;
		_mathLibrary.InverseF(_view, _view);
		_sceneData._viewMatrix = _view;

		float fovY = 1.13446;
		float aspect = 0;
		d3d.GetAspectRatio(aspect);
		float zNear = 0.1f;
		float zFar = 100.0f;
		_mathLibrary.IdentityF(_projection);
		_mathLibrary.ProjectionDirectXLHF(fovY, aspect, zNear, zFar, _projection);
		_sceneData._projectionMatrix = _projection;

		//directional light
		lightDir = { -1.0f, -1.0f, 2.0f, 0.0f };
		GW::MATH::GVector::NormalizeF(lightDir, lightDir);
		_sceneData._lightDirection = lightDir;
		lightColor = { 0.9f, 0.9f, 1.0f, 0.0f };
		_sceneData._lightColor = lightColor;
		// Ambient Light
		_ambientLight = { 63.75 / 255, 63.75 / 255, 89.25 / 255 };
		_sceneData._lightAmbient = _ambientLight;

		///////////////////////Information Gets Loaded In/////////////////////////
		GW::SYSTEM::GLog log; // handy for logging any messages/warning/errors
		// begin loading level
		log.Create("../testLevelLoaderLog.txt");
		log.EnableConsoleLogging(true); // mirror output to the console
		log.Log("Start Program.");

		dataOrientedLoader.LoadLevel(AllLevelFiles[0].gameLevelTxt, AllLevelFiles[0].assetFile, log);

		log.Log("End Program.");

		//load all of the materials into our constant buffer
		for (int i = 0; i < dataOrientedLoader.levelMaterials.size(); i++)
		{
			_meshData._material[i] = dataOrientedLoader.levelMaterials[i].attrib;
		}
		//load all of the transforms into our constant buffer
		for (int i = 0; i < dataOrientedLoader.levelTransforms.size(); i++)
		{
			_meshData._worldMatrix[i] = dataOrientedLoader.levelTransforms[i];
		}
		/////////////////////////////////////////////////////////////////////////////
		
		//Camera Set Up
		for (const auto loadedCamera : dataOrientedLoader.cameras)
		{
			GW::MATH::GMATRIXF whateverneedstogetpassedintothis;
			_mathLibrary.InverseF(loadedCamera.position, whateverneedstogetpassedintothis);
			cameras.push_back(whateverneedstogetpassedintothis);
		}

		IntializeGraphics();
	}

private:
	//constructor helper functions
	void IntializeGraphics()
	{
		ID3D11Device* creator;
		d3d.GetDevice((void**)&creator);

		InitializeVertexBuffer(creator);

		InitializeIndexBuffer(creator);

		D3D11_SUBRESOURCE_DATA b1Data = { &_sceneData, 0, 0 };
		CD3D11_BUFFER_DESC b1Desc(sizeof(Scene_Data), D3D11_BIND_CONSTANT_BUFFER, D3D11_USAGE_DYNAMIC, D3D11_CPU_ACCESS_WRITE);
		creator->CreateBuffer(&b1Desc, &b1Data, constantSceneBuffer.GetAddressOf());

		D3D11_SUBRESOURCE_DATA b2Data = { &_meshData, 0, 0 };
		CD3D11_BUFFER_DESC b2Desc(sizeof(Mesh_Data), D3D11_BIND_CONSTANT_BUFFER, D3D11_USAGE_DYNAMIC, D3D11_CPU_ACCESS_WRITE);
		creator->CreateBuffer(&b2Desc, &b2Data, constantMeshBuffer.GetAddressOf());

		D3D11_SUBRESOURCE_DATA b3Data = { &_idData, 0, 0 };
		CD3D11_BUFFER_DESC b3Desc(sizeof(Data_for_IDs), D3D11_BIND_CONSTANT_BUFFER, D3D11_USAGE_DYNAMIC, D3D11_CPU_ACCESS_WRITE);
		creator->CreateBuffer(&b3Desc, &b3Data, constantIDBuffer.GetAddressOf());

		InitializePipeline(creator);

		// free temporary handle
		creator->Release();
	}

	void InitializeVertexBuffer(ID3D11Device* creator)
	{
		CreateVertexBuffer(creator, dataOrientedLoader.levelVertices.data(), sizeof(H2B::VERTEX) * dataOrientedLoader.levelVertices.size());

		H2B::VECTOR test1 = dataOrientedLoader.levelVertices[0].pos;
	}

	void InitializeIndexBuffer(ID3D11Device* creator)
	{
		CreateIndexBuffer(creator, dataOrientedLoader.levelIndices.data(), sizeof(unsigned int) * dataOrientedLoader.levelIndices.size());
	}

	void CreateVertexBuffer(ID3D11Device* creator, const void* data, unsigned int sizeInBytes)
	{
		D3D11_SUBRESOURCE_DATA bData = { data, 0, 0 };
		CD3D11_BUFFER_DESC bDesc(sizeInBytes, D3D11_BIND_VERTEX_BUFFER);
		creator->CreateBuffer(&bDesc, &bData, vertexBuffer.GetAddressOf());
	}

	void CreateIndexBuffer(ID3D11Device* creator, const void* data, unsigned int sizeInBytes)
	{
		D3D11_SUBRESOURCE_DATA bData = { data, 0, 0 };
		CD3D11_BUFFER_DESC bDesc(sizeInBytes, D3D11_BIND_INDEX_BUFFER);
		creator->CreateBuffer(&bDesc, &bData, indexBuffer.GetAddressOf());
	}

	void InitializePipeline(ID3D11Device* creator)
	{
		UINT compilerFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if _DEBUG
		compilerFlags |= D3DCOMPILE_DEBUG;
#endif
		Microsoft::WRL::ComPtr<ID3DBlob> vsBlob = CompileVertexShader(creator, compilerFlags);
		Microsoft::WRL::ComPtr<ID3DBlob> psBlob = CompilePixelShader(creator, compilerFlags);

		CreateVertexInputLayout(creator, vsBlob);
	}

	Microsoft::WRL::ComPtr<ID3DBlob> CompileVertexShader(ID3D11Device* creator, UINT compilerFlags)
	{
		std::string vertexShaderSource = ReadFileIntoString("../Shaders/VertexShader.hlsl");

		Microsoft::WRL::ComPtr<ID3DBlob> vsBlob, errors;

		HRESULT compilationResult =
			D3DCompile(vertexShaderSource.c_str(), vertexShaderSource.length(),
				nullptr, nullptr, nullptr, "main", "vs_4_0", compilerFlags, 0,
				vsBlob.GetAddressOf(), errors.GetAddressOf());

		if (SUCCEEDED(compilationResult))
		{
			creator->CreateVertexShader(vsBlob->GetBufferPointer(),
				vsBlob->GetBufferSize(), nullptr, vertexShader.GetAddressOf());
		}
		else
		{
			PrintLabeledDebugString("Vertex Shader Errors:\n", (char*)errors->GetBufferPointer());
			abort();
			return nullptr;
		}

		return vsBlob;
	}

	Microsoft::WRL::ComPtr<ID3DBlob> CompilePixelShader(ID3D11Device* creator, UINT compilerFlags)
	{
		std::string pixelShaderSource = ReadFileIntoString("../Shaders/PixelShader.hlsl");

		Microsoft::WRL::ComPtr<ID3DBlob> psBlob, errors;

		HRESULT compilationResult =
			D3DCompile(pixelShaderSource.c_str(), pixelShaderSource.length(),
				nullptr, nullptr, nullptr, "main", "ps_4_0", compilerFlags, 0,
				psBlob.GetAddressOf(), errors.GetAddressOf());

		if (SUCCEEDED(compilationResult))
		{
			creator->CreatePixelShader(psBlob->GetBufferPointer(),
				psBlob->GetBufferSize(), nullptr, pixelShader.GetAddressOf());
		}
		else
		{
			PrintLabeledDebugString("Pixel Shader Errors:\n", (char*)errors->GetBufferPointer());
			abort();
			return nullptr;
		}

		return psBlob;
	}

	void CreateVertexInputLayout(ID3D11Device* creator, Microsoft::WRL::ComPtr<ID3DBlob>& vsBlob)
	{
		D3D11_INPUT_ELEMENT_DESC attributes[3];

		attributes[0].SemanticName = "UV_POSITION";
		attributes[0].SemanticIndex = 0;
		attributes[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		attributes[0].InputSlot = 0;
		attributes[0].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
		attributes[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		attributes[0].InstanceDataStepRate = 0;

		attributes[1].SemanticName = "UV_COORDINATE";
		attributes[1].SemanticIndex = 0;
		attributes[1].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		attributes[1].InputSlot = 0;
		attributes[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
		attributes[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		attributes[1].InstanceDataStepRate = 0;

		attributes[2].SemanticName = "UV_NORMALS";
		attributes[2].SemanticIndex = 0;
		attributes[2].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		attributes[2].InputSlot = 0;
		attributes[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
		attributes[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		attributes[2].InstanceDataStepRate = 0;

		creator->CreateInputLayout(attributes, ARRAYSIZE(attributes),
			vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(),
			vertexFormat.GetAddressOf());
	}


public:
	void Render()
	{
		//current value of clock
		begin = steadyClock.now();
		float deltaTime = duration_cast<microseconds>(begin - update).count() / 1000000.0f;
		update = begin;

		int rotationSpeed = 1;

		// Swap Levels?
		SwapLevel();

		PipelineHandles curHandles = GetCurrentPipelineHandles();
		SetUpPipeline(curHandles);
		
		D3D11_MAPPED_SUBRESOURCE gpu;

		HRESULT mapReturn = curHandles.context->Map(constantSceneBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &gpu);

		_sceneData._viewMatrix = _view;

		//memcpy_s destination, size, source, size
		//subresource.pdata (destination)
		//instance of shader variable struct (source)
		//size of struct (size)
		memcpy_s(gpu.pData, sizeof(Scene_Data), &_sceneData, sizeof(Scene_Data));
		//un map
		curHandles.context->Unmap(constantSceneBuffer.Get(), 0);

		//Loop through all level model instances 
		for (int i = 0; i < dataOrientedLoader.levelInstances.size(); i++) // total instances of all models in the scene
		{
			Level_Data::MODEL_INSTANCES& ModelInstance = dataOrientedLoader.levelInstances[i];  // current instance of some model
			// Models index into Level_Model vector (dataOriented.levelModels[modelIndex])
			ModelInstance.modelIndex;
			// Number of instances in the scene of this specific Model
			ModelInstance.transformCount;
			// Model transforms starting index inside of dataOriented.levelTransforms[transformStart]
			ModelInstance.transformStart;

			Level_Data::LEVEL_MODEL& Model = dataOrientedLoader.levelModels[ModelInstance.modelIndex]; // specific model we are drawing
			// Models Indice Info
			Model.indexCount;
			Model.indexStart;
			// Model Material Info
			Model.materialCount;
			Model.materialStart;
			// Model Mesh Info
			Model.meshCount;
			Model.meshStart;
			// Model Vertex Info
			Model.vertexCount;
			Model.vertexStart;
			//Model Batch Info (The information needed to draw the sub-mesh of a model)
			Model.batchStart;

			HRESULT mapReturn = curHandles.context->Map(constantIDBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &gpu);

			/*_idData.transforms.x = ModelInstance.transformStart;*/
			_idData.transforms.x = dataOrientedLoader.levelInstances[i].transformStart;

			memcpy_s(gpu.pData, sizeof(Data_for_IDs), &_idData, sizeof(Data_for_IDs));
			//un map
			curHandles.context->Unmap(constantIDBuffer.Get(), 0);

			int btchStrt = dataOrientedLoader.levelModels[i].batchStart;
			int indxStrt = dataOrientedLoader.levelModels[i].indexStart;
			int vertStrt = dataOrientedLoader.levelModels[i].vertexStart;

			for (int j = 0; j < dataOrientedLoader.levelModels[i].meshCount; j++) // total number of submeshes in this model
			{
				H2B::MESH& Mesh = dataOrientedLoader.levelMeshes[Model.meshStart + j];

				Mesh.drawInfo.indexCount;
				Mesh.drawInfo.indexOffset;
				Mesh.materialIndex;
				
				HRESULT mapReturn = curHandles.context->Map(constantIDBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &gpu);

				_idData.transforms.y = dataOrientedLoader.levelMeshes[btchStrt + j].materialIndex 
										+ dataOrientedLoader.levelModels[i].materialStart;

				memcpy_s(gpu.pData, sizeof(Data_for_IDs), &_idData, sizeof(Data_for_IDs));
				//un map
				curHandles.context->Unmap(constantIDBuffer.Get(), 0);

				// things to set:
				// 1. World Matrix
				// 2. material
				// we are currently only using the transform of the MODEL, we are ignoreing the transforms of the submeshes, 
				// which should be multiplied by the model transform
				// mFinalTransform = SubMeshTransform * ModelTransform;  (child times parent)

				//dataOrientedLoader.levelBatches[Model.batchStart].
				viewports[0] = { 0.0f, 0.0f, (float)screen_width, (float)screen_height, 0.0f, 1.0f };
				curHandles.context->RSSetViewports(1, viewports);

				curHandles.context->DrawIndexedInstanced(
					dataOrientedLoader.levelMeshes[btchStrt + j].drawInfo.indexCount,
					dataOrientedLoader.levelInstances[i].transformCount,
					dataOrientedLoader.levelMeshes[btchStrt + j].drawInfo.indexOffset + indxStrt,
					vertStrt,
					0);

				viewports[0] = { 0.0f, 0.0f, (float)screen_width / 2.0f, (float)screen_height / 2.0f, 0.0f, 1.0f };
				curHandles.context->RSSetViewports(1, viewports);
				curHandles.context->DrawIndexedInstanced(
					dataOrientedLoader.levelMeshes[btchStrt + j].drawInfo.indexCount,
					dataOrientedLoader.levelInstances[i].transformCount,
					dataOrientedLoader.levelMeshes[btchStrt + j].drawInfo.indexOffset + indxStrt,
					vertStrt,
					0);
			}
		}
		ReleasePipelineHandles(curHandles);
	}

	void UpdateCamera()
	{
		GW::MATH::GMATRIXF viewCopy;
		GW::MATH::GVECTORF translateMe;

		//window info
		unsigned int windowHeight = 0;
		unsigned int windowWidth = 0;
		float aspectRatio = 0;
		win.GetHeight(windowHeight);
		win.GetWidth(windowWidth);
		d3d.GetAspectRatio(aspectRatio);

		//up and down
		float space = 0;
		float lShift = 0;
		float rTrigger = 0;
		float leftTrigger = 0;

		//forward back left right
		float forward = 0;
		float backward = 0;
		float lStickY = 0;
		float lStickX = 0;
		float left = 0;
		float right = 0;

		//current value of clock
		begin = steadyClock.now();
		float deltaTime = duration_cast<microseconds>(begin - update).count() / 1000000.0f;
		update = begin;

		//update view matrix
		_mathLibrary.InverseF(_view, viewCopy);

		float deltaY = 0;
		float deltaZ = 0;
		float deltaX = 0;
		float mouseXdelta = 0;
		float mouseYdelta = 0;
		float pitchY = 0;
		float yawX = 0;
		float perFrameSpeed = 0;
		const float cameraSpeed = 10.0f;
		//Thumbstick_Speed = PI * Seconds_Passed_Since_Last_Frame
		float thumbstick_speed = 3.14159 * deltaTime;
		float total_pitch = 0;
		float total_yaw = 0;

		//up and down
		input.GetState(G_KEY_SPACE, space);
		input.GetState(G_KEY_LEFTSHIFT, lShift);
		input.GetState(G_RIGHT_TRIGGER_AXIS, rTrigger);
		input.GetState(G_LEFT_TRIGGER_AXIS, leftTrigger);

		//for testing input
		if (space != 0)
		{
			int j = 5;
		}

		deltaY = space - lShift + rTrigger - leftTrigger;
		viewCopy.row4.y += deltaY * cameraSpeed * deltaTime;

		//forward back left right
		input.GetState(G_KEY_W, forward);
		input.GetState(G_KEY_S, backward);
		input.GetState(G_LY_AXIS, lStickY);
		input.GetState(G_LX_AXIS, lStickX);
		input.GetState(G_KEY_A, left);
		input.GetState(G_KEY_D, right);

		//PerFrameSpeed = Camera_Speed * Seconds_Passed_Since_Last_Frame
		perFrameSpeed = cameraSpeed * deltaTime;
		//Total_Z_Change = W_KEY_STATE – S_KEY_STATE + LEFT_STICK_Y_AXIS_STATE
		deltaZ = forward - backward + lStickY;
		//Total_X_Change = D_KEY_STATE – A_KEY_STATE + LEFT_STICK_X_AXIS_STATE
		deltaX = right - left + lStickX;

		//TranslationMatrix(Total_X_Change * PerFrameSpeed, 0, Total_Z_Change * PerFrameSpeed)
		translateMe.x = deltaX * perFrameSpeed;
		translateMe.y = 0;
		translateMe.z = deltaZ * perFrameSpeed;

		//Camera = MatrixMultiply(TranslationMatrix, Camera)*/
		_mathLibrary.TranslateLocalF(viewCopy, translateMe, viewCopy);

		//mouse and controller stick pitch
		input.GetMouseDelta(mouseXdelta, mouseYdelta);
		if (mouseXdelta == 1 || mouseXdelta == -1)
		{
			mouseXdelta = 0;

		}
		if (mouseYdelta == 1 || mouseYdelta == -1)
		{
			mouseYdelta = 0;

		}
		input.GetState(G_RY_AXIS, pitchY);
		/*Total_Pitch = FOV * MOUSE_Y_DELTA / SCREEN_HEIGHT + RIGHT_STICK_Y_AXIS_STATE * Thumbstick_Speed * -1
		PitchMatrix(Total_Pitch)*/
		total_pitch = 1.13446 * mouseYdelta / windowHeight + pitchY * thumbstick_speed * -1.0f;
		//Camera = MatrixMultiplication(PitchMatrix, Camera)
		_mathLibrary.RotateXLocalF(viewCopy, total_pitch, viewCopy);
		//mouse and controller stick yaw
		input.GetState(G_RX_AXIS, yawX);
		//Total_Yaw = FOV * AspectRatio * MOUSE_X_DELTA / SCREEN_WIDTH + RIGHT_STICK_X_AXIS_STATE * Thumb_Speed
		total_yaw = 1.13446 * aspectRatio * mouseXdelta / windowWidth + yawX * thumbstick_speed;
		//YawMatrix(Total_Yaw)
		_mathLibrary.RotateYGlobalF(viewCopy, total_yaw, viewCopy);

		_mathLibrary.InverseF(viewCopy, _view);
	}

	bool ChangeCamera()
	{
		//Camera Options
		/*Camera MainCam;
		Camera TopDownCam;
		Camera BottomUpCam;
		Camera FlagCam;
		std::vector<Camera>AllCams;*/

		bool cameraChanged;
		float camera1Select;
		float camera2Select;
		float camera3Select;
		float camera4Select;

		input.GetState(G_KEY_1, camera1Select);
		input.GetState(G_KEY_2, camera2Select);
		input.GetState(G_KEY_3, camera3Select);
		input.GetState(G_KEY_4, camera4Select);


		if (camera1Select > 0)
		{
			_view = cameras[0];
			cameraChanged = true;
		}
		else if (camera2Select > 0)
		{
			_view = cameras[1];
			cameraChanged = true;
		}
		else if (camera3Select > 0)
		{
			_view = cameras[2];
			cameraChanged = true;
		}
		else
		{
			cameraChanged = false;
		}

		return cameraChanged;
	}

	void SwapLevel()
	{
		float level1;
		float level2;

		input.GetState(G_KEY_NUMPAD_0, level1);
		input.GetState(G_KEY_NUMPAD_1, level2);

		if (level1 == 0 && level2 == 0)
		{
			return;
		}

		dataOrientedLoader.UnloadLevel();

		GW::SYSTEM::GLog log; // handy for logging any messages/warning/errors
		// begin loading level
		log.Create("../testLevelLoaderLog.txt");
		log.EnableConsoleLogging(true); // mirror output to the console
		log.Log("Start Program.");


		if (level1 != 0)
		{
			dataOrientedLoader.LoadLevel(AllLevelFiles[0].gameLevelTxt, AllLevelFiles[0].assetFile, log);

			log.Log("End Program.");

			//load all of the materials into our constant buffer
			for (int i = 0; i < dataOrientedLoader.levelMaterials.size(); i++)
			{
				_meshData._material[i] = dataOrientedLoader.levelMaterials[i].attrib;
			}
			//load all of the transforms into our constant buffer
			for (int i = 0; i < dataOrientedLoader.levelTransforms.size(); i++)
			{
				_meshData._worldMatrix[i] = dataOrientedLoader.levelTransforms[i];
			}
			/////////////////////////////////////////////////////////////////////////////

		}
		else if (level2 != 0)
		{
			dataOrientedLoader.LoadLevel(AllLevelFiles[1].gameLevelTxt, AllLevelFiles[1].assetFile, log);

			log.Log("End Program.");

			//load all of the materials into our constant buffer
			for (int i = 0; i < dataOrientedLoader.levelMaterials.size(); i++)
			{
				_meshData._material[i] = dataOrientedLoader.levelMaterials[i].attrib;
			}
			//load all of the transforms into our constant buffer
			for (int i = 0; i < dataOrientedLoader.levelTransforms.size(); i++)
			{
				_meshData._worldMatrix[i] = dataOrientedLoader.levelTransforms[i];
			}
		}

		IntializeGraphics();
	}

private:
	struct PipelineHandles
	{
		ID3D11DeviceContext* context;
		ID3D11RenderTargetView* targetView;
		ID3D11DepthStencilView* depthStencil;
	};

	PipelineHandles GetCurrentPipelineHandles()
	{
		PipelineHandles retval;
		d3d.GetImmediateContext((void**)&retval.context);
		d3d.GetRenderTargetView((void**)&retval.targetView);
		d3d.GetDepthStencilView((void**)&retval.depthStencil);
		return retval;
	}

	void SetUpPipeline(PipelineHandles handles)
	{
		SetRenderTargets(handles);
		SetVertexBuffers(handles);
		SetIndexBuffer(handles);
		SetShaders(handles);

		//Set vertex shader scene and mesh buffers.
		ID3D11Buffer* sceneBufferArray[] = { constantSceneBuffer.Get() };
		handles.context->VSSetConstantBuffers(0, 1, sceneBufferArray);

		ID3D11Buffer* meshBufferArray[] = { constantMeshBuffer.Get() };
		handles.context->VSSetConstantBuffers(1, 1, meshBufferArray);

		ID3D11Buffer* IDBufferArray[] = { constantIDBuffer.Get() };
		handles.context->VSSetConstantBuffers(2, 1, IDBufferArray);

		//Set pixel shader scene and mesh buffers.
		ID3D11Buffer* PSsceneBufferArray[] = { constantSceneBuffer.Get() };
		handles.context->PSSetConstantBuffers(0, 1, PSsceneBufferArray);

		ID3D11Buffer* PSmeshBufferArray[] = { constantMeshBuffer.Get() };
		handles.context->PSSetConstantBuffers(1, 1, PSmeshBufferArray);

		ID3D11Buffer* PSidBufferArray[] = { constantIDBuffer.Get() };
		handles.context->PSSetConstantBuffers(2, 1, PSidBufferArray);

		handles.context->IASetInputLayout(vertexFormat.Get());
		handles.context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	}

	void SetRenderTargets(PipelineHandles handles)
	{
		ID3D11RenderTargetView* const views[] = { handles.targetView };
		handles.context->OMSetRenderTargets(ARRAYSIZE(views), views, handles.depthStencil);
	}

	void SetVertexBuffers(PipelineHandles handles)
	{
		const UINT strides[] = { sizeof(H2B::VERTEX) };
		const UINT offsets[] = { 0 };
		ID3D11Buffer* const buffs[] = { vertexBuffer.Get() };
		handles.context->IASetVertexBuffers(0, ARRAYSIZE(buffs), buffs, strides, offsets);
	}

	void SetIndexBuffer(PipelineHandles handles)
	{
		ID3D11Buffer* const buff = { indexBuffer.Get() };
		handles.context->IASetIndexBuffer(buff, DXGI_FORMAT_R32_UINT, 0);
	}

	void SetShaders(PipelineHandles handles)
	{
		handles.context->VSSetShader(vertexShader.Get(), nullptr, 0);
		handles.context->PSSetShader(pixelShader.Get(), nullptr, 0);
	}

	void ReleasePipelineHandles(PipelineHandles toRelease)
	{
		toRelease.depthStencil->Release();
		toRelease.targetView->Release();
		toRelease.context->Release();
	}


public:
	~Renderer()
	{
		// ComPtr will auto release so nothing to do here yet 
	}
};
