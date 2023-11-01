import { CLICKED } from '../actions/actionTypes';

const clickedReducer = (state = '' , action: { type: string, clicked: number}) => {
    switch (action.type) {
        case CLICKED: return action.clicked;
        default: return state;
    }
};

export { clickedReducer };
