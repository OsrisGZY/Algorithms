#include <iostream>
#include <vector>
void print_array(std::vector<int> v)
{
	for (int i =0; i<v.size(); i++)
		std::cout<<v[i]<<" ";
	std::cout<<std::endl;
}
//升序排列
std::vector<int> merge(std::vector<int> v, std::vector<int> u)
{
	std::vector<int> result(v.size() + u.size());
	int i=0, j=0;
	for(int t=0; t<v.size()+u.size(); t++)
	{
		if((v[i]>u[j] && j < u.size()) || i == v.size())
		{
			result[t] = u[j];
			j++;
		}
		else
		{
			result[t] = v[i];
			i++;
		}
	}
	return result;
}

std::vector<int> merge_sort(std::vector<int> v)
{	
	if(v.size()==1)
		return v;
	else
	{
		int n = v.size() / 2;
		std::vector<int> left(v.begin(), v.begin() + n);
		std::vector<int> right(v.begin()+n, v.end());
		std::vector<int> new_left;
		std::vector<int> new_right;
		if(left.size()>1)
			new_left = merge_sort(left);
		else
			new_left = left;
		if(right.size()>1)
			new_right = merge_sort(right);
		else
			new_right = right;
		return merge(new_left, new_right);
	}
}
int main()
{
	int array_local[7]={};
	std::cout<<"input array:"<<std::endl;
	for(int i=0;i<7;i++)
		std::cin>>array_local[i];

	std::vector<int> array(array_local,array_local+7); //从数组中获得初值
	print_array(array);
	print_array(merge_sort(array));

}