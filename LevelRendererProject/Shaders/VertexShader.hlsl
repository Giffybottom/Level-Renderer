// an ultra simple hlsl vertex shader
#pragma pack_matrix(row_major)
// TODO: Part 1F
struct VERTEX_IN
{
    float3 local_UV_position : UV_POSITION;
    float3 local_UV_Coordinate : UV_COORDINATE;
    float3 local_UV_Normals : UV_NORMALS;
};

struct VERTEX_OUT
{
    float4 projected_position : SV_Position;
    float3 posW : WORLD;
    float3 normW : NORMAL;
};

// TODO: Part 1H 
// TODO: Part 2B
cbuffer Scene_Data : register(b0)
{

    float4x4 _viewMatrix; //(float * 4)^4 bytes
    float4x4 _projectionMatrix; //(float * 4)^4 bytes
    float4 _lightDirection; //lighting info
    float4 _lightColor; //lighting info
    float4 _lightAmbient;
    float4 _cameraPosition;
};

struct OBJ_ATTRIBUTES
{
    float3 Kd; // diffuse reflectivity
    float d; // dissolve (transparency) 
    float3 Ks; // specular reflectivity
    float Ns; // specular exponent
    float3 Ka; // ambient reflectivity
    float sharpness; // local reflection map sharpness
    float3 Tf; // transmission filter
    float Ni; // optical density (index of refraction)
    float3 Ke; // emissive reflectivity
	unsigned int illum; // illumination model
};

cbuffer Mesh_data : register(b1)
{
    float4x4 _worldMatrix[200]; //world space transform
    OBJ_ATTRIBUTES _material[200]; //material information (color, reflectivity, emissiveness, ets...)
};

cbuffer Data_for_IDs : register(b2)
{
   float4 transforms;
};

VERTEX_OUT main(VERTEX_IN inputVertex, uint instanceID : SV_InstanceID)
{
    VERTEX_OUT to_rasterizer = (VERTEX_OUT) 0;
    float4 homogenous_position = float4(inputVertex.local_UV_position, 1.0f);
    homogenous_position = mul(homogenous_position, _worldMatrix[instanceID + int(transforms.x)]);
    to_rasterizer.normW = mul(inputVertex.local_UV_Normals, _worldMatrix[instanceID + int(transforms.x)]);
    to_rasterizer.posW = homogenous_position;
    homogenous_position = mul(homogenous_position, _viewMatrix);
    homogenous_position = mul(homogenous_position, _projectionMatrix);
    to_rasterizer.projected_position = homogenous_position;
    
    return to_rasterizer;
}