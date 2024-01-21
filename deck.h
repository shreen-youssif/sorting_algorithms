#ifndef DECK_H
#define DECK_H

#include <stddef.h>

/**
 * enum kind_e - Suit of a card
 *
 * @SPADE: Spade suit
 * @HEART: Heart suit
 * @CLUB: Club suit
 * @DIAMOND: Diamond suit
 */
typedef enum kind_e
{
    SPADE,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card (Ace to King)
 * @kind: Suit of the card (Spade, Heart, Club, Diamond)
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Node in a doubly-linked list representing a deck of cards
 *
 * @card: Pointer to the card
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
