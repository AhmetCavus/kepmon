import bindings from 'bindings';

const pointerService = bindings('pointerService');

export function getPointerPosition() {
  return pointerService.getPointerPosition();
}

export function getPointerBoundary() {
  return pointerService.getPointerBoundary();
}

export function setPointerPosition(x: number, y: number) {
  pointerService.setPointerPosition(x, y);
}