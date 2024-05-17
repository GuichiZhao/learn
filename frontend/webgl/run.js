
const esbuild = require('esbuild')
async function run() {
  let ctx = await esbuild.context({
    entryPoints: ['./main.js'],
    bundle: true,
    sourcemap:true,
    outfile: 'out.js',
  })
  await ctx.watch()
  let { host, port } = await ctx.serve({
    servedir: '.',
  })
  console.log(`Serving at http://${host}:${port}`)
}
run()

