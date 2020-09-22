#include <iostream>
#include <vector>
using namespace std;

/*
һ��������ֻ��һ�����������һ�� �������ǳ���������
�ҵ��������һ�ε�����
*/

//�����������е������������ ���õ��Ľ��������Ҫ�ҵ���
int SingleNumber(vector<int>& vec)
{
	if(vec.size()<=0)
		return 0;
	int i;
	int  value = vec[0];
	for(i=1;i<vec.size();i++)
		value ^= vec[i];
	return value;
}

/*
���һ����������������������һ�� �������ǳ��������� ���������ֱ���ʲô
*/

void SingleNumberII(vector<int>& a,int& pN1,int& pN2)
{
	int i,j,temp;

	//�������������������
	temp =0;
	for(i=0;i<a.size();i++)
		temp ^= a[i];

	//�ҵ�������е�һ��Ϊ1��λ
	for(j=0;j<sizeof(int)*8;j++)
		if(((temp >> j)&1) ==1)
			break;

	//��jλΪ1��˵�������������ڵ�jλ���ǲ�ͬ��  ������������з���
	pN1 =0;
	pN2 =0;
	for(i=0;i<a.size();i++)
		if(((a[i] >> j )&1) ==0)
			pN1 ^= a[i];
		else
			pN2 ^= a[i];

}

/*
һ��������ֻ��һ����������һ�� �������ǳ��������� �ҳ������
*/

//ͬ������λ���ж�

int SingleNumberIII(vector<int>& vec)
{
	int i,j;
	int low=0,high=vec.size()-1;
	int bit =1;
	int flag =0;

	//ͨ��ĳһλ��ֵ�������Ϊ�����֣�����һ���ְ����˴��ҵ��� ��һ���ֲ�����
	while(low <= high)
	{
		if(low == high)
			return vec[low];
		i = low-1;
		for(j = low;j<= high;j++)
		{
			if((vec[j]&bit) == 0)
			{
				i++;
				swap(vec[i],vec[j]);
			}
		}
		if(i >= low)
		{
			if((i-low+1)%3 == 0)
				low = i+1;
			else
				high =i;
		}
		bit = bit<<1;
	}
	return 0;
}
int main()
{
	int array[]={12,23,12,45,56,45,23,78,78,78,12,23,45};
	vector<int> vec(array,array+sizeof(array)/sizeof(int));
	int fir,sec;
	cout<<SingleNumberIII(vec);
//	cout<<fir<<endl<<sec<<endl;
	return 0;
}
