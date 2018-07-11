#include <iostream>

template <class T>
int minimum(T array[], int n)
{
	int index = 0;
	for(int i=1;i<n;i++)
		if(array[i] <= array[index])
			index = i;
	return index;

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
T random_select(T array[], int begin, int end, int i)
{
	if(begin == end)
		return array[begin];
	int middle = partition(begin, end, array);
	int num = middle -  begin + 1;
	if(num == i)
		return array[middle];
	else if(num < i)
		return random_select(array, middle + 1, end, i - num);
	else
		return random_select(array, begin, middle - 1, i);
		// return random_select(array, begin, middle, i); 换成这个就会报错


}

void print_array(int array[], int n)
{
	for (int i =0; i<n; i++)
		std::cout<<array[i]<<" ";
	std::cout<<std::endl;
}
int main()
{
	int n = 16;
	int array[16] = {13,-3,-25,20,-3,-16,-23,-18,-20,-7,12,-5,22,15,-4,7};
	print_array(array, 16);
	std::cout<<"minimum:"<<minimum(array, n)<<" "<<array[minimum(array, n)]<<std::endl;
	std::cout<<"input index:"<<std::endl;
	int index;
	std::cin>>index;
	std::cout<<"minimum index:"<<index<<":"<<random_select(array, 0, n-1, index)<<std::endl;
}