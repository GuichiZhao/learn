import * as webglUtils from "./util.js";
export const create3DFBufferInfo = createBufferInfoFunc(create3DFVertices);

export function createCameraBufferInfo(gl, scale = 1) {
  // first let's add a cube. It goes from 1 to 3
  // because cameras look down -Z so we want
  // the camera to start at Z = 0. We'll put a
  // a cone in front of this cube opening
  // toward -Z
  const positions = [
    -1, -1, 1, // cube vertices
    1, -1, 1,
    -1, 1, 1,
    1, 1, 1,
    -1, -1, 3,
    1, -1, 3,
    -1, 1, 3,
    1, 1, 3,
    0, 0, 1, // cone tip
  ];
  const indices = [
    0,
    1,
    1,
    3,
    3,
    2,
    2,
    0, // cube indices
    4,
    5,
    5,
    7,
    7,
    6,
    6,
    4,
    0,
    4,
    1,
    5,
    3,
    7,
    2,
    6,
  ];
  // add cone segments
  const numSegments = 6;
  const coneBaseIndex = positions.length / 3;
  const coneTipIndex = coneBaseIndex - 1;
  for (let i = 0; i < numSegments; ++i) {
    const u = i / numSegments;
    const angle = u * Math.PI * 2;
    const x = Math.cos(angle);
    const y = Math.sin(angle);
    positions.push(x, y, 0);
    // line from tip to edge
    indices.push(coneTipIndex, coneBaseIndex + i);
    // line from point on edge to next point on edge
    indices.push(coneBaseIndex + i, coneBaseIndex + ((i + 1) % numSegments));
  }
  positions.forEach((v, ndx) => {
    positions[ndx] *= scale;
  });
  return webglUtils.createBufferInfoFromArrays(gl, {
    position: positions,
    indices,
  });
}

