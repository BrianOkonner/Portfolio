import {useCallback} from "react";
import {Container, SubTitle, Title} from "./styled";
import {getCards} from "../../api/cards";
import useAsync from "../../hooks/use-async";
import Item from "./Item";
import NewItem from "./NewItem";

const CardDeck = () => {
    const getCardsList = useCallback(() => getCards(), []);
    const {
        execute: requestCards,
        isLoading: isCardsLoading,
        value: cards = [],
    } = useAsync(getCardsList);
    return (<>
        <Container>
            <Title>My first deck</Title>
            <SubTitle>Click the items to view second card form</SubTitle>
            {cards.map((card) => (
                <Item
                    key={card.id}
                    id={card.id}
                    firstImagePath={card.firstImagePath}
                    secondImagePath={card.secondImagePath}
                    isFrontView={card.isFrontView}
                    requestCards={requestCards}
                    text={card.text}
                />
            ))}
        </Container>
    <NewItem isCardsLoading={isCardsLoading} requestCards={requestCards}/>
        </>
    );
}
export default CardDeck;