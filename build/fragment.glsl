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

uniform sampler2D ourTexture;
uniform bool isTexture;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

uniform int test;

void main()
{
    float ambiantStrength = 0.2;
    float specularStrength = 0.5f;
    vec3 ambiant = ambiantStrength * lightColor;

    vec3 norm = normalize(Normal);
    vec3 directLight = normalize(lightPos - fragmentPos);
    float diff = max(dot(norm, directLight), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 viewDir = normalize(viewPos - fragmentPos);
    vec3 reflectDir = reflect(-directLight, norm);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

vec3 ncol;
    ncol = vec3(test,test,test);
color = vec4((ambiant + diffuse + specular) * ncol, 1.0f);
/*    if (isTexture)
{
//        vec3 tcolor = vec3(texture(ourTexture, TexCoord));
  //      color = vec4((ambiant + diffuse + specular) * tcolor, 1.0f);
  }
    //else
    //color = vec4((ambiant + diffuse + specular) * fragmentColor, 1.0f);*/
}
