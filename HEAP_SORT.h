#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <math.h>
#include <iostream>
template<class T>
T LEFT(T array[], int i)
{
	return array[2*i+1];	
}

template<class T>
T RIGHT(T array[], int i)
{
	return array[2*i+2];
}

template<class T>
T PARENT(T array[], int i)
{
	return array[(i-1)/2];
}

template<class T>
void max_heapify(T array[], int i, int n)
{
	int large = i;
	if(2*i+1 < n)
	{
		T left = LEFT(array, i);
		if(left>=array[i])
			large = 2*i+1;
		else
			large = i;
		if(2*i+2 < n)
		{
			T right = RIGHT(array, i);
			if(right >= array[large])
				large = 2*i+2;	
		}	
	}

	if(large != i)
	{
		T temp = array[i];
		array[i] = array[large];
		array[large] = temp;
		max_heapify(array, large, n);
	}

}

template<class T>
void build_max_heap(T array[], int n)
{
	for(int i=n-1;i>=0; i--)
		max_heapify(array, i, n);
	
};

template<class T>
void heap_sort(T array[], int n)
{
	build_max_heap(array, n);
	for(int i=n-1; i>0; i--)
	{
		T temp = array[i];
		array[i] =  array[0];
		array[0] = temp;
		max_heapify(array, 0, i);
	}	
};
#endif
