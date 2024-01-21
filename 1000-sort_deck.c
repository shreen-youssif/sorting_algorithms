#include "deck.h"
#include <stdlib.h>

/**
 * compare_cards - Compare two cards for sorting
 *
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 *
 * Return: Negative, zero, or positive value based on comparison
 */
int compare_cards(const void *a, const void *b)
{
    const card_t *card_a = (*(const deck_node_t **)a)->card;
    const card_t *card_b = (*(const deck_node_t **)b)->card;

    if (card_a->kind != card_b->kind)
        return (card_a->kind - card_b->kind);
    return (value_to_int(card_a->value) - value_to_int(card_b->value));
}

/**
 * value_to_int - Convert card value to integer for comparison
 *
 * @value: Card value
 *
 * Return: Integer representing the card value
 */
int value_to_int(const char *value)
{
    if (*value == 'A')
        return 1;
    if (*value == 'K')
        return 13;
    if (*value == 'Q')
        return 12;
    if (*value == 'J')
        return 11;
    return (*value - '0');
}

/**
 * sort_deck - Sort a deck of cards
 *
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t i, count = 0;
    deck_node_t *current;
    deck_node_t **array;

    if (deck == NULL || *deck == NULL)
        return;

    current = *deck;
    while (current)
    {
        count++;
        current = current->next;
    }

    array = malloc(count * sizeof(*array));
    if (array == NULL)
        return;

    current = *deck;
    for (i = 0; i < count; i++)
    {
        array[i] = current;
        current = current->next;
    }

    qsort(array, count, sizeof(*array), compare_cards);

    *deck = array[0];
    for (i = 0; i < count - 1; i++)
    {
        array[i]->next = array[i + 1];
        array[i + 1]->prev = array[i];
    }
    array[count - 1]->next = NULL;

    free(array);
}
