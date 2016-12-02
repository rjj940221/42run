#version 330 core
in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D ourTexture;
uniform bool isTexture;

void main()
{
    //if (isTexture)
    //{
        color = texture(ourTexture, TexCoord);
        //color = vec4 (color.xyz * lightColor, 1.0);
    //}
    //else
      //  color = vec4 (ourColor /* lightColor*/, 1.0);
}