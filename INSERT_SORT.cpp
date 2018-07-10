#include <iostream>

void print_array(int array[], int n)
{
	for (int i =0; i<n; i++)
		std::cout<<array[i]<<" ";
	std::cout<<std::endl;
}
void insert_sort(int array[], int n)
{
	for(int i = 1; i<n; i++)
	{
		int j = i-1;
		int key = array[i];
		while(j>=0 && array[j] > key)
		{
			array[j+1] = array[j];
			j = j - 1;
		}
		array[j+1] = key;
	}
}
int main()
{
	int array[6] = {6,3,7,2,1,8};
	print_array(array, 6);
	insert_sort(array, 6);
	print_array(array, 6);
}