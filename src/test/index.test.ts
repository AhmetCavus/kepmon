import { getPointerPosition, getPointerBoundary, setPointerPosition } from '../../index';

const position = getPointerPosition();
console.log('Current Pointer Position:', position);

const boundary = getPointerBoundary();
console.log('Pointer Boundary:', boundary);

const newXPos = boundary.xLimit < position.x + 50 ? 0 : position.x + 50;
setPointerPosition(newXPos, position.y);

const updatedPosition = getPointerPosition();
console.log('Updated Pointer Position:', updatedPosition);
