#version 100

precision mediump float;

varying vec2 TexCoord;

// Текстурные сэмплеры
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	gl_FragColor = mix(texture2D(texture1, TexCoord), texture2D(texture2, TexCoord), 0.2);
}

