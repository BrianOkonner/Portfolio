import { Close } from "@styled-icons/material-outlined/Close";

import { removeCard, updateCard } from "../../../api/cards";

import { Container,Image, Content, Text } from "./styled";

const Item = ({ id, isFrontView,firstImagePath,secondImagePath, requestCards, text }) => {
    const handleTodoClick = async () => {
        await updateCard({ id, isFrontView: !isFrontView, text,firstImagePath,secondImagePath });

        requestCards();
    };

    const handleRemoveClick = async () => {
        await removeCard(id);

        requestCards();
    };

    return (
        <Container isFrontView={isFrontView}>
            <Content onClick={handleTodoClick}>
                {!isFrontView ? (
                    <Image src={firstImagePath} />
                ) : (
                    <Image src={secondImagePath} />
                )}
                <Text>{text}</Text>
            </Content>
            <Close size={24} title="Remove" onClick={handleRemoveClick} />
        </Container>
    );
};

export default Item;