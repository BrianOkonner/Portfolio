import { START } from './actionTypes';

export const start = (start: number) => {
    return {type: START, start};
};
