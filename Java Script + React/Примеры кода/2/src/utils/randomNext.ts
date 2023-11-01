import { random } from './random';

const randomNext = (number: number, zero: number): number => {
    switch (zero) {
        case 0:
            switch (number) {
                case 0: return -10;
                case 1: return 1;
                case 2: return 10;
                case 3: return -1;
                default: return 0;
            }
        case 1:
            switch (number) {
                case 3: return -10;
                case 0: return 1;
                case 1: return 10;
                case 2: return -1;
                default: return 0;
            }
        case 2:
            switch (number) {
                case 2: return -10;
                case 3: return 1;
                case 0: return 10;
                case 1: return -1;
                default: return 0;
            }
        case 3:
            switch (number) {
                case 1: return -10;
                case 2: return 1;
                case 3: return 10;
                case 0: return -1;
                default: return 0;
            }
        default: return 0;
    }
}

export const randomNextMove = (first: number, last: number): number => {
    let next = 0;
    switch (first) {
        case 0:
            switch (last) {
                case 0: next += randomNext(random(0,2),1); break;
                case 1: next += randomNext(random(0,3),1); break;
                case 2: next += randomNext(random(0,2),2); break;
            }
            break;
        case 1:
            switch (last) {
                case 0: next += randomNext(random(0,3),0); break;
                case 1: next += randomNext(random(0,4),0); break;
                case 2: next += randomNext(random(0,3),2); break;
            }
            break;
        case 2:
            switch (last) {
                case 0: next += randomNext(random(0,2),0); break;
                case 1: next += randomNext(random(0,3),3); break;
                case 2: next += randomNext(random(0,2),3); break;
            }
            break;
    }
    return next;
}
