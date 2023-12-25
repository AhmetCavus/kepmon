import addon from 'bindings'
import { exit } from 'process';
const pointerService = addon('pointerService')

const name = process.argv[2]
console.log(pointerService.sayHello(name))
exit()