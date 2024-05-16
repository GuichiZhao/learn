export function loadShader(gl, shaderType, shaderSource, opt_errorCallback) {
  const errFn = opt_errorCallback || console.error;
  // Create the shader object
  const shader = gl.createShader(shaderType);

  // Load the shader source
  gl.shaderSource(shader, shaderSource);

  // Compile the shader
  gl.compileShader(shader);

  // Check the compile status
  const compiled = gl.getShaderParameter(shader, gl.COMPILE_STATUS);
  if (!compiled) {
    // Something went wrong during compilation; get the error
    const lastError = gl.getShaderInfoLog(shader);
    errFn(
      "*** Error compiling shader '" +
        shader +
        "':" +
        lastError +
        `\n` +
        shaderSource
          .split("\n")
          .map((l, i) => `${i + 1}: ${l}`)
          .join("\n")
    );
    gl.deleteShader(shader);
    return null;
  }

  return shader;
}

export function createProgram(
  gl,
  shaders,
  opt_attribs,
  opt_locations,
  opt_errorCallback
) {
  const errFn = opt_errorCallback || console.error;
  const program = gl.createProgram();
  shaders.forEach(function (shader) {
    gl.attachShader(program, shader);
  });
  if (opt_attribs) {
    opt_attribs.forEach(function (attrib, ndx) {
      gl.bindAttribLocation(
        program,
        opt_locations ? opt_locations[ndx] : ndx,
        attrib
      );
    });
  }
  gl.linkProgram(program);

  // Check the link status
  const linked = gl.getProgramParameter(program, gl.LINK_STATUS);
  if (!linked) {
    // something went wrong with the link
    const lastError = gl.getProgramInfoLog(program);
    errFn("Error in program linking:" + lastError);

    gl.deleteProgram(program);
    return null;
  }
  return program;
}

/**
 * Creates setter functions for all uniforms of a shader
 * program.
 *
 * @see {@link module:webgl-utils.setUniforms}
 *
 * @param {WebGLProgram} program the program to create setters for.
 * @returns {Object.<string, function>} an object with a setter by name for each uniform
 * @memberOf module:webgl-utils
 */
