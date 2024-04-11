#include "sort.h"
/**
 * partition - Lomuto partition scheme
 * @array: Pointer to the array to be partitioned
 * @low: The index of the first element of the partition
 * @high: The index of the last element of the partition
 *
 * Return: The index of the pivot element.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int temp;

	if (low < 0 || high >= (int)size)
		return -1;

	for (int j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}
/**
 * quick_sort_helper - Sorts an array of integers using the Quick sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort_helper(int *array,int low, int high, size_t size)
{
	int partition_index; 

	if (low >= high || low < 0)
		return;

	if (low < high)
	{
		partition_index = partition(array, low, high, size);
		quick_sort_helper(array, low,  partition_index - 1, size);
		quick_sort_helper(array, partition_index + 1, high, size);
	}
}
/**
 * quick_sort - that sorts an array of integers
 * @array: an array of integers
 * @size: the lenght of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL ||size < 2)
		return;
	print_array(array, size);
	quick_sort_helper(array, 0, size - 1, size);
}
