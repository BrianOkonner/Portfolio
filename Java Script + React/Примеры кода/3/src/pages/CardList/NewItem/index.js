import {useState} from "react";

import {addCard} from "../../../api/cards";

import {AddButton, Container, MiniContainer, Input, InputFile} from "./styled";

const NewItem = ({isCardsLoading, requestCards}) => {
    const [text, setText] = useState("");
    const [firstImage, firstSetImage] = useState("");
    const [secondImage, secondSetImage] = useState("");

    const handleInputChange = (event) => {
        setText(event.target.value);
    };

    const handleFirstImageChange = (event) => {
        if (event.target.files && event.target.files[0]) {
            firstSetImage(URL.createObjectURL(event.target.files[0]));
        }
    }
    const handleSecondImageChange = (event) => {
        if (event.target.files && event.target.files[0]) {
            secondSetImage(URL.createObjectURL(event.target.files[0]));
        }
    }

    const handleAddClick = async () => {
        if (text && firstImage && secondImage) {
            await addCard(text, firstImage, secondImage);

            requestCards();
            setText("");
        }
    };

    return (
        <Container>
            <Input value={text} onChange={handleInputChange}></Input>
            <MiniContainer>
                FRONT VIEW
                <InputFile type="file" onChange={handleFirstImageChange}/>
            </MiniContainer>
            <MiniContainer>
                BACK VIEW
                <InputFile type="file" onChange={handleSecondImageChange}/>
            </MiniContainer>
            <AddButton disabled={!text || isCardsLoading} onClick={handleAddClick}>
                Add
            </AddButton>
        </Container>
    );
};

export default NewItem;