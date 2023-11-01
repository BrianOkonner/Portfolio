import React from 'react';
import './Cells.scss';
import { Cell } from '../Cell/Cell';
import { useSelector } from 'react-redux';

export const Cells: React.FC = (): JSX.Element => {
    const cell = useSelector<any,any>(state => state.start);
    const isLoading = useSelector<any, any>(state => state.isLoading);

    const cells = [[<Cell key='cell0' hidden={cell === 0 ? '' : 'hidden'} number={0}/>,<Cell key='cell1' hidden={cell === 1 ? '' : 'hidden'} number={1}/>,<Cell key='cell2' hidden={cell === 2 ? '' : 'hidden'} number={2}/>],
                  [<Cell key='cell10' hidden={cell === 10 ? '' : 'hidden'} number={10}/>,<Cell key='cell11' hidden={cell === 11 ? '' : 'hidden'} number={11}/>,<Cell key='cell12' hidden={cell === 12 ? '' : 'hidden'} number={12}/>],
                  [<Cell key='cell20' hidden={cell === 20 ? '' : 'hidden'} number={20}/>,<Cell key='cell21' hidden={cell === 21 ? '' : 'hidden'} number={21}/>,<Cell key='cell22' hidden={cell === 22 ? '' : 'hidden'} number={22}/>]];

    return (
        <>
            <div className='cells'>
                 {cells.map(item => item.map(cell => cell))}
            </div>
            <div className={isLoading !== 1 ? 'wait hidden' : 'wait'}>Подождите все морковки!</div>
        </>
    );
}
