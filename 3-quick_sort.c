#include "sort.h"
/**
 * partition - Lomuto partition scheme
 * @array: Pointer to the array to be partitioned
 * @low: The index of the first element of the partition
 * @high: The index of the last element of the partition
 * @size: Number of elements in the array
 * Return: The index of the pivot element.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int temp;

	for (int j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (temp != array[i])
				print_array(array, size);
			++i;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	if (temp != array[i])
		print_array(array, size);

	return (i);
}
/**
 * quick_sort_helper - Sorts an array of integers
 * using the Quick sort algorithm
 * @array: Pointer to the array to be sorted
 * @low: The index of the first element of the partition
 * @high: The index of the last element of the partition
 * @size: Number of elements in the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < 0 || low >= high)
		return;

	partition_index = partition(array, low, high, size);
	quick_sort_helper(array, low,  partition_index - 1, size);
	quick_sort_helper(array, partition_index + 1, high, size);
}
/**
 * quick_sort - that sorts an array of integers
 * @array: an array of integers
 * @size: the lenght of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
