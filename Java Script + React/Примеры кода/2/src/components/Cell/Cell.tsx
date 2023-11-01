import React, { useEffect, useState } from 'react';
import './Cell.scss';
// @ts-ignore
import bunny from '../../assets/images/bunny.png';
import { useDispatch, useSelector } from 'react-redux';
import { isLoading } from '../../redux/actions/isLoadingAction';
import { start } from '../../redux/actions/startAction';
import { ThumbDown, ThumbUp } from '@mui/icons-material';
import { clicked } from '../../redux/actions/clickedAction';

interface CellProps {
    hidden: string,
    number: number
}

export const Cell: React.FC<CellProps> = (props): JSX.Element => {
    const dispatch = useDispatch();
    let started = useSelector<any, any>(state => state.start);
    const end = useSelector<any, any>(state => state.end);
    const hasEnded = useSelector<any, any>(state => state.isLoading);
    let click = useSelector<any,any>(state => state.clicked);

    const [isUpHidden, setIsUpHidden] = useState(true);
    const [isDownHidden, setIsDownHidden] = useState(true);

    const handleClick = () => {
        if (!started && started !== 0) started = -1;
        if (started !== -1 && (!hasEnded || hasEnded === 1)) {
            dispatch(isLoading(1));
        } else if (started === -1) {
            dispatch(isLoading(0));
        } else {
            dispatch(isLoading(2));
        }
        if (hasEnded === 2) {
            if (click === -2) {
                dispatch(start(props.number));
                dispatch(clicked(props.number));
                if (props.number === end) {
                    setIsUpHidden(false);
                    setTimeout(() => {
                        setIsUpHidden(true);
                        dispatch(start(-1));
                    }, 3000);
                } else {
                    setIsDownHidden(false);
                    setTimeout(() => {
                        dispatch(start(-1));
                        setIsDownHidden(true);
                    }, 3000);
                }
                dispatch(clicked(-1));
            }
        }
    }

    useEffect(() => {
        if (end === props.number) setIsUpHidden(false);
        setTimeout(() => {
            setIsUpHidden(true);
        }, 3000);
    }, [click])

    return (
        <div className='cell' onClick={handleClick}>
            <img className={hasEnded === 2 ? `bunny ${props.hidden} small` : `bunny ${props.hidden}`} src={bunny} alt='bunny' />
            <ThumbUp className={isUpHidden ? 'thumb up hidden' : 'thumb up'} fontSize='large'/>
            <ThumbDown className={isDownHidden ? 'thumb down hidden' : 'thumb down'} fontSize='large'/>
        </div>
    );
}
