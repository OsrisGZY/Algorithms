#include <iostream>
//升序排列
void swap(int array[] , int i, int j)
{
	int temp = array[i-1];
	array[i-1] = array[j-1];
	array[j-1] = temp;
}
void print_array(int array[], int n)
{
	for (int i =0; i<n; i++)
		std::cout<<array[i]<<" ";
	std::cout<<std::endl;
}
void insert_sort(int array[], int n)
{
	for(int i = 0; i<n; i++)
	{
		if(i==0)
			continue;
		for(int j=0; j<i; j++)
		{
			int key = array[i];
			if(key < array[j])
				swap(array, i+1, j+1);
		}
	}
}
int main()
{
	int array[6] = {6,3,7,2,1,8};
	print_array(array, 6);
	swap(array, 1,3);
	print_array(array, 6);
	insert_sort(array, 6);
	print_array(array, 6);
}