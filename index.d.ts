declare module 'bindings' {
  export default function(string: 'pointerService'): PointerService;
}

interface PointerPosition {
  x: number;
  y: number;
}

interface PointerBoundary {
  xLimit: number;
  yLimit: number;
}

interface PointerService {
  getPointerPosition(): PointerPosition;
  getPointerBoundary(): PointerBoundary;
  setPointerPosition(x: number, y: number): void;
}

export function getPointerPosition(): PointerPosition;
export function getPointerBoundary(): PointerBoundary;
export function setPointerPosition(x: number, y: number): void;