#version 100

precision mediump float;
varying vec3 ourColor;

void main()
{
    gl_FragColor = vec4(ourColor, 1.0);
};