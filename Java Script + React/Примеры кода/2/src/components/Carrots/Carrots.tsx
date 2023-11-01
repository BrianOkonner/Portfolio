import React, { useState, useEffect } from 'react';
import './Carrots.scss';
import { Carrot } from '../Carrot/Carrot';
import { useDispatch, useSelector } from 'react-redux';
import { randomNextMove } from '../../utils';
import { end } from '../../redux/actions/endAction';
import { isLoading } from '../../redux/actions/isLoadingAction';

export const Carrots: React.FC = (): JSX.Element => {
    const dispatch = useDispatch();
    const startPos = useSelector<any, any>(state => state.start);
    const click = useSelector<any,any>(state => state.clicked);
    const loaded = useSelector<any,any>(state => state.isLoading);

    const carrots: { key: string; hidden: string; angle: number; }[] = [];
    for (let i = 0; i < 10; i++) {
        carrots.push({
            key: `key${i}`,
            hidden: 'hidden',
            angle: 0
        })
    }

    const [cur, setCur] = useState<number>(-1);
    const [carrotsInfo, setCarrotsInfo] = useState({carrots, index: 0});

    useEffect(() => {
        if (loaded !== 2) {
            if ((startPos || startPos === 0) && cur === -1) setCur(startPos);
            if (cur !== -1 && carrotsInfo.index < 11) {
                let next = 0;
                const first = Math.trunc(cur / 10);
                const last = cur % 10;
                next += randomNextMove(first, last)
                const newCarrots = [...carrotsInfo.carrots];
                if (carrotsInfo.index !== 10) {
                    let angle;
                    switch (next) {
                        case 10:
                            angle = 90;
                            break;
                        case -1:
                            angle = 180;
                            break;
                        case -10:
                            angle = 270;
                            break;
                        default:
                            angle = 0;
                    }
                    newCarrots[carrotsInfo.index].hidden = '';
                    newCarrots[carrotsInfo.index].angle = angle;
                }
                setCarrotsInfo(prevState => ({carrots: newCarrots, index: prevState.index + 1}));
                setTimeout(() => setCur(prevState => prevState + next), 1000);
            }
            if (carrotsInfo.index === 10) {
                dispatch(end(cur));
                dispatch(isLoading(2));
            }
        }
    }, [cur, startPos]);

    useEffect(() => {
        if (click === -1) {
            setTimeout(() => {
                setCarrotsInfo({carrots, index: 0});
                setCur(-1);
            }, 3000);
        }
    }, [click])

    return (
        <div className='carrots'>
            {carrots.map((carrot, index) => <Carrot key={carrot.key} hidden={carrotsInfo.carrots[index].hidden} angle={carrotsInfo.carrots[index].angle}/>)}
        </div>
    );
}