export function createUniformSetters(gl, program) {
  let textureUnit = 0;

  /**
   * Creates a setter for a uniform of the given program with it's
   * location embedded in the setter.
   * @param {WebGLProgram} program
   * @param {WebGLUniformInfo} uniformInfo
   * @returns {function} the created setter.
   */
  function createUniformSetter(program, uniformInfo) {
    // debugger
    const location = gl.getUniformLocation(program, uniformInfo.name);
    // console.log(uniformInfo, location);
    const type = uniformInfo.type;
    // Check if this uniform is an array
    const isArray =
      uniformInfo.size > 1 && uniformInfo.name.substr(-3) === "[0]";
    if (type === gl.FLOAT && isArray) {
      return function (v) {
        gl.uniform1fv(location, v);
      };
    }
    if (type === gl.FLOAT) {
      return function (v) {
        gl.uniform1f(location, v);
      };
    }
    if (type === gl.FLOAT_VEC2) {
      return function (v) {
        gl.uniform2fv(location, v);
      };
    }
    if (type === gl.FLOAT_VEC3) {
      return function (v) {
        gl.uniform3fv(location, v);
      };
    }
    if (type === gl.FLOAT_VEC4) {
      return function (v) {
        gl.uniform4fv(location, v);
      };
    }
    if (type === gl.INT && isArray) {
      return function (v) {
        gl.uniform1iv(location, v);
      };
    }
    if (type === gl.INT) {
      return function (v) {
        gl.uniform1i(location, v);
      };
    }
    if (type === gl.INT_VEC2) {
      return function (v) {
        gl.uniform2iv(location, v);
      };
    }
    if (type === gl.INT_VEC3) {
      return function (v) {
        gl.uniform3iv(location, v);
      };
    }
    if (type === gl.INT_VEC4) {
      return function (v) {
        gl.uniform4iv(location, v);
      };
    }
    if (type === gl.BOOL) {
      return function (v) {
        gl.uniform1iv(location, v);
      };
    }
    if (type === gl.BOOL_VEC2) {
      return function (v) {
        gl.uniform2iv(location, v);
      };
    }
    if (type === gl.BOOL_VEC3) {
      return function (v) {
        gl.uniform3iv(location, v);
      };
    }
    if (type === gl.BOOL_VEC4) {
      return function (v) {
        gl.uniform4iv(location, v);
      };
    }
    if (type === gl.FLOAT_MAT2) {
      return function (v) {
        gl.uniformMatrix2fv(location, false, v);
      };
    }
    if (type === gl.FLOAT_MAT3) {
      return function (v) {
        gl.uniformMatrix3fv(location, false, v);
      };
    }
    if (type === gl.FLOAT_MAT4) {
      return function (v) {
        gl.uniformMatrix4fv(location, false, v);
      };
    }
    if ((type === gl.SAMPLER_2D || type === gl.SAMPLER_CUBE) && isArray) {
      const units = [];
      for (let ii = 0; ii < info.size; ++ii) {
        units.push(textureUnit++);
      }
      return (function (bindPoint, units) {
        return function (textures) {
          gl.uniform1iv(location, units);
          textures.forEach(function (texture, index) {
            gl.activeTexture(gl.TEXTURE0 + units[index]);
            gl.bindTexture(bindPoint, texture);
          });
        };
      })(getBindPointForSamplerType(gl, type), units);
    }
    if (type === gl.SAMPLER_2D || type === gl.SAMPLER_CUBE) {
      return (function (bindPoint, unit) {
        return function (texture) {
          gl.uniform1i(location, unit);
          gl.activeTexture(gl.TEXTURE0 + unit);
          gl.bindTexture(bindPoint, texture);
        };
      })(getBindPointForSamplerType(gl, type), textureUnit++);
    }
    throw "unknown type: 0x" + type.toString(16);
    // we should never get here.
  }

  const uniformSetters = {};
  const numUniforms = gl.getProgramParameter(program, gl.ACTIVE_UNIFORMS);

  for (let ii = 0; ii < numUniforms; ++ii) {
    const uniformInfo = gl.getActiveUniform(program, ii);

    if (!uniformInfo) {
      break;
    }
    let name = uniformInfo.name;
    // remove the array suffix.
    if (name.substr(-3) === "[0]") {
      name = name.substr(0, name.length - 3);
    }
    const setter = createUniformSetter(program, uniformInfo);
    uniformSetters[name] = setter;
  }
  return uniformSetters;
}
export function setUniforms(setters, ...values) {
  setters = setters.uniformSetters || setters;
  for (const uniforms of values) {
    Object.keys(uniforms).forEach(function (name) {
      const setter = setters[name];
      if (setter) {
        setter(uniforms[name]);
      }
    });
  }
}
function getBindPointForSamplerType(gl, type) {
  if (type === gl.SAMPLER_2D) return gl.TEXTURE_2D; // eslint-disable-line
  if (type === gl.SAMPLER_CUBE) return gl.TEXTURE_CUBE_MAP; // eslint-disable-line
  return undefined;
}
/**
 *
 * @param {WebGLRenderingContext} gl
 * @param {*} program
 * @returns
 */
export function createAttributeSetters(gl, program) {
  const attribSetters = {};

  function createAttribSetter(index) {
    return function (b) {
      if (b.value) {
        gl.disableVertexAttribArray(index);
        switch (b.value.length) {
          case 4:
            gl.vertexAttrib4fv(index, b.value);
            break;
          case 3:
            gl.vertexAttrib3fv(index, b.value);
            break;
          case 2:
            gl.vertexAttrib2fv(index, b.value);
            break;
          case 1:
            gl.vertexAttrib1fv(index, b.value);
            break;
          default:
            throw new Error(
              "the length of a float constant value must be between 1 and 4!"
            );
        }
      } else {
        gl.enableVertexAttribArray(index);
        gl.bindBuffer(gl.ARRAY_BUFFER, b.buffer);
        gl.vertexAttribPointer(
          index,
          b.numComponents || b.size,
          b.type || gl.FLOAT,
          b.normalize || false,
          b.stride || 0,
          b.offset || 0
        );
      }
    };
  }

  const numAttribs = gl.getProgramParameter(program, gl.ACTIVE_ATTRIBUTES);
  for (let ii = 0; ii < numAttribs; ++ii) {
    const attribInfo = gl.getActiveAttrib(program, ii);
    if (!attribInfo) {
      break;
    }

    const index = gl.getAttribLocation(program, attribInfo.name);
    attribSetters[attribInfo.name] = createAttribSetter(index, attribInfo);
  }

  return attribSetters;
}
export function setAttributes(setters, attribs) {
  setters = setters.attribSetters || setters;
  Object.keys(attribs).forEach(function (name) {
    const setter = setters[name];
    if (setter) {
      setter(attribs[name]);
    }
  });
}

