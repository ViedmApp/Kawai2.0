#version 130

in vec3 normal;
in vec2 st;
in vec3 light;
out vec4 frag_colour;
uniform sampler2D basic_texture;
uniform int tulio;

void main() {
    vec2 n_st = st + vec2(tulio*0.001f,0.0f);
	vec4 texel = texture (basic_texture, n_st);
    float l = clamp( dot(normalize(normal), normalize(light)), 0, 1 ); 
	//frag_colour = 2*texel*l;
    frag_colour = texel;
    //frag_colour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
