#include <iostream>
//升序排列
void swap(int array[] , int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
void print_array(int array[], int n)
{
	for (int i =0; i<n; i++)
		std::cout<<array[i]<<" ";
	std::cout<<std::endl;
}
void insert_sort(int array[], int n, int array_2[], int array_3[])
{
	for(int i = 0; i<n; i++)
	{
		if(i==0)
			continue;
		for(int j=0; j<i; j++)
		{
			int key = array[i];
			if(key < array[j])
			{
				swap(array, i, j);
				swap(array_2, i, j);
				swap(array_3, i, j);
			}
		}
	}
}

void radix_sort(int array[], int array_2[], int array_3[], int n)
{
	insert_sort(array, n, array_2, array_3);
	insert_sort(array_2, n, array, array_3);
	insert_sort(array_3, n, array, array_2);
}
int main()
{
	int array[6] = {6,3,7,2,1,8};
	int array_2[6] = {1,0,2,2,4,2};
	int array_3[6] = {3,3,1,5,2,1};
	print_array(array, 6);
	print_array(array_2, 6);
	print_array(array_3, 6);
	radix_sort(array, array_2, array_3, 6);

	print_array(array, 6);
	print_array(array_2, 6);
	print_array(array_3, 6);
}