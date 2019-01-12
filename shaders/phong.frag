#version 130

const int MAX_LIGHTS = 2;

in vec3 position_eye, normal_eye;
in vec2 st;

uniform sampler2D rgb_sampler;
uniform sampler2D spec_sampler;
uniform mat4 view;

//LIGHTS UNIFORM
uniform vec3 light_pos[MAX_LIGHTS];
uniform vec3 light_spec[MAX_LIGHTS];
uniform vec3 light_diff[MAX_LIGHTS];
uniform vec3 light_amb[MAX_LIGHTS];

uniform vec3 light_ks[MAX_LIGHTS];
uniform vec3 light_kd[MAX_LIGHTS];
uniform vec3 light_ka[MAX_LIGHTS];

uniform float light_pow[MAX_LIGHTS];

//WORLD
vec3 Wlight_position_world  = vec3 (100.0, 100.0, 100.0);
vec3 WLs = vec3 (1.0, 1.0, 0.7); // white specular colour
vec3 WLd = vec3 (0.9, 0.9, 0.9); // dull white diffuse light colour
vec3 WLa = vec3 (0.0, 0.0, 0.0); // grey ambient colour
  
// surface reflectance
vec3 WKs = vec3 (0.7, 0.7, 0.7); // fully reflect specular light
vec3 WKd = vec3 (1.0, 1.0, 1.0); // diffuse surface reflectance
vec3 WKa = vec3 (1.0, 1.0, 1.0); // fully reflect ambient light

// fixed point light properties
float specular_exponent = 10.0; // specular 'power'

out vec4 fragment_colour; // final colour of surface
void main () {

	//WORLD
	vec3 light_pos_eye = vec3(view * vec4 (Wlight_position_world, 1.0));
	vec3 dist_light_eye = normalize(light_pos_eye - position_eye);
	vec3 dir_light_eye = normalize (dist_light_eye);

	// (1) ambient intensity
	vec3 Ia = WLa * WKa;

	// (2) diffuse intensity
	vec3 Id = WLd * WKd * max(dot(dir_light_eye, normal_eye), 0.0f);

	// (3) specular intensity 
	vec3 surf_view_eye = normalize (-position_eye);
    vec3 Is = WLs * WKs * pow( max( dot(reflect(-dist_light_eye, normal_eye), surf_view_eye), 0.0f), specular_exponent);
	// raise light position to eye space


	//OTHER LIGHTS
	for(int i = 0; i < MAX_LIGHTS; ++i)
	{
		vec3 light_position_world  = light_pos[i];
		vec3 Ls = light_spec[i]; // white specular colour
		vec3 Ld = light_diff[i]; // dull white diffuse light colour
		vec3 La = light_amb[i]; // grey ambient colour
		
		// surface reflectance
		vec3 Ks = light_ks[i]; // fully reflect specular light
		vec3 Kd = light_kd[i]; // diffuse surface reflectance
		vec3 Ka = light_ka[i]; // fully reflect ambient light
	
		light_pos_eye = vec3(view * vec4 (light_position_world, 1.0));
		dist_light_eye = normalize(light_pos_eye - position_eye);
		dir_light_eye = normalize (dist_light_eye);
		surf_view_eye = normalize (-position_eye);


		// (1) ambient intensity
		Ia += La * Ka;

		// (2) diffuse intensity
		Id += Ld * Kd * max(dot(dir_light_eye, normal_eye), 0.0f);

		// (3) specular intensity 

		Is += Ls * Ks * pow( max( dot(reflect(-dist_light_eye, normal_eye), surf_view_eye), 0.0f), light_pow[i]);

	}

	// final colour
	vec4 texel = texture (rgb_sampler, st);
	vec4 spectexel = texture (spec_sampler, st);
	fragment_colour = vec4 (Is*(spectexel.xyz) + (Id + Ia)*texel.xyz, 1.0);
	//fragment_colour = spectexel;
}
