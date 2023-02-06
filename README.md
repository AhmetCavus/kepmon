# Kepmon

Kepmon is a [napi module](https://www.npmjs.com/package/node-addon-api) providing pointer access and control.

In the earliest version only the Windows platfrom is currently supported!

## Getting Started

### Installation

`npm i kepmon`

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

Feel free to make any suggestions or creating pull requests in order to provide a multi-platform support or further extensions.

## License

See the [LICENSE](./LICENSE) file for licensing information.