export function createBufferFromTypedArray(gl, array, type, drawType) {
  type = type || gl.ARRAY_BUFFER;
  const buffer = gl.createBuffer();
  gl.bindBuffer(type, buffer);
  gl.bufferData(type, array, drawType || gl.STATIC_DRAW);
  return buffer;
}
function getGLTypeForTypedArray(gl, typedArray) {
  if (typedArray instanceof Int8Array) {
    return gl.BYTE;
  }
  if (typedArray instanceof Uint8Array) {
    return gl.UNSIGNED_BYTE;
  }
  if (typedArray instanceof Int16Array) {
    return gl.SHORT;
  }
  if (typedArray instanceof Uint16Array) {
    return gl.UNSIGNED_SHORT;
  }
  if (typedArray instanceof Int32Array) {
    return gl.INT;
  }
  if (typedArray instanceof Uint32Array) {
    return gl.UNSIGNED_INT;
  }
  if (typedArray instanceof Float32Array) {
    return gl.FLOAT;
  }
  throw "unsupported typed array type";
}
/**
 *
 * @param {WebGLRenderingContext} gl
 * @param {[string,string]} shaderPaths
 */
export const createProgramInfo = async (gl, shaderPaths) => {
  const shaders = shaderPaths.map(async (path, i) => {
    const text = await fetch(path).then((x) => x.text());
    return loadShader(
      gl,
      i === 0 ? gl.VERTEX_SHADER : gl.FRAGMENT_SHADER,
      text
    );
  });
  const program = createProgram(gl, await Promise.all(shaders));
  const uniformSetters = createUniformSetters(gl, program);
  const attribSetters = createAttributeSetters(gl, program);
  return { program, uniformSetters, attribSetters };
};

/**
 * Calls `gl.drawElements` or `gl.drawArrays`, whichever is appropriate
 *
 * normally you'd call `gl.drawElements` or `gl.drawArrays` yourself
 * but calling this means if you switch from indexed data to non-indexed
 * data you don't have to remember to update your draw call.
 *
 * @param {WebGLRenderingContext} gl A WebGLRenderingContext
 * @param {module:webgl-utils.BufferInfo} bufferInfo as returned from createBufferInfoFromArrays
 * @param {enum} [primitiveType] eg (gl.TRIANGLES, gl.LINES, gl.POINTS, gl.TRIANGLE_STRIP, ...)
 * @param {number} [count] An optional count. Defaults to bufferInfo.numElements
 * @param {number} [offset] An optional offset. Defaults to 0.
 * @memberOf module:webgl-utils
 */
