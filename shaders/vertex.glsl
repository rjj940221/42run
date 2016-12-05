 #version 330 core
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 3) in vec3 vertexColor;
layout(location = 1) in vec3 normal;
out vec3 fragmentColor;
out vec3 Normal;
out vec3 fragmentPos;
uniform mat4 MVP;
uniform mat4 model;

void main(){

     gl_Position =  MVP * vec4(vertexPosition_modelspace,1);
     fragmentColor = vertexColor;
     fragmentPos = vec3(model * vec4(vertexPosition_modelspace, 1.0));
     Normal = normal;
}