#version 130

const int MAX_LIGHTS = 2;

in vec3 vertex_position;
in vec3 vertex_normal;
in vec2 texture_coord;

//LIGHTS UNIFORM
uniform vec3 light_pos[MAX_LIGHTS];
uniform vec3 light_spec[MAX_LIGHTS];
uniform vec3 light_diff[MAX_LIGHTS];
uniform vec3 light_amb[MAX_LIGHTS];

uniform vec3 light_ks[MAX_LIGHTS];
uniform vec3 light_kd[MAX_LIGHTS];
uniform vec3 light_ka[MAX_LIGHTS];
uniform float light_pow[MAX_LIGHTS];


uniform mat4 proj, view, model;
out vec3 position_eye, normal_eye;
out vec2 st;


void main(){

	position_eye = vec3 (view* model* vec4 (vertex_position, 1.0));
	normal_eye = vec3 (view* model* vec4 (vertex_normal, 0.0));
	st = texture_coord;
	gl_Position = proj * vec4 (position_eye, 1.0);
}
