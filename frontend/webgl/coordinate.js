import * as vec4 from "./gl-matrix/vec4.js";
import * as d3 from '../node_modules/d3-selection/src/index.js'
function Point(x, y, z = 0, w = 1) {
  return new Float32Array([x, y, z, w]);
}
const createSetColor = ({ alpha = 1, defaultColor = [0, 0, 0] } = {}) => {
  return (color) => {
    let _color
    if (Array.isArray(color)) {
      _color = color
      if (color.length === 3) {
        _color = [...color, alpha]
      }
    } else {
      _color = [...defaultColor, alpha]
    }

    return `rgba(${_color.join(',')})`
  };
}
const setColor = createSetColor()
const setColorAlpha = createSetColor({ alpha: 0.1 })
const svgs = {}

let length = 100
export function createAxesConfigs({ x, y, z }) {
  const shapes = [];
  const createBase = (config, position) => {
    const { axis, plane, color = [0, 0, 0] } = config || {};
    if (axis) {
      const from = [0, 0, 0]
      const to = [0, 0, 0]
      to[position] = length
      console.log(color)
      shapes.push({ points: [from, to], color: setColor(color) })
    }
    if (plane) {
      const points = [[length, length], [length, -length],
      [-length, -length], [-length, length]]
      points.forEach(p => {
        p.splice(position, 0, 0)
      })
      shapes.push({
        points,
        color: setColorAlpha(color)
      })
    }
  }
  if (x) {
    createBase(x, 0)
  }
  if (y) {
    createBase(y, 1)
  }
  if (z) {
    createBase(z, 2)
  }
  return shapes
}
const all = createAxesConfigs({
  x: {
    axis: true,
    plane: true,
    color: [255, 0, 0]
  },
  y: {
    axis: true,
    plane: true,
    color: [0, 255, 0]
  },
  z: {
    axis: true,
    plane: true,
    color: [0, 0, 255]
  }
})
console.log(all)



export function drawCoordinate({ id = '', glViewport, viewProjection, container, shapes = all }) {
  const [x, y, width, height] = glViewport.map(x => x / devicePixelRatio)
  const glClipToSvg = new Float32Array([
    width / 2, 0, 0, 0,
    0, -height / 2, 0, 0,
    0, 0, 1, 0,
    width / 2, height / 2, 0, 1,
  ])
  const worldToSvg = (point) => {
    point = Point(...point)
    let result = new Float32Array(4)
    vec4.transformMat4(result, point, viewProjection)
    const [x, y, z, w] = result
    result = [x / w, y / w, z / w, 1]
    vec4.transformMat4(result, result, glClipToSvg)
    return result
  }

  if (!svgs[id]) {
    svgs[id] = d3.select(container).append('svg')
      .attr('width', width)
      .attr('height', height)
      .attr('style', `position: absolute;left: ${x};top: 0;`)
      .attr('viewBox', `0 0 ${width} ${height}`)
  }

  const svg = svgs[id]
  const groups = svg.selectAll('g')
    .data(shapes)
    .join('g')
    .attr('class', config => config.points.length === 2 ? 'axis' : 'plane')
  groups.filter('.axis')
    .selectAll('line')
    .data((config) => {
      const points = config.points.map(point => {
        return worldToSvg(point)
      })
      return [{
        color: config.color,
        x1: points[0][0],
        y1: points[0][1],
        x2: points[1][0],
        y2: points[1][1]
      }]
    })
    .join('line')
    .attr('x1', c => c.x1).attr('y1', c => c.y1)
    .attr('x2', c => c.x2).attr('y2', c => c.y2)
    .attr('stroke', c => c.color).attr('stroke-width', 2)
  groups.filter('.plane')
    .selectAll('polygon')
    .data((config) => {
      const points = config.points.map(worldToSvg)
      return [{
        points: `${points[0][0]},${points[0][1]} ${points[1][0]},${points[1][1]} ${points[2][0]},${points[2][1]} ${points[3][0]},${points[3][1]} `,
        fill: config.color,
      }]
    })
    .join('polygon')
    .attr('points', p => p.points)
    .attr('fill', p => p.fill)
}