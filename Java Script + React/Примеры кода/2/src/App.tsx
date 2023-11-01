import React from 'react';
import './App.scss';
import { Carrots, Cells } from './components';
import { Button } from '@mui/material';
import './styles/buttons.scss';
import { useDispatch } from 'react-redux';
import { start } from './redux/actions/startAction';
import { random } from './utils';
import { isLoading } from './redux/actions/isLoadingAction';
import { clicked } from './redux/actions/clickedAction';
import { end } from './redux/actions/endAction';

const App: React.FC = (): JSX.Element => {
    const dispatch = useDispatch();

    const handleClick = () => {
        const sec = new Date().getSeconds() / 2;
        let number = random(0,3);
        if (sec < 20 && sec >= 10) {
            number += 10;
        }
        if (sec >= 20) {
            number += 20;
        }
        dispatch(start(number));
        dispatch(isLoading(0));
        dispatch(clicked(-2));
        dispatch(end(-1));
    }

    return (
        <div className='App'>
            <div className='title'>ЛАБИРИНТ</div>
            <Cells />
            <div className='button-wrapper'>
                <Button className='start-button' variant='contained' color='primary' onClick={handleClick}>Начать</Button>
            </div>
            <Carrots />
        </div>
    );
}

export default App;
