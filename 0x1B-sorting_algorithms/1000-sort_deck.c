#include "deck.h"

/**
 * decode_name - convert a card name into a numerical value
 * @name: "Ace", "2" ... "9", "10", "Jack", "Queen", "King"
 * Return: 0, 50 ... 57, 58, 99, 101, 110
 */
static char decode_name(const char *name)
{
	if (!name[1]) /* 2-9 -> '2'-'9' */
		return (name[0]);
	if (!name[2]) /* 10 -> */
		return ('9' + 1);
	if (!name[3]) /* Ace -> 0 */
		return (0);
	return (name[2]); /* Jack/Queen/King -> 'c'/'e'/'n' */
}

/**
 * greater - check if card @a > card @b
 * @a: card a
 * @b: card b
 * Return: if @a > @b
 */
static char greater(const card_t *a, const card_t *b)
{
	if (a->kind != b->kind)
		return (a->kind > b->kind);
	return (decode_name(a->value) > decode_name(b->value));
}

/**
 * find_place - search backwards for the place that a card belongs
 * @start: node to start searching at
 * @card: card value to search for
 * Return: node to insert after
 */
static deck_node_t *find_place(deck_node_t *start, const card_t *card)
{
	while (start)
	{
		if (greater(card, start->card))
			return (start);
		start = start->prev;
	}
	return (NULL);
}

/**
 * sort_deck - sort a deck of cards (using insertion sort)
 * @deck: address of head ptr
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *curr, *place, *next;

	if (!deck)
		return;

	curr = (*deck)->next;
	while (curr)
	{
		next = curr->next;
		place = find_place(curr->prev, curr->card);
		if (place != curr->prev)
		{
			/* Remove from old position */
			if (curr->prev)
				curr->prev->next = next;
			if (next)
				next->prev = curr->prev;
			/* Insert at new position */
			if (!place) /* at beginning */
			{
				curr->next = *deck;
				(*deck)->prev = curr;
				*deck = curr;
				curr->prev = NULL;
			}
			else
			{
				curr->next = place->next;
				curr->prev = place;
				if (place->next)
					place->next->prev = curr;
				place->next = curr;
			}
		}
		curr = next;
	}
}
