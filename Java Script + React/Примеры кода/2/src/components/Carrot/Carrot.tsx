import React from 'react';
import './Carrot.scss';
// @ts-ignore
import carrot from '../../assets/images/carrot.png';

interface CarrotProps {
    angle: number,
    hidden: string
}

export const Carrot: React.FC<CarrotProps> = (props): JSX.Element => {
    return (
        <div className='carrot-cell'>
            <img className={`carrot ${props.hidden}`} src={carrot} alt='bunny' style={{transform: `rotate(${props.angle}deg)`}}/>
        </div>
    );
}
