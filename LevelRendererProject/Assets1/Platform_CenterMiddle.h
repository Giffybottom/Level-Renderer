// "Platform_CenterMiddle.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "Platform_CenterMiddle.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _Platform_CenterMiddle_version_
const char Platform_CenterMiddle_version[4] = { '0','1','9','d' };
#define _Platform_CenterMiddle_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _Platform_CenterMiddle_vertexcount_
const unsigned Platform_CenterMiddle_vertexcount = 48;
#define _Platform_CenterMiddle_vertexcount_
#endif
#ifndef _Platform_CenterMiddle_indexcount_
const unsigned Platform_CenterMiddle_indexcount = 108;
#define _Platform_CenterMiddle_indexcount_
#endif
#ifndef _Platform_CenterMiddle_materialcount_
const unsigned Platform_CenterMiddle_materialcount = 1; // can be used for batched draws
#define _Platform_CenterMiddle_materialcount_
#endif
#ifndef _Platform_CenterMiddle_meshcount_
const unsigned Platform_CenterMiddle_meshcount = 1;
#define _Platform_CenterMiddle_meshcount_
#endif
/************************************************/
/*  This section contains the raw data to load  */
/************************************************/
#ifndef __OBJ_VEC3__
typedef struct _OBJ_VEC3_
{
	float x,y,z; // 3D Coordinate.
}OBJ_VEC3;
#define __OBJ_VEC3__
#endif
#ifndef __OBJ_VERT__
typedef struct _OBJ_VERT_
{
	OBJ_VEC3 pos; // Left-handed +Z forward coordinate w not provided, assumed to be 1.
	OBJ_VEC3 uvw; // D3D/Vulkan style top left 0,0 coordinate.
	OBJ_VEC3 nrm; // Provided direct from obj file, may or may not be normalized.
}OBJ_VERT;
#define __OBJ_VERT__
#endif
#ifndef _Platform_CenterMiddle_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT Platform_CenterMiddle_vertices[48] =
{
	{	{ -0.506900f, 0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.999999f, 0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.999999f, -0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.014996f, 0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.506900f, -0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.999999f, 0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ -0.506900f, 0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ -0.506900f, -0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ -0.014996f, 0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ -0.014996f, -0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.999999f, -0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, 1.000000f }	},
	{	{ 0.999999f, 0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, 1.000000f }	},
	{	{ 0.476907f, 0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, 1.000000f }	},
	{	{ 0.476907f, -0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, 1.000000f }	},
	{	{ 0.476907f, -0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.476907f, 0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.999999f, 0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.999999f, -0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, 0.000000f }	},
	{	{ 0.999999f, -0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, 0.000000f }	},
	{	{ 0.999999f, 0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, 0.000000f }	},
	{	{ 0.476907f, 0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.014996f, 0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.014996f, 0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.014996f, -0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -1.000000f, 0.000000f }	},
	{	{ -0.014996f, -0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -1.000000f, 0.000000f }	},
	{	{ 0.476907f, -0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -1.000000f, 0.000000f }	},
	{	{ -0.999999f, 0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, -0.000000f, 0.000000f }	},
	{	{ -0.999999f, -0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, -0.000000f, 0.000000f }	},
	{	{ -0.999999f, -0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, -0.000000f, 0.000000f }	},
	{	{ -0.506900f, 0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.506900f, 0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.999999f, 0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.476907f, 0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.999999f, 0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.476907f, -0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -1.000000f, 0.000000f }	},
	{	{ 0.999999f, -0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -1.000000f, 0.000000f }	},
	{	{ -0.506900f, -0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -1.000000f, 0.000000f }	},
	{	{ -0.506900f, -0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -1.000000f, 0.000000f }	},
	{	{ -0.999999f, -0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -1.000000f, 0.000000f }	},
	{	{ 0.999999f, 0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.014996f, -0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.999999f, -0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.999999f, -0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.999999f, 0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 1.000000f, -0.000000f, 0.000000f }	},
	{	{ -0.999999f, 0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -1.000000f, -0.000000f, 0.000000f }	},
	{	{ -0.999999f, 0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.999999f, -0.999998f, 1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -1.000000f, 0.000000f }	},
	{	{ -0.999999f, -0.999998f, -1.562632f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -1.000000f, 0.000000f }	},
};
#define _Platform_CenterMiddle_vertices_
#endif
#ifndef _Platform_CenterMiddle_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int Platform_CenterMiddle_indices[108] =
{
	 0, 1, 2,
	 3, 0, 4,
	 5, 6, 7,
	 6, 8, 9,
	 10, 11, 12,
	 13, 12, 3,
	 14, 15, 16,
	 9, 8, 15,
	 17, 18, 19,
	 20, 21, 22,
	 23, 24, 25,
	 26, 27, 28,
	 29, 30, 31,
	 29, 22, 21,
	 20, 32, 33,
	 34, 25, 35,
	 24, 23, 36,
	 37, 36, 38,
	 9, 15, 14,
	 20, 33, 39,
	 0, 2, 4,
	 3, 4, 40,
	 5, 7, 41,
	 6, 9, 7,
	 10, 12, 13,
	 13, 3, 40,
	 14, 16, 42,
	 17, 19, 43,
	 20, 22, 32,
	 23, 25, 34,
	 26, 28, 44,
	 29, 31, 45,
	 29, 21, 30,
	 34, 35, 46,
	 24, 36, 37,
	 37, 38, 47,
};
#define _Platform_CenterMiddle_indices_
#endif
// Part of an OBJ_MATERIAL, the struct is 16 byte aligned so it is GPU register friendly.
#ifndef __OBJ_ATTRIBUTES__
typedef struct _OBJ_ATTRIBUTES_
{
	OBJ_VEC3    Kd; // diffuse reflectivity
	float	    d; // dissolve (transparency) 
	OBJ_VEC3    Ks; // specular reflectivity
	float       Ns; // specular exponent
	OBJ_VEC3    Ka; // ambient reflectivity
	float       sharpness; // local reflection map sharpness
	OBJ_VEC3    Tf; // transmission filter
	float       Ni; // optical density (index of refraction)
	OBJ_VEC3    Ke; // emissive reflectivity
	unsigned    illum; // illumination model
}OBJ_ATTRIBUTES;
#define __OBJ_ATTRIBUTES__
#endif
// This structure also has been made GPU register friendly so it can be transfered directly if desired.
// Note: Total struct size will vary depenedening on CPU processor architecture (string pointers).
#ifndef __OBJ_MATERIAL__
typedef struct _OBJ_MATERIAL_
{
	// The following items are typically used in a pixel/fragment shader, they are packed for GPU registers.
	OBJ_ATTRIBUTES attrib; // Surface shading characteristics & illumination model
	// All items below this line are not needed on the GPU and are generally only used during load time.
	const char* name; // the name of this material
	// If the model's materials contain any specific texture data it will be located below.
	const char* map_Kd; // diffuse texture
	const char* map_Ks; // specular texture
	const char* map_Ka; // ambient texture
	const char* map_Ke; // emissive texture
	const char* map_Ns; // specular exponent texture
	const char* map_d; // transparency texture
	const char* disp; // roughness map (displacement)
	const char* decal; // decal texture (lerps texture & material colors)
	const char* bump; // normal/bumpmap texture
	void* padding[2]; // 16 byte alignment on 32bit or 64bit
}OBJ_MATERIAL;
#define __OBJ_MATERIAL__
#endif
#ifndef _Platform_CenterMiddle_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL Platform_CenterMiddle_materials[1] =
{
	{
		{{ 0.293787f, 0.165832f, 0.071064f },
		1.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		96.078453f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.000000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"LightBrown.004",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
	},
};
#define _Platform_CenterMiddle_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _Platform_CenterMiddle_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int Platform_CenterMiddle_batches[1][2] =
{
	{ 108, 0 },
};
#define _Platform_CenterMiddle_batches_
#endif
#ifndef __OBJ_MESH__
typedef struct _OBJ_MESH_
{
	const char* name;
	unsigned    indexCount;
	unsigned    indexOffset;
	unsigned    materialIndex;
}OBJ_MESH;
#define __OBJ_MESH__
#endif
#ifndef _Platform_CenterMiddle_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH Platform_CenterMiddle_meshes[1] =
{
	{
		"Platform_CenterMiddle.004_LightBrown.004",
		108,
		0,
		0,
	},
};
#define _Platform_CenterMiddle_meshes_
#endif