function createBufferInfoFunc(fn) {
  return function (gl) {
    const arrays = fn.apply(null, Array.prototype.slice.call(arguments, 1));
    return webglUtils.createBufferInfoFromArrays(gl, arrays);
  };
}
function expandRLEData(rleData, padding) {
  padding = padding || [];
  const data = [];
  for (let ii = 0; ii < rleData.length; ii += 4) {
    const runLength = rleData[ii];
    const element = rleData.slice(ii + 1, ii + 4);
    element.push.apply(element, padding);
    for (let jj = 0; jj < runLength; ++jj) {
      data.push.apply(data, element);
    }
  }
  return data;
}
function create3DFVertices() {
  const positions = [
    // left column front
    0, 0, 0, 0, 150, 0, 30, 0, 0, 0, 150, 0, 30, 150, 0, 30, 0, 0,

    // top rung front
    30, 0, 0, 30, 30, 0, 100, 0, 0, 30, 30, 0, 100, 30, 0, 100, 0, 0,

    // middle rung front
    30, 60, 0, 30, 90, 0, 67, 60, 0, 30, 90, 0, 67, 90, 0, 67, 60, 0,

    // left column back
    0, 0, 30, 30, 0, 30, 0, 150, 30, 0, 150, 30, 30, 0, 30, 30, 150, 30,

    // top rung back
    30, 0, 30, 100, 0, 30, 30, 30, 30, 30, 30, 30, 100, 0, 30, 100, 30, 30,

    // middle rung back
    30, 60, 30, 67, 60, 30, 30, 90, 30, 30, 90, 30, 67, 60, 30, 67, 90, 30,

    // top
    0, 0, 0, 100, 0, 0, 100, 0, 30, 0, 0, 0, 100, 0, 30, 0, 0, 30,

    // top rung right
    100, 0, 0, 100, 30, 0, 100, 30, 30, 100, 0, 0, 100, 30, 30, 100, 0, 30,

    // under top rung
    30, 30, 0, 30, 30, 30, 100, 30, 30, 30, 30, 0, 100, 30, 30, 100, 30, 0,

    // between top rung and middle
    30, 30, 0, 30, 60, 30, 30, 30, 30, 30, 30, 0, 30, 60, 0, 30, 60, 30,

    // top of middle rung
    30, 60, 0, 67, 60, 30, 30, 60, 30, 30, 60, 0, 67, 60, 0, 67, 60, 30,

    // right of middle rung
    67, 60, 0, 67, 90, 30, 67, 60, 30, 67, 60, 0, 67, 90, 0, 67, 90, 30,

    // bottom of middle rung.
    30, 90, 0, 30, 90, 30, 67, 90, 30, 30, 90, 0, 67, 90, 30, 67, 90, 0,

    // right of bottom
    30, 90, 0, 30, 150, 30, 30, 90, 30, 30, 90, 0, 30, 150, 0, 30, 150, 30,

    // bottom
    0, 150, 0, 0, 150, 30, 30, 150, 30, 0, 150, 0, 30, 150, 30, 30, 150, 0,

    // left side
    0, 0, 0, 0, 0, 30, 0, 150, 30, 0, 0, 0, 0, 150, 30, 0, 150, 0,
  ];

  const texcoords = [
    // left column front
    0.22, 0.19, 0.22, 0.79, 0.34, 0.19, 0.22, 0.79, 0.34, 0.79, 0.34, 0.19,

    // top rung front
    0.34, 0.19, 0.34, 0.31, 0.62, 0.19, 0.34, 0.31, 0.62, 0.31, 0.62, 0.19,

    // middle rung front
    0.34, 0.43, 0.34, 0.55, 0.49, 0.43, 0.34, 0.55, 0.49, 0.55, 0.49, 0.43,

    // left column back
    0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1,

    // top rung back
    0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1,

    // middle rung back
    0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1,

    // top
    0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1,

    // top rung right
    0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1,

    // under top rung
    0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0,

    // between top rung and middle
    0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1,

    // top of middle rung
    0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1,

    // right of middle rung
    0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1,

    // bottom of middle rung.
    0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0,

    // right of bottom
    0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1,

    // bottom
    0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0,

    // left side
    0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0,
  ];

  const normals = expandRLEData([
    // left column front
    // top rung front
    // middle rung front
    18, 0, 0, 1,

    // left column back
    // top rung back
    // middle rung back
    18, 0, 0, -1,

    // top
    6, 0, 1, 0,

    // top rung right
    6, 1, 0, 0,

    // under top rung
    6, 0, -1, 0,

    // between top rung and middle
    6, 1, 0, 0,

    // top of middle rung
    6, 0, 1, 0,

    // right of middle rung
    6, 1, 0, 0,

    // bottom of middle rung.
    6, 0, -1, 0,

    // right of bottom
    6, 1, 0, 0,

    // bottom
    6, 0, -1, 0,

    // left side
    6, -1, 0, 0,
  ]);

  const colors = expandRLEData(
    [
      // left column front
      // top rung front
      // middle rung front
      18, 200, 70, 120,

      // left column back
      // top rung back
      // middle rung back
      18, 80, 70, 200,

      // top
      6, 70, 200, 210,

      // top rung right
      6, 200, 200, 70,

      // under top rung
      6, 210, 100, 70,

      // between top rung and middle
      6, 210, 160, 70,

      // top of middle rung
      6, 70, 180, 210,

      // right of middle rung
      6, 100, 70, 210,

      // bottom of middle rung.
      6, 76, 210, 100,

      // right of bottom
      6, 140, 210, 80,

      // bottom
      6, 90, 130, 110,

      // left side
      6, 160, 160, 220,
    ],
    [255]
  );

  const numVerts = positions.length / 3;

  const arrays = {
    position: webglUtils.createAugmentedTypedArray(3, numVerts),
    texcoord: webglUtils.createAugmentedTypedArray(2, numVerts),
    normal: webglUtils.createAugmentedTypedArray(3, numVerts),
    color: webglUtils.createAugmentedTypedArray(4, numVerts, Uint8Array),
    indices: webglUtils.createAugmentedTypedArray(3, numVerts / 3, Uint16Array),
  };

  arrays.position.push(positions);
  arrays.texcoord.push(texcoords);
  arrays.normal.push(normals);
  arrays.color.push(colors);

  for (let ii = 0; ii < numVerts; ++ii) {
    arrays.indices.push(ii);
  }

  return arrays;
}
