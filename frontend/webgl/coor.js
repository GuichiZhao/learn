import { drawBufferInfo, createBufferInfoFromArrays, createProgramInfo, setBuffersAndAttributes, setUniforms } from "./util.js";
import * as mat4 from './gl-matrix/mat4.js'
import * as vec4 from './gl-matrix/vec4.js'
const position = [
  0, 0, 0,
  7, 0, 0, // x

  0, 0, 0,
  1, 0, 0, // unit X 

  0, 0, 0,
  0, 5, 0, // y

  0, 0, 0,
  0, 1, 0, // unit Y

  0, 0, 0,
  1, 2, 0, // another unit X

  0, 0, 0,
  2, 1, 0, // another unit Y
];

const color = [
  0, 1, 0, 1,
  0, 1, 0, 1, // x

  0, 0, 1, 1,
  0, 0, 1, 1, // unit X

  1, 0, 0, 1,
  1, 0, 0, 1, // y

  0, 0, 1, 1,
  0, 0, 1, 1, // unit Y

  0, 0, 1, 1,
  0, 0, 1, 1, // another unit X

  0, 0, 1, 1,
  0, 0, 1, 1, // another unit Y
]


const indices = [
  0, 1, 2, 4, 5, 6, 7, 8, 9, 10]



const canvas = document.querySelector("#glcanvas");
canvas.width = canvas.clientWidth * devicePixelRatio;
canvas.height = canvas.clientHeight * devicePixelRatio;
/**
 * @type {WebGLRenderingContext}
 */
const gl = canvas.getContext("webgl");
const { width, height } = canvas
gl.viewport(0, 0, width, height)
const program = await createProgramInfo(gl, [
  "./shader/coordinate-v.glsl",
  "./shader/coordinate-f.glsl",
]);
const bufferInfo = createBufferInfoFromArrays(gl, { position, color, indices })
setBuffersAndAttributes(gl, program, bufferInfo);
gl.useProgram(program.program)
gl.clearColor(0, 0, 0, 0.1)
gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT)
const projection = mat4.ortho(mat4.create(), -width / 200, width / 200, -height / 200, height / 200, -100, 100)
const v = vec4.fromValues(90, 10, 0, 1)
const x = vec4.transformMat4(vec4.create(), v, projection);
console.log(x)


setUniforms(program, {
  u_matrix: projection
})


gl.lineWidth(5)
gl.drawArrays(gl.LINES, 0, 12);

// drawBufferInfo(gl, bufferInfo, gl.LINES)



