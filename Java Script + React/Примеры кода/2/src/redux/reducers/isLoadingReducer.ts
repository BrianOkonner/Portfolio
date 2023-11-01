import { IS_LOADING } from '../actions/actionTypes';

const isLoadingReducer = (state = '' , action: { type: string, isLoading: boolean }) => {
    switch (action.type) {
        case IS_LOADING: return action.isLoading;
        default: return state;
    }
};

export { isLoadingReducer };
