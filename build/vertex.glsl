 #version 330 core
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texCoord;
layout(location = 3) in vec3 vertexColor;


out vec3 fragmentColor;
out vec3 Normal;
out vec3 fragmentPos;
out vec2 TexCoord;

uniform mat4 MVP;
uniform mat4 model;

void main(){

     gl_Position =  MVP * vec4(vertexPosition_modelspace,1);
     fragmentColor = vertexColor;
     fragmentPos = vec3(model * vec4(vertexPosition_modelspace, 1.0));
     Normal = mat3(transpose(inverse(model)))*normal;
     TexCoord = texCoord;
}