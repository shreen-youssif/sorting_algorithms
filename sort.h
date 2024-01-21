#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
/* quick sort **/

void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *a, listint_t *b);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *array, size_t left, size_t right);
void merge(int *array, size_t left, size_t middle, size_t right);
void heap_sort(int *array, size_t size);
void build_max_heap(int *array, size_t size);
void heapify(int *array, size_t size, int root);
#endif /* SORT_H */
