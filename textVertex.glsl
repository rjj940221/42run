#version 330 core
layout(location = 0) in vec4 vertex;
out vec2 textPos;

uniform mat4 Pro;

void main(){
  gl_Position = Pro * vec4(vertex.xy,0.0, 1.0);
  textPos = vertex.zw;
}