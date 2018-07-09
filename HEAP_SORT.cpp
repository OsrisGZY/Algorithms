#include "HEAP_SORT.h"
#include <iostream>

void print_array(int array[], int n);

int main()
{
	int array[15] = {1,-3,-2,20,-3,-16,-23,-18,-20,-7,12,-5,22,15,7};
	print_array(array, 15);
	heap_sort(array, 15);
	print_array(array, 15);
}


void print_array(int array[], int n)
{
	for (int i =0; i<n; i++)
		std::cout<<array[i]<<" ";
	std::cout<<std::endl;
}