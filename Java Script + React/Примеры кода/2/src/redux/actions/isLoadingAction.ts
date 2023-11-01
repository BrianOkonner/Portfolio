import { IS_LOADING } from './actionTypes';

export const isLoading = (isLoading: number) => {
    return {type: IS_LOADING, isLoading};
};
