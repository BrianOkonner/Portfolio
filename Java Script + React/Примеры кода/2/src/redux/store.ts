import { createStore, applyMiddleware, combineReducers } from 'redux';
import { composeWithDevTools } from 'redux-devtools-extension';
import thunk from 'redux-thunk';
import { startReducer, endReducer, isLoadingReducer, clickedReducer } from './reducers';

const rootReducers = combineReducers({
    start: startReducer,
    end: endReducer,
    isLoading: isLoadingReducer,
    clicked: clickedReducer
});

const store = createStore(rootReducers, composeWithDevTools(applyMiddleware(thunk)));

export default store;
