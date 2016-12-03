#version 330 core
in  vec3 fragmentColor;
in vec3  Normal;
in vec3 fragmentPos;
in vec2 TexCoord;

out vec4 color;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float constant;
    float linear;
    float quadratic;
};

uniform sampler2D ourTexture;
uniform bool isTextured;
uniform vec3 viewPos;
uniform Material material;
//uniform Light   light;
uniform int NumLights;
uniform Light pointLights[100];

uniform int test;
vec3 calculatePointLight(Light light, vec3 norm, vec3 viewDir)
{

    float ambiantIntencity = 0.2;
    vec3 ambient = material.ambient * light.ambient * ambiantIntencity;

    vec3 directLight = normalize(light.position - fragmentPos);
    float diff = max(dot(norm, directLight), 0.0);
    vec3 diffuse = (diff * material.diffuse)* light.diffuse;

    vec3 reflectDir = reflect(-directLight, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);

    float distance    = length(light.position - fragmentPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance +
        		    light.quadratic * (distance * distance));

    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;

    return (ambient + diffuse + specular);
}
void main()
{

    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - fragmentPos);
    vec3 lightEfect = vec3(0,0,0);

    for (int i = 0; i < NumLights; i++){
            lightEfect += calculatePointLight(pointLights[i], norm, viewDir);
    }

    if (isTextured)
    {
        vec3 tcolor = vec3(texture(ourTexture, TexCoord));
        color = vec4((lightEfect) * tcolor, 1.0f);
    }
    else
        color = vec4((lightEfect) * fragmentColor, 1.0f);
}
