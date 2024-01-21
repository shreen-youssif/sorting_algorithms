#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


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
/* quick sort */
void swap(int *array, size_t size, int *a, int *b);
size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high);
void quicksort(int *array, size_t size, ssize_t low, ssize_t high);
void quick_sort(int *array, size_t size);
/* shell sort */
void shell_sort(int *array, size_t size);
/* cocktail list sort */
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *a, listint_t *b);
/* counting sort */
void counting_sort(int *array, size_t size);
/* merge sort */
void merge_sort(int *arr, size_t size);
void recursive_merge(int *arr, size_t left, size_t right, int *result);
void merge_arrays(int *arr, size_t left, size_t right, int *result);
/* heap sort */
void heap_sort(int *array, size_t size);
void build_max_heap(int *array, size_t size);
void heapify(int *array, size_t size, int root);
#endif /* SORT_H */
