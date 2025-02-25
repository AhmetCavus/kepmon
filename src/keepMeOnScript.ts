import { exit } from 'process';
import * as readlineLib from 'readline';
import { getPointerPosition, getPointerBoundary, setPointerPosition } from './index';

var input = "";

const readline = readlineLib.createInterface({
  input: process.stdin,
  output: process.stdout
});

const pointerLoop = () => {
  setTimeout(() => {
    if (input.length > 0) return;
    const position = getPointerPosition();
    const boundary = getPointerBoundary();
    const newXPos = boundary.xLimit < position.x + 50 ? 0 : position.x + 50;
    setPointerPosition(newXPos, position.y);
    console.log('Pointer position updated successfully.');
    pointerLoop();
  }, 3000);
};

pointerLoop();

readline.question('Enter any key to stop\n', _ => {
  input = "end";
  exit();
});