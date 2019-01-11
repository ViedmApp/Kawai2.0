#version 130

// valores de entrada, cada thread recibe uno distinto.
in vec3 vertex_position;
in vec3 vertex_normal;
in vec2 texture_coord;

// variables comunes para todos los shaders
uniform mat4 view, proj, model;
uniform int tulio;

// variables de salida, cada shader genera un valor distinto
out vec3 light;
out vec3 normal;
out vec2 st;

void main(){
    light = (view * vec4(1.0f, 0.0f, 1.0f, 0.0f)).xyz;
	st = texture_coord;
	normal = (view * model * vec4(vertex_normal, 0.0)).xyz;
	gl_Position = proj * view * model * vec4(vertex_position, 1.0);
}
