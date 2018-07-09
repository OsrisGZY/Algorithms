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
int partition(int begin, int end, T array[]) 
{
	int index = begin - 1;
	T x = array[end];
	for(int i = begin; i<end; i++)
	{
		if(array[i] <= x)
		{
			index = index + 1;
			swap(index, i, array);
		}
	}
	index = index + 1;
	swap(index, end, array);
	// std::cout<<"find index"<<index<<std::endl;
	return index;
}

template <class T>
void quick_sort(int begin, int end, T array[])
{
	if(begin > end)
	{
		std::cout<<"error"<<std::endl;
	}
	else
	{
		int middle = partition(begin, end, array);
		//注意array[middle]不用参加递归式
		// std::cout<<"segmentation OK "<<middle<<std::endl;
		if(middle-begin>1)
			quick_sort(begin, middle - 1, array);
		if(end - middle > 1)
			quick_sort(middle + 1, end, array);
	}
}

int main()
{
	int array[16] = {13,-3,-25,20,-3,-16,-23,-18,-20,-7,12,-5,22,15,-4,7};
	print_array(array, 16);
	quick_sort(0,15, array);
	print_array(array, 16);

}

