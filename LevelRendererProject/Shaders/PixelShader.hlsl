#pragma pack_matrix(row_major)
// an ultra simple hlsl pixel shader
// TODO: Part 3A 
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

// TODO: Part 4B 
struct VERTEX_OUT
{
    float4 projected_position : SV_Position;
    float3 posW : WORLD;
    float3 normW : NORMAL;
};

cbuffer Data_for_IDs : register(b2)
{
    float4 transforms;
};


float4 main(VERTEX_OUT from_VertexShder) : SV_TARGET
{
    float3 result;
    float3 indirectLight;
    float directLightEnergy;
    
    directLightEnergy = saturate(dot(normalize(-_lightDirection.xyz), normalize(from_VertexShder.normW)));
    indirectLight = _lightAmbient * _material[int(transforms.y)].Kd;
    
    float3 viewDirection;
    
    viewDirection = normalize(_cameraPosition - from_VertexShder.posW);
    
    float3 reflectVec;
    reflectVec = normalize((-_lightDirection.xyz + viewDirection));
    
    float intensity;
    intensity = max(pow(saturate(dot(normalize(from_VertexShder.normW), reflectVec)), _material[int(transforms.y)].Ns + 0.000001f), 0);
    
    float totalReflection = _lightColor.xyz * _material[int(transforms.y)].Ks * intensity;
    result = saturate(directLightEnergy + indirectLight) * _material[int(transforms.y)].Kd + totalReflection + _material[int(transforms.y)].Ke;
    
    //used to test result
    //result = float3(50.0f, 9.0f, 9.0f);
    
    return float4(result, 1.0f);
    
}