export function drawBufferInfo(gl, bufferInfo, primitiveType, count, offset) {
  const indices = bufferInfo.indices;
  primitiveType = primitiveType === undefined ? gl.TRIANGLES : primitiveType;
  const numElements = count === undefined ? bufferInfo.numElements : count;
  offset = offset === undefined ? 0 : offset;
  if (indices) {
    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, bufferInfo.indices);
    gl.drawElements(primitiveType, numElements, gl.UNSIGNED_SHORT, offset);
  } else {
    gl.drawArrays(primitiveType, offset, numElements);
  }
}
export function setBuffersAndAttributes(gl, setters, buffers) {
  setAttributes(setters, buffers.attribs);
  if (buffers.indices) {
    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, buffers.indices);
  }
}
export function createAugmentedTypedArray(
  numComponents,
  numElements,
  opt_type
) {
  const Type = opt_type || Float32Array;
  return augmentTypedArray(
    new Type(numComponents * numElements),
    numComponents
  );
}
function augmentTypedArray(typedArray, numComponents) {
  let cursor = 0;
  typedArray.push = function () {
    for (let ii = 0; ii < arguments.length; ++ii) {
      const value = arguments[ii];
      if (
        value instanceof Array ||
        (value.buffer && value.buffer instanceof ArrayBuffer)
      ) {
        for (let jj = 0; jj < value.length; ++jj) {
          typedArray[cursor++] = value[jj];
        }
      } else {
        typedArray[cursor++] = value;
      }
    }
  };
  typedArray.reset = function (opt_index) {
    cursor = opt_index || 0;
  };
  typedArray.numComponents = numComponents;
  Object.defineProperty(typedArray, "numElements", {
    get: function () {
      return (this.length / this.numComponents) | 0;
    },
  });
  return typedArray;
}
export function createBufferInfoFromArrays(gl, arrays, opt_mapping) {
  const bufferInfo = {
    attribs: createAttribsFromArrays(gl, arrays, opt_mapping),
  };
  let indices = arrays.indices;
  if (indices) {
    indices = makeTypedArray(indices, "indices");
    bufferInfo.indices = createBufferFromTypedArray(
      gl,
      indices,
      gl.ELEMENT_ARRAY_BUFFER
    );
    bufferInfo.numElements = indices.length;
  } else {
    bufferInfo.numElements = getNumElementsFromNonIndexedArrays(arrays);
  }

  return bufferInfo;
}
function createAttribsFromArrays(gl, arrays, opt_mapping) {
  const mapping = opt_mapping || createMapping(arrays);
  const attribs = {};
  Object.keys(mapping).forEach(function (attribName) {
    const bufferName = mapping[attribName];
    const origArray = arrays[bufferName];
    if (origArray.value) {
      attribs[attribName] = {
        value: origArray.value,
      };
    } else {
      const array = makeTypedArray(origArray, bufferName);
      attribs[attribName] = {
        buffer: createBufferFromTypedArray(gl, array),
        numComponents:
          origArray.numComponents ||
          array.numComponents ||
          guessNumComponentsFromName(bufferName),
        type: getGLTypeForTypedArray(gl, array),
        normalize: getNormalizationForTypedArray(array),
      };
    }
  });
  return attribs;
}
function createMapping(obj) {
  const mapping = {};
  Object.keys(obj)
    .filter(allButIndices)
    .forEach(function (key) {
      mapping["a_" + key] = key;
    });
  return mapping;
}
function allButIndices(name) {
  return name !== "indices";
}

function makeTypedArray(array, name) {
  if (isArrayBuffer(array)) {
    return array;
  }

  if (array.data && isArrayBuffer(array.data)) {
    return array.data;
  }

  if (Array.isArray(array)) {
    array = {
      data: array,
    };
  }

  if (!array.numComponents) {
    array.numComponents = guessNumComponentsFromName(name, array.length);
  }

  let type = array.type;
  if (!type) {
    if (name === "indices") {
      type = Uint16Array;
    }
  }
  const typedArray = createAugmentedTypedArray(
    array.numComponents,
    (array.data.length / array.numComponents) | 0,
    type
  );
  typedArray.push(array.data);
  return typedArray;
}
function isArrayBuffer(a) {
  return a.buffer && a.buffer instanceof ArrayBuffer;
}
function getNormalizationForTypedArray(typedArray) {
  if (typedArray instanceof Int8Array) {
    return true;
  } // eslint-disable-line
  if (typedArray instanceof Uint8Array) {
    return true;
  } // eslint-disable-line
  return false;
}
function guessNumComponentsFromName(name, length) {
  let numComponents;
  if (name.indexOf("coord") >= 0) {
    numComponents = 2;
  } else if (name.indexOf("color") >= 0) {
    numComponents = 4;
  } else {
    numComponents = 3; // position, normals, indices ...
  }

  if (length % numComponents > 0) {
    throw "can not guess numComponents. You should specify it.";
  }

  return numComponents;
}
