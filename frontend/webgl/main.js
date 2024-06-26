import * as mat4 from "./gl-matrix/mat4.js";
import { setupUI } from "./ui.js";
import {
  createProgramInfo,
  setUniforms,
  setBuffersAndAttributes,
  drawBufferInfo,
  initCanvas,
} from "./util.js";
import {
  create3DFBufferInfo, createCameraBufferInfo,
  createUnitCubeWireframeBufferInfo,
} from "./primatives.js";
import { createAxesConfigs, drawSvg } from "./drawSvg.js";
import { pointer } from "d3-selection";

main();




// const position = vec4.fromValues(10, 10, 60, 1);
// const view = mat4.lookAt(mat4.create(), [40, 40, 80], [40, 40, 10], [0, 1, 0]);
// // console.log(view);
// const afterCamera = vec4.transformMat4(vec4.create(), position, view);
// console.log(afterCamera); //-30,-30,-20,1
// const projection = mat4.perspective(mat4.create(), degToRad(60), 1, 1, 2000);
// const afterProjection = vec4.transformMat4(
//   vec4.create(),
//   afterCamera,
//   projection
// );
// console.log(afterProjection) //-51.9615249633,-51.961524963378906,18.019010543823242,20;

async function main() {
  /**
   * @type {HTMLDivElement}
   */
  const container = document.getElementById("container");
  const canvas = initCanvas(container);
  /**
   * @type {WebGLRenderingContext}
   */
  const gl = canvas.getContext("webgl");
  const sceneProgram = await createProgramInfo(gl, [
    "./shader/f-v.glsl",
    "./shader/f-f.glsl",
  ]);
  const cameraProgram = await createProgramInfo(gl, [
    "./shader/camera-v.glsl",
    "./shader/camera-f.glsl",
  ]);

  const near = 70;
  const far = 800;
  const zCenter = 0;
  const lightPosition = [100, 100, zCenter - 200]
  const width = gl.canvas.width;
  const height = gl.canvas.height;
  const offsetRadius = 200,
    cameraRadius = 600;
  const image = new Image();

  const scale = [1, -1, 1];

  const setting = {
    cameraAngle: 0,
    translationX: 0,
    translationY: 0,
    translationZ: zCenter,
    rotateX: 0,
    rotateY: 0,
    rotateZ: 0,
    // scaleX: 1,
    // scaleY: 1,
    // scaleZ: 1,
  };
  image.src = "./leaves.jpg";
  image.onload = function () {
    setupUI(document.querySelector("#ui"), setting, [
      {
        type: "slider",
        key: "cameraAngle",
        min: 0,
        max: 360,
        change: render,
      },
      {
        type: "slider",
        key: "translationX",
        change: render,
        max: width / 2,
        min: -width / 2,
      },
      {
        type: "slider",
        key: "translationY",
        change: render,
        max: height / 2,
        min: -height / 2,
      },
      {
        type: "slider",
        key: "translationZ",
        change: render,
        min: -far,
        max: far,
      },
      {
        type: "slider",
        key: "rotateX",
        change: render,
        min: 0,
        max: 360,
      },
      {
        type: "slider",
        key: "rotateY",
        change: render,
        min: 0,
        max: 360,
      },
      {
        type: "slider",
        key: "rotateZ",
        change: render,
        min: 0,
        max: 360,
      },
    ]);
    setUniforms(sceneProgram.uniformSetters, {
      u_color: [0.2, 1, 0.2, 1],
      u_textureSize: [width, height],
      u_reverseLightDirection: [1, 1, -1],
    });
    const cameraBufferInfo = createCameraBufferInfo(gl, 30);
    const fBufferInfo = create3DFBufferInfo(gl);
    const cubeBufferInfo = createUnitCubeWireframeBufferInfo(gl)

    var texture = gl.createTexture();
    gl.bindTexture(gl.TEXTURE_2D, texture);

    // Set the parameters so we can render any size image.
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);

    // Create a texture.
    var texture = gl.createTexture();
    gl.bindTexture(gl.TEXTURE_2D, texture);

    // Set the parameters so we can render any size image.
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);

    // Upload the image into the texture.
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, image);

    render(gl);

    function render() {
      const halfWidth = width / 2;
      const leftViewport = [0, 0, halfWidth, height]
      gl.viewport(...leftViewport);

      gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
      gl.enable(gl.DEPTH_TEST);
      gl.blendFunc(gl.SRC_ALPHA, gl.ONE_MINUS_SRC_ALPHA);

      const cameraProjection = mat4.perspective(
        mat4.create(),
        degToRad(60),
        halfWidth / height,
        near,
        far
      );
      const camaraPosition = [
        0 + cameraRadius * Math.sin(degToRad(setting.cameraAngle)),
        100,
        zCenter + cameraRadius * Math.cos(degToRad(setting.cameraAngle)),
      ];
      const cameraView = mat4.lookAt(
        mat4.create(),
        camaraPosition,
        [0, 0, zCenter],
        [0, 1, 0]
      );

      const cameraViewProjection = mat4.multiply(
        mat4.create(),
        cameraProjection,
        cameraView
      );

      const model = mat4.create();
      mat4.translate(model, model, [
        setting.translationX,
        setting.translationY,
        setting.translationZ,
      ]);
      mat4.rotateX(model, model, degToRad(setting.rotateX));
      mat4.rotateY(model, model, degToRad(setting.rotateY));
      mat4.rotateZ(model, model, degToRad(setting.rotateZ));
      mat4.scale(model, model, scale);

      drawScene(model, cameraViewProjection);
      drawSvg({ id: 'left', container, glViewport: leftViewport, viewProjection: cameraViewProjection })

      const rightViewport = [halfWidth, 0, halfWidth, height]
      gl.viewport(...rightViewport);


      const rightAspect = rightViewport[2] / rightViewport[3]
      const range = 1000
      const globalProjection = mat4.ortho(mat4.create(), -range, range, -range * rightAspect, range * rightAspect, 10000, -10000)
      const globalView = mat4.lookAt(mat4.create(),
        [1200, 1500, 1800],
        [0, 0, 0],
        [0, 1, 0]
      );
      const worldViewProjection = mat4.multiply(mat4.create(), globalProjection, globalView)
      drawSvg({
        id: 'right', container, glViewport: rightViewport,
        viewProjection: worldViewProjection, shapes: createAxesConfigs({
          x: { axis: true },
          y: { axis: true, },
          z: { axis: true, plane: true, color: [255, 212, 34] }
        })
      })
      // const 
      drawSvg({
        id: 'light', container, glViewport: rightViewport,
        viewProjection: worldViewProjection, shapes: [{
          color: [255, 0, 0, 1],
          points: [
            [100, 100, zCenter - 200, ],
            [100 + 10, 100 + 10, zCenter - 200 + 10],
            [100 - 10, 100 + 20, zCenter - 200 - 30]
          ]
        }]
      })
      const cameraModel = mat4.invert(mat4.create(), cameraView)
      drawCamera(
        cameraModel,
        worldViewProjection
      );
      drawFrustum(
        mat4.invert(mat4.create(), cameraViewProjection),
        worldViewProjection)
      drawScene(model, worldViewProjection);


    }
    function drawCamera(model, viewProjection) {
      gl.useProgram(cameraProgram.program);
      setBuffersAndAttributes(gl, cameraProgram, cameraBufferInfo);
      setUniforms(cameraProgram.uniformSetters, {
        u_matrix: mat4.multiply(mat4.create(), viewProjection, model), u_color: [0, 0, 0, 1]
      });

      drawBufferInfo(gl, cameraBufferInfo, gl.LINES);
    }

    function drawFrustum(model, viewProjection) {
      gl.useProgram(cameraProgram.program)
      setBuffersAndAttributes(gl, cameraProgram, cubeBufferInfo);

      setUniforms(cameraProgram.uniformSetters, {
        u_matrix: mat4.multiply(mat4.create(), viewProjection, model),
        u_color: [120, 0, 110, 1]
      });
      drawBufferInfo(gl, cubeBufferInfo, gl.LINES);

    }

    function drawScene(model, viewProjection) {
      setBuffersAndAttributes(gl, sceneProgram, fBufferInfo);
      gl.useProgram(sceneProgram.program);
      const n = 5;
      for (let i = 0; i < n; i++) {
        const u_matrix = mat4.create();
        const angle = (i * Math.PI * 2) / n;
        const x = Math.cos(angle) * offsetRadius;
        const z = Math.sin(angle) * offsetRadius;
        const u_model = mat4.fromTranslation(mat4.create(), [x, 0, z]);
        mat4.multiply(u_model, u_model, model);
        mat4.multiply(u_matrix, viewProjection, u_model);

        const u_modelInvertAndTranspose = mat4.create();
        mat4.invert(u_modelInvertAndTranspose, u_model);
        mat4.transpose(u_modelInvertAndTranspose, u_modelInvertAndTranspose);

        setUniforms(sceneProgram.uniformSetters, {
          u_matrix,
          u_model,
          u_modelInvertAndTranspose,
          u_lightPosition: lightPosition,
        });
        drawBufferInfo(gl, fBufferInfo);
      }
    }
  };
}
function degToRad(d) {
  return (d * Math.PI) / 180;
}
