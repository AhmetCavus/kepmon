import addon from 'bindings'
import { exit } from 'process';
import * as readlineLib from 'readline'
const pointerService = addon('pointerService')

var input =  "" 

const readline = readlineLib.createInterface({
    input: process.stdin,
    output: process.stdout
  });

const pointerLoop = () => {
    setTimeout(() => {
        if (input.length > 0) return  
        const position = pointerService.getPointerPosition()
        const boundary = pointerService.getPointerBoundary()
        const newXPos = boundary.xLimit < position.x + 50 ? 0 : position.x + 50  
        pointerService.setPointerPosition(newXPos, position.y)
        pointerLoop()
    }, 3000)
}

pointerLoop()

readline.question('Enter any key to stop\n', _ => {
    input = "end"
    exit()
})