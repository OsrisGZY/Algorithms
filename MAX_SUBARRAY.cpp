#include <iostream>

struct subarray{
	int low_index;
	int high_index;
	double sum;
};

void print_array(int array[], int n)
{
	for (int i =0; i<n; i++)
		std::cout<<array[i]<<" ";
	std::cout<<std::endl;
}

template <class T>
T* getArray(int begin, int end, T array[]) 
{
    T *result = new T[end-begin+1];
    for(int i = 0; i<=end-begin;i++)
    	result[i] = array[begin + i];
    return result;
}
struct subarray find_max_crossing_subarray(int low, int hight, int middle, int array[])
{
	subarray result;
	result.sum = array[middle];
	result.low_index = middle;
	result.high_index = middle;
	double temp_result = result.sum;
	for(int i=middle-1; i>=low; i--)
	{
		temp_result = temp_result + array[i];
		// std::cout<<"temp result"<<temp_result<<" result.sum"<<result.sum<<std::endl;
		if(temp_result > result.sum)
		{
			result.sum = temp_result;
			result.low_index = i;
			// std::cout<<"low_index"<<result.low_index<<" "<<std::endl;
		}
	}
	std::cout<<"middle"<<result.low_index<<std::endl;	
	temp_result = result.sum;
	for(int i=middle+1; i<=hight; i++)
	{
		temp_result = temp_result + array[i];
		if(temp_result > result.sum)
		{
			result.sum = temp_result;
			result.high_index = i;
		}
	}
	return result;
};

struct subarray find_max_subarray(int low, int high, int array[])
{
	subarray result;
	if(low == high)
	{
		result.low_index = result.high_index = low;
		result.sum = array[low];
	}
	else
	{
		int middle = (high - low) / 2;
		int *low_array = getArray(low, middle, array);
		int *high_array = getArray(middle+1,high,array);
		subarray result_low = find_max_subarray(0, middle - low, low_array);
		subarray result_high = find_max_subarray(0, high - middle-1 , high_array);
		subarray result_middle = find_max_crossing_subarray(low, high, middle, array);

		delete[] low_array;
		delete[] high_array;

		result_high.low_index = result_high.low_index + middle + 1;
		result_high.high_index = result_high.high_index + middle + 1;

		if(result_low.sum > result_middle.sum)
		{
			result = result_low;
			// std::cout<<"low"<<result.sum<<std::endl;
		}
		else
		{
			result = result_middle;
			// std::cout<<"middle"<<result.low_index<<std::endl;
		}
		if(result.sum < result_high.sum)
		{
			result = result_high;
			// std::cout<<"high"<<result.sum<<std::endl;
		}
	}
	return result;

};

int main()
{
	int array[16] = {13,-3,-25,20,-3,-16,-23,-18,-20,-7,12,-5,22,15,-4,7};
	print_array(array, 16);
	subarray result = find_max_subarray(0, 15, array);
	// int *low_array = getArray(0, 12, array);
	// print_array(low_array, 12);
	std::cout<<"array size:"<<" "<<sizeof(array)<<std::endl;
	std::cout<<result.low_index<<" "<<result.high_index<<" "<<result.sum<<std::endl;

}

// template <class T>
// int getArrayLen(T& array) //使用模板定义一个函数getArrayLen,该函数将返回数组array的长度
// {
//     return (sizeof(array) / sizeof(array[0]));
// }

