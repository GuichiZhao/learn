attribute vec4 a_position;
uniform mat4 u_matrix;
attribute vec2 a_texcoord;
varying vec2 v_texcoord;
attribute vec4 a_color;
varying vec4 v_color;
uniform vec3 u_reverseLightDirection;
uniform mat4 u_model;
uniform mat4 u_modelInvertAndTranspose;
attribute vec3 a_normal;
varying vec3 v_normal;
uniform vec3  u_lightPosition;
varying vec3 v_surfaceToLight;

void main() {
  gl_Position = u_matrix * a_position;
  v_texcoord = a_texcoord;
  v_normal = normalize(mat3(u_modelInvertAndTranspose) * a_normal);
  vec3 surfacePosition = (u_model * a_position).xyz;
  v_surfaceToLight = u_lightPosition - surfacePosition;
  // v_color = vec4(0, 1, 0, 1);
  v_color = a_color;
}