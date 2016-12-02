#version 330 core
in  vec3 fragmentColor;
in vec3  Normal;
in vec3 fragmentPos;
out vec4 color;

uniform vec3 lightColor;
uniform vec3 lightPos;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 directLight = normalize(lightPos - fragmentPos);
    float diff = max(dot(norm, directLight), 0.0);
    vec3 diffuse = diff * lightColor;
    float ambiantStrength = 0.2;
    vec3 ambiant = ambiantStrength * lightColor;
    color = vec4((ambiant + diffuse)* fragmentColor, 1.0f);
}
