export interface PointerPos {
    x: number
    y: number
}

export interface PointerBoundary {
    xLimit: number
    yLimit: number
}

export interface PointerService {
    getPointerPosition: () => PointerPos
    getPointerBoundary: () => PointerBoundary
    setPointerPosition: (x: number, y: number) => void
    setPointerInput: (inputType: TypeOfInput) => void
}

export enum TypeOfInput {
    MOUSE_L_CLICK = 1,
    MOUSE_L_DOUBLE_CLICK = 2,
    MOUSE_R_CLICK = 3,
    MOUSE_M_CLICK = 4,
}