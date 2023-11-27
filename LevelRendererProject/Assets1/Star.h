// "Star.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "Star.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _Star_version_
const char Star_version[4] = { '0','1','9','d' };
#define _Star_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _Star_vertexcount_
const unsigned Star_vertexcount = 160;
#define _Star_vertexcount_
#endif
#ifndef _Star_indexcount_
const unsigned Star_indexcount = 270;
#define _Star_indexcount_
#endif
#ifndef _Star_materialcount_
const unsigned Star_materialcount = 1; // can be used for batched draws
#define _Star_materialcount_
#endif
#ifndef _Star_meshcount_
const unsigned Star_meshcount = 1;
#define _Star_meshcount_
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
#ifndef _Star_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT Star_vertices[160] =
{
	{	{ 0.258743f, -0.084071f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.294100f, 0.095600f, 0.951000f }	},
	{	{ 0.159912f, 0.220100f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.294100f, 0.095600f, 0.951000f }	},
	{	{ 0.000000f, 0.000001f, 0.168345f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.294100f, 0.095600f, 0.951000f }	},
	{	{ 0.258743f, -0.084071f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.188000f, -0.258800f, 0.947500f }	},
	{	{ 0.000000f, -0.272059f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.188000f, -0.258800f, 0.947500f }	},
	{	{ 0.230880f, -0.372705f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.188000f, -0.258800f, 0.947500f }	},
	{	{ -0.159912f, 0.220100f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.319800f, 0.947500f }	},
	{	{ 0.159912f, 0.220100f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.319800f, 0.947500f }	},
	{	{ 0.032284f, 0.437233f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.319800f, 0.947500f }	},
	{	{ -0.159912f, 0.220100f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.304200f, 0.098800f, 0.947500f }	},
	{	{ -0.405857f, 0.165817f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.304200f, 0.098800f, 0.947500f }	},
	{	{ -0.425810f, 0.104408f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.304200f, 0.098800f, 0.947500f }	},
	{	{ -0.258743f, -0.084071f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.188000f, -0.258800f, 0.947500f }	},
	{	{ -0.283118f, -0.334752f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.188000f, -0.258800f, 0.947500f }	},
	{	{ -0.230880f, -0.372705f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.188000f, -0.258800f, 0.947500f }	},
	{	{ 0.159912f, 0.220100f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.304200f, 0.098800f, 0.947500f }	},
	{	{ 0.258743f, -0.084071f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.304200f, 0.098800f, 0.947500f }	},
	{	{ 0.425809f, 0.104408f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.304200f, 0.098800f, 0.947500f }	},
	{	{ 0.032284f, 0.437233f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.032285f, 0.437233f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.032285f, 0.437233f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.283118f, -0.334752f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.587800f, -0.809000f, 0.000000f }	},
	{	{ -0.283118f, -0.334752f, -0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.587800f, -0.809000f, 0.000000f }	},
	{	{ -0.230880f, -0.372705f, -0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.587800f, -0.809000f, 0.000000f }	},
	{	{ -0.405857f, 0.165817f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.951100f, 0.309000f, 0.000000f }	},
	{	{ -0.405857f, 0.165817f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.951100f, 0.309000f, 0.000000f }	},
	{	{ -0.425810f, 0.104408f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.951100f, 0.309000f, 0.000000f }	},
	{	{ -0.258743f, -0.084071f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.181800f, -0.250200f, 0.951000f }	},
	{	{ 0.000000f, -0.272059f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.181800f, -0.250200f, 0.951000f }	},
	{	{ 0.000000f, 0.000001f, 0.168345f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.181800f, -0.250200f, 0.951000f }	},
	{	{ 0.000000f, -0.272059f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.181800f, -0.250200f, 0.951000f }	},
	{	{ 0.258743f, -0.084071f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.181800f, -0.250200f, 0.951000f }	},
	{	{ 0.000000f, 0.000001f, 0.168345f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.181800f, -0.250200f, 0.951000f }	},
	{	{ -0.258743f, -0.084071f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.294100f, 0.095600f, 0.951000f }	},
	{	{ 0.000000f, 0.000001f, 0.168345f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.294100f, 0.095600f, 0.951000f }	},
	{	{ -0.159912f, 0.220100f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.294100f, 0.095600f, 0.951000f }	},
	{	{ -0.159912f, 0.220100f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.309200f, 0.951000f }	},
	{	{ 0.000000f, 0.000001f, 0.168345f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.309200f, 0.951000f }	},
	{	{ 0.159912f, 0.220100f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.309200f, 0.951000f }	},
	{	{ -0.405857f, 0.165817f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.215500f, 0.976500f, 0.000000f }	},
	{	{ -0.159912f, 0.220100f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.215500f, 0.976500f, 0.000000f }	},
	{	{ -0.159912f, 0.220100f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.215500f, 0.976500f, 0.000000f }	},
	{	{ 0.405856f, 0.165817f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.951100f, 0.309000f, 0.000000f }	},
	{	{ 0.405856f, 0.165817f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.951100f, 0.309000f, 0.000000f }	},
	{	{ 0.425809f, 0.104408f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.951100f, 0.309000f, 0.000000f }	},
	{	{ 0.283118f, -0.334752f, -0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.587800f, -0.809000f, 0.000000f }	},
	{	{ 0.283118f, -0.334752f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.587800f, -0.809000f, 0.000000f }	},
	{	{ 0.230880f, -0.372705f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.587800f, -0.809000f, 0.000000f }	},
	{	{ 0.000000f, -0.272059f, -0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.399600f, -0.916700f, 0.000000f }	},
	{	{ 0.000000f, -0.272059f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.399600f, -0.916700f, 0.000000f }	},
	{	{ -0.230880f, -0.372705f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.399600f, -0.916700f, 0.000000f }	},
	{	{ 0.032284f, 0.437233f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.862100f, 0.506700f, 0.000000f }	},
	{	{ 0.159912f, 0.220100f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.862100f, 0.506700f, 0.000000f }	},
	{	{ 0.159912f, 0.220100f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.862100f, 0.506700f, 0.000000f }	},
	{	{ 0.425809f, 0.104408f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.748300f, -0.663300f, 0.000000f }	},
	{	{ 0.258743f, -0.084071f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.748300f, -0.663300f, 0.000000f }	},
	{	{ 0.258743f, -0.084071f, -0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.748300f, -0.663300f, 0.000000f }	},
	{	{ 0.258743f, -0.084071f, -0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.995300f, 0.096800f, 0.000000f }	},
	{	{ 0.258743f, -0.084071f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.995300f, 0.096800f, 0.000000f }	},
	{	{ 0.283118f, -0.334752f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.995300f, 0.096800f, 0.000000f }	},
	{	{ 0.230880f, -0.372705f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.399600f, -0.916700f, 0.000000f }	},
	{	{ 0.000000f, -0.272059f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.399600f, -0.916700f, 0.000000f }	},
	{	{ 0.000000f, -0.272059f, -0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.399600f, -0.916700f, 0.000000f }	},
	{	{ -0.159912f, 0.220100f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.862100f, 0.506700f, 0.000000f }	},
	{	{ -0.159912f, 0.220100f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.862100f, 0.506700f, 0.000000f }	},
	{	{ -0.032285f, 0.437233f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.862100f, 0.506700f, 0.000000f }	},
	{	{ -0.258743f, -0.084071f, -0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.748300f, -0.663300f, 0.000000f }	},
	{	{ -0.258743f, -0.084071f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.748300f, -0.663300f, 0.000000f }	},
	{	{ -0.425810f, 0.104408f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.748300f, -0.663300f, 0.000000f }	},
	{	{ -0.283118f, -0.334752f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.995300f, 0.096800f, 0.000000f }	},
	{	{ -0.258743f, -0.084071f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.995300f, 0.096800f, 0.000000f }	},
	{	{ -0.258743f, -0.084071f, -0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.995300f, 0.096800f, 0.000000f }	},
	{	{ 0.159912f, 0.220100f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.215500f, 0.976500f, 0.000000f }	},
	{	{ 0.159912f, 0.220100f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.215500f, 0.976500f, 0.000000f }	},
	{	{ 0.405856f, 0.165817f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.215500f, 0.976500f, 0.000000f }	},
	{	{ 0.258743f, -0.084071f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.294100f, 0.095600f, -0.951000f }	},
	{	{ 0.000000f, 0.000001f, -0.168345f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.294100f, 0.095600f, -0.951000f }	},
	{	{ 0.159912f, 0.220100f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.294100f, 0.095600f, -0.951000f }	},
	{	{ 0.230880f, -0.372705f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.188000f, -0.258800f, -0.947500f }	},
	{	{ 0.000000f, -0.272059f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.188000f, -0.258800f, -0.947500f }	},
	{	{ 0.258743f, -0.084071f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.188000f, -0.258800f, -0.947500f }	},
	{	{ 0.032285f, 0.437233f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.319800f, -0.947500f }	},
	{	{ 0.159912f, 0.220100f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.319800f, -0.947500f }	},
	{	{ -0.159912f, 0.220100f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.319800f, -0.947500f }	},
	{	{ -0.159912f, 0.220100f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.304200f, 0.098800f, -0.947500f }	},
	{	{ -0.258743f, -0.084071f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.304200f, 0.098800f, -0.947500f }	},
	{	{ -0.425810f, 0.104408f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.304200f, 0.098800f, -0.947500f }	},
	{	{ -0.258743f, -0.084071f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.188000f, -0.258800f, -0.947500f }	},
	{	{ 0.000000f, -0.272059f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.188000f, -0.258800f, -0.947500f }	},
	{	{ -0.230880f, -0.372705f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.188000f, -0.258800f, -0.947500f }	},
	{	{ 0.425809f, 0.104408f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.304200f, 0.098800f, -0.947500f }	},
	{	{ 0.258743f, -0.084071f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.304200f, 0.098800f, -0.947500f }	},
	{	{ 0.159912f, 0.220100f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.304200f, 0.098800f, -0.947500f }	},
	{	{ 0.032285f, 0.437233f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.283118f, -0.334752f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.587800f, -0.809000f, 0.000000f }	},
	{	{ -0.405857f, 0.165817f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.951100f, 0.309000f, 0.000000f }	},
	{	{ -0.258743f, -0.084071f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.181800f, -0.250200f, -0.951000f }	},
	{	{ 0.000000f, 0.000001f, -0.168345f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.181800f, -0.250200f, -0.951000f }	},
	{	{ 0.000000f, -0.272059f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.181800f, -0.250200f, -0.951000f }	},
	{	{ 0.000000f, -0.272059f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.181800f, -0.250200f, -0.951000f }	},
	{	{ 0.000000f, 0.000001f, -0.168345f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.181800f, -0.250200f, -0.951000f }	},
	{	{ 0.258743f, -0.084071f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.181800f, -0.250200f, -0.951000f }	},
	{	{ -0.258743f, -0.084071f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.294100f, 0.095600f, -0.951000f }	},
	{	{ -0.159912f, 0.220100f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.294100f, 0.095600f, -0.951000f }	},
	{	{ 0.000000f, 0.000001f, -0.168345f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.294100f, 0.095600f, -0.951000f }	},
	{	{ -0.159912f, 0.220100f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.309200f, -0.951000f }	},
	{	{ 0.159912f, 0.220100f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.309200f, -0.951000f }	},
	{	{ 0.000000f, 0.000001f, -0.168345f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.309200f, -0.951000f }	},
	{	{ -0.405857f, 0.165817f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.215500f, 0.976500f, 0.000000f }	},
	{	{ -0.405857f, 0.165817f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.215500f, 0.976500f, 0.000000f }	},
	{	{ 0.425809f, 0.104408f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.951100f, 0.309000f, 0.000000f }	},
	{	{ 0.405856f, 0.165817f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.951100f, 0.309000f, 0.000000f }	},
	{	{ 0.230880f, -0.372705f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.587800f, -0.809000f, 0.000000f }	},
	{	{ 0.283118f, -0.334752f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.587800f, -0.809000f, 0.000000f }	},
	{	{ -0.230880f, -0.372705f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.399600f, -0.916700f, 0.000000f }	},
	{	{ 0.000000f, -0.272059f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.399600f, -0.916700f, 0.000000f }	},
	{	{ 0.032285f, 0.437233f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.862100f, 0.506700f, 0.000000f }	},
	{	{ 0.032285f, 0.437233f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.862100f, 0.506700f, 0.000000f }	},
	{	{ 0.425809f, 0.104408f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.748300f, -0.663300f, 0.000000f }	},
	{	{ 0.425809f, 0.104408f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.748300f, -0.663300f, 0.000000f }	},
	{	{ 0.283118f, -0.334752f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.995300f, 0.096800f, 0.000000f }	},
	{	{ 0.258743f, -0.084071f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.995300f, 0.096800f, 0.000000f }	},
	{	{ 0.230880f, -0.372705f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.399600f, -0.916700f, 0.000000f }	},
	{	{ 0.230880f, -0.372705f, -0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.399600f, -0.916700f, 0.000000f }	},
	{	{ -0.032285f, 0.437233f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.862100f, 0.506700f, 0.000000f }	},
	{	{ -0.159912f, 0.220100f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.862100f, 0.506700f, 0.000000f }	},
	{	{ -0.425810f, 0.104408f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.748300f, -0.663300f, 0.000000f }	},
	{	{ -0.258743f, -0.084071f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.748300f, -0.663300f, 0.000000f }	},
	{	{ -0.283118f, -0.334752f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.995300f, 0.096800f, 0.000000f }	},
	{	{ -0.283118f, -0.334752f, -0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.995300f, 0.096800f, 0.000000f }	},
	{	{ 0.405856f, 0.165817f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.215500f, 0.976500f, 0.000000f }	},
	{	{ 0.159912f, 0.220100f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.215500f, 0.976500f, 0.000000f }	},
	{	{ 0.283118f, -0.334752f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.188000f, -0.258800f, 0.947500f }	},
	{	{ -0.032285f, 0.437233f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.319800f, 0.947500f }	},
	{	{ -0.258743f, -0.084071f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.304200f, 0.098800f, 0.947500f }	},
	{	{ 0.000000f, -0.272059f, 0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.188000f, -0.258800f, 0.947500f }	},
	{	{ 0.405856f, 0.165817f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.304200f, 0.098800f, 0.947500f }	},
	{	{ -0.032285f, 0.437233f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.230880f, -0.372705f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.587800f, -0.809000f, 0.000000f }	},
	{	{ -0.425810f, 0.104408f, 0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.951100f, 0.309000f, 0.000000f }	},
	{	{ 0.425809f, 0.104408f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.951100f, 0.309000f, 0.000000f }	},
	{	{ 0.230880f, -0.372705f, -0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.587800f, -0.809000f, 0.000000f }	},
	{	{ -0.230880f, -0.372705f, -0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.399600f, -0.916700f, 0.000000f }	},
	{	{ 0.283118f, -0.334752f, -0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.995300f, 0.096800f, 0.000000f }	},
	{	{ -0.032285f, 0.437233f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.862100f, 0.506700f, 0.000000f }	},
	{	{ -0.425810f, 0.104408f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.748300f, -0.663300f, 0.000000f }	},
	{	{ 0.405856f, 0.165817f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.215500f, 0.976500f, 0.000000f }	},
	{	{ 0.283118f, -0.334752f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.188000f, -0.258800f, -0.947500f }	},
	{	{ -0.032285f, 0.437233f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.319800f, -0.947500f }	},
	{	{ -0.405857f, 0.165817f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.304200f, 0.098800f, -0.947500f }	},
	{	{ -0.283118f, -0.334752f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.188000f, -0.258800f, -0.947500f }	},
	{	{ 0.405856f, 0.165817f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.304200f, 0.098800f, -0.947500f }	},
	{	{ -0.032285f, 0.437233f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.230880f, -0.372705f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.587800f, -0.809000f, 0.000000f }	},
	{	{ -0.425810f, 0.104408f, -0.023483f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.951100f, 0.309000f, 0.000000f }	},
	{	{ -0.159912f, 0.220100f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.215500f, 0.976500f, 0.000000f }	},
	{	{ 0.159912f, 0.220100f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.862100f, 0.506700f, 0.000000f }	},
	{	{ 0.258743f, -0.084071f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.748300f, -0.663300f, 0.000000f }	},
	{	{ 0.000000f, -0.272059f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.399600f, -0.916700f, 0.000000f }	},
	{	{ -0.258743f, -0.084071f, -0.096780f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.995300f, 0.096800f, 0.000000f }	},
};
#define _Star_vertices_
#endif
#ifndef _Star_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int Star_indices[270] =
{
	 0, 1, 2,
	 3, 4, 5,
	 6, 7, 8,
	 9, 10, 11,
	 12, 13, 14,
	 15, 16, 17,
	 18, 19, 20,
	 21, 22, 23,
	 24, 25, 26,
	 27, 28, 29,
	 30, 31, 32,
	 33, 34, 35,
	 36, 37, 38,
	 39, 40, 41,
	 42, 43, 44,
	 45, 46, 47,
	 48, 49, 50,
	 51, 52, 53,
	 54, 55, 56,
	 57, 58, 59,
	 60, 61, 62,
	 63, 64, 65,
	 66, 67, 68,
	 69, 70, 71,
	 72, 73, 74,
	 75, 76, 77,
	 78, 79, 80,
	 81, 82, 83,
	 84, 85, 86,
	 87, 88, 89,
	 90, 91, 92,
	 20, 19, 93,
	 23, 22, 94,
	 26, 25, 95,
	 96, 97, 98,
	 99, 100, 101,
	 102, 103, 104,
	 105, 106, 107,
	 108, 109, 41,
	 110, 111, 42,
	 112, 113, 45,
	 114, 115, 48,
	 116, 117, 53,
	 118, 119, 56,
	 120, 121, 57,
	 122, 123, 62,
	 124, 125, 63,
	 126, 127, 66,
	 128, 129, 71,
	 130, 131, 72,
	 3, 5, 132,
	 6, 8, 133,
	 9, 11, 134,
	 12, 14, 135,
	 15, 17, 136,
	 18, 20, 137,
	 21, 23, 138,
	 24, 26, 139,
	 39, 41, 109,
	 42, 44, 140,
	 45, 47, 141,
	 48, 50, 142,
	 51, 53, 117,
	 54, 56, 119,
	 57, 59, 143,
	 60, 62, 123,
	 63, 65, 144,
	 66, 68, 145,
	 69, 71, 129,
	 72, 74, 146,
	 78, 80, 147,
	 81, 83, 148,
	 84, 86, 149,
	 87, 89, 150,
	 90, 92, 151,
	 20, 93, 152,
	 23, 94, 153,
	 26, 95, 154,
	 108, 41, 155,
	 110, 42, 140,
	 112, 45, 141,
	 114, 48, 142,
	 116, 53, 156,
	 118, 56, 157,
	 120, 57, 143,
	 122, 62, 158,
	 124, 63, 144,
	 126, 66, 145,
	 128, 71, 159,
	 130, 72, 146,
};
#define _Star_indices_
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
#ifndef _Star_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL Star_materials[1] =
{
	{
		{{ 0.510615f, 0.359458f, 0.042371f },
		1.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		96.078453f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.000000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"Yellow.001",
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
#define _Star_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _Star_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int Star_batches[1][2] =
{
	{ 270, 0 },
};
#define _Star_batches_
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
#ifndef _Star_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH Star_meshes[1] =
{
	{
		"Star.011_Yellow.001",
		270,
		0,
		0,
	},
};
#define _Star_meshes_
#endif
