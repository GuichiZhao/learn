precision mediump float;
uniform sampler2D u_image;
uniform vec2 u_textureSize;
vec2 onePixel = vec2(1.0, 1.0) / u_textureSize;

varying vec2 v_texcoord;
varying vec4 v_color;
varying vec3 v_normal;
varying vec3 v_surfaceToLight;
void main() {
    // because v_normal is a varying it's interpolated
  // so it will not be a unit vector. Normalizing it
  // will make it a unit vector again
  vec3 normal = normalize(v_normal);
  vec3 surfaceToLightDirection = normalize(v_surfaceToLight);
  float light = dot(normal, surfaceToLightDirection);
  gl_FragColor = v_color;
  gl_FragColor.rgb *= light;
  // gl_FragColor = texture2D(u_image, v_texcoord);
}