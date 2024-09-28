#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

//out vec4 FragColor;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, TexCoord);
    FragColor = vec4(1.0, 0.5, 1.0, 1.0);
}
