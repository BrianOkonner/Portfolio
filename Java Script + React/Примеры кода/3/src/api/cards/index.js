import storage from "../../api";

const CARDS_STORAGE_KEY = "todos";

export const getCards = async () => {
    const cards = await storage.getItem(CARDS_STORAGE_KEY);

    return cards || [];
};

export const addCard = async (text, firstImagePath,secondImagePath) => {
    const cards = (await storage.getItem(CARDS_STORAGE_KEY)) || [];

    cards.push({ id: `${Date.now()}`, text,firstImagePath,secondImagePath, isReverse: false });

    return storage.setItem(CARDS_STORAGE_KEY, cards);
};

export const removeCard = async (id) => {
    const cards = await storage.getItem(CARDS_STORAGE_KEY);

    return storage.setItem(
        CARDS_STORAGE_KEY,
        cards.filter((card) => card.id !== id),
    );
};

export const updateCard = async (card) => {
    const cards = (await storage.getItem(CARDS_STORAGE_KEY)) || [];

    cards.splice(
        cards.findIndex((c) => c.id === card.id),
        1,
        card,
    );

    return storage.setItem(CARDS_STORAGE_KEY, cards);
};