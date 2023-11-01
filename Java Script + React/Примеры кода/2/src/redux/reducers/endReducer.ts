import { END } from '../actions/actionTypes';

const endReducer = (state = '' , action: { type: string, end: number }) => {
    switch (action.type) {
        case END: return action.end;
        default: return state;
    }
};

export { endReducer };
