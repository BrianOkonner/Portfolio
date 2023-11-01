import { END } from './actionTypes';

export const end = (end: number) => {
    return {type: END, end};
};
