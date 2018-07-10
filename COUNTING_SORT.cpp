#include <iostream>

void print_array(int array[], int n)
{
	for (int i =0; i<n; i++)
		std::cout<<array[i]<<" ";
	std::cout<<std::endl;
}
template <class T>
void swap(int i, int j, T array[])
{
	T temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}


template <class T>
void counting_sort(T u[], T v[],int k, int n)
{
	int count[k + 1];
	for(int i=0;i<=k; i++)
		count[i] = 0;
	// count[i] contains the number of elements equal to i
	for(int i=0;i<n; i++)
		count[u[i]] = count[u[i]] + 1;
	// count[i] contains the number of elements less than or equal to i
	for(int i=1; i<=k; i++)
		count[i] = count[i-1] + count[i];
	for(int i=n-1; i>=0; i--)
	{
		v[count[u[i]] - 1] = u[i];
		count[u[i]] = count[u[i]] - 1;
	}
}

int main()
{
	int array[16] = {13,3,25,20,3,16,23,18,20,7,12,5,22,15,4,7};
	int array_2[16];
	print_array(array, 16);
	counting_sort(array,array_2, 30, 16);
	print_array(array_2, 16);

}

