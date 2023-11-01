import { CLICKED } from './actionTypes';

export const clicked = (clicked: number) => {
    return {type: CLICKED, clicked};
};
