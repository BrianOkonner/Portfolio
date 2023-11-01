import { START } from '../actions/actionTypes';

const startReducer = (state = '' , action: { type: string, start: number }) => {
    switch (action.type) {
        case START: return action.start;
        default: return state;
    }
};

export { startReducer };
