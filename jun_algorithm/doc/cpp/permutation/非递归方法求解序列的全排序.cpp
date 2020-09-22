#include <iostream>
#include <vector>
using namespace std;

/*
�ǵݹ�ķ���ʵ��ȫ����
˼·��ʹ��STL�е�˼�룬�Ӻ���ǰ��һ�����ڵ�������һ�����ڵ�����
��һ��Ԫ��С�ڵڶ���Ԫ�أ�����*i < *ii,�Ӻ���ǰ�ҵ���һ��Ԫ��*j��
ʹ��*j > *i,Ȼ�󽻻�*i��*j,Ȼ�󽻻���*ii��ʼ������*ii���ڣ���
����ĩβ������
*/
void Rserve(vector<int>& vec,int begin,int end)
{
	while(begin <= end)
	{
		swap(vec[begin],vec[end]);
		begin++;
		end--;
	}
}

bool FindPair(vector<int>& vec,int& first,int& second)
{
	int last = vec.size()-1;
	for(;last>0;last--)
	{
		second = last;
		first = last-1;
		if(vec[first] < vec[second])
			return true;
	}
	return false;
}

bool next_premutation(vector<int>& vec)
{
	int first,second,index;
	if(FindPair(vec,first,second))
	{
		index = vec.size()-1;
		for(;index>=first;index--)
		{
			if(vec[index] > vec[first])
				break;
		}
		swap(vec[index],vec[first]);
		Rserve(vec,second,vec.size()-1);
		return true;
	}
	return false;
}

int main()
{
	vector<int> vec(3);
	int i;
	for(i=0;i<vec.size();i++)
		vec[i] = i+1;
	vec[1]	=1;
	do{
		int i;
		for(i=0;i<vec.size();i++)
			cout<<vec[i]<<" ";
		cout<<endl;
	}while(next_premutation(vec));
	return 0;
}

