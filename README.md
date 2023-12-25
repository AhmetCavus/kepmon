# Kepmon

Kepmon is a [napi module](https://www.npmjs.com/package/node-addon-api) providing pointer access and control.

In the earliest version only the Windows platfrom is currently supported!

## Getting Started

### Usage

```nodejs
import kepmon from ("kepmon")

const position = kepmon.getPointerPosition()
const boundary = kepmon.getPointerBoundary()
const newXPos = boundary.xLimit < position.x + 50 ? 0 : position.x + 50  
kepmon.setPointerPosition(newXPos, position.y)

```
For more information check the [keepMeOnScript.ts](./src/keepMeOnScript.ts).

### Extending the library

First of all you've to install node-gyp.

node-gyp is a tool for building native Addon modules for Node.js, using the same infrastructure as Node itself. With node-gyp, you can compile your C/C++ code into a binary that can be loaded by Node.js and used as if it were any other native module.

#### Prerequisites
Before you can use node-gyp, you need to make sure you have the following installed:

- Node.js and npm
- Python (version 2.x)
- Visual Studio Build Tools (for Windows only) or Xcode (for MacOS only)
- The Windows SDK (for Windows only)
- Installing node-gyp

You can install node-gyp globally with the following command:

`
npm install -g node-gyp
`

Once you have node-gyp installed, you can generate the necessary code with the code below

`
node-gyp configure
node-gyp build
`

and than

`
node-gyp rebuild
`

After that you'll get the `pointerService.node` file which is used for performing the hardware executions.
So execute now 

`npm i`

in order to install required node modules. 

The [binding](node_modules/bindings/README.md) module maps the cpp code through the exposed interface -> see [PointerService](src/pointer/pointerService.ts)
and binds it to the generated `node` file located in the binary directory. 

For further instruction on how to use node-gyp and napi properly you can follow the (documentation)[https://nodejs.org/api/n-api.html] 

Feel free to make any suggestions or creating pull requests in order to provide a multi-platform support or further extensions.

## License

See the [LICENSE](./LICENSE) file for licensing information.
