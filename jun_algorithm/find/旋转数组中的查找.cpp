#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
��һ�����ظ�Ԫ�ص��Ѿ�����ת���������в���ĳһ��Ԫ��
�����Ԫ�ش��ڸ���ת�����У�����1
�����Ԫ�ز����ڸ���ת�����У�����0
*/

bool RotateArray(vector<int>& vec,int key)
{
	int low =0,high = vec.size()-1;
	int mid;
	while(low<=high)
	{
		mid = low + (high-low)/2;
		if(vec[mid] == key)
			return 1;
		//����������������������������
		if(vec[mid]>vec[low]) //ǰ�벿��һ��������
		{
			if(key >= vec[low]&& key<vec[mid]) //˵�������ҵ�Ԫ����������������
				high =mid-1;
			else//ʣ�µ������������ת�����в���
				low = mid+1;
		}
		else //ǰ�벿�ֲ������򣬰����˾�����ת�Ĳ���
		{
			if(key > vec[mid]&& key<= vec[high])
				low= mid+1;
			else
				high = mid-1;
		}
	}
	return 0;
}

/*
��һ�����ظ�Ԫ�ص���ת�����в���ĳһ��Ԫ��
�жϸ�Ԫ���Ƿ����
*/
bool RotateArray2(vector<int>& vec,int key)
{
	int low = 0,high=vec.size()-1;
	int mid;
	//ͬ��ʹ�ö��ֲ��ҵ�˼��
	while(low <= high)
	{
		mid = low+(high-low)/2;
		if(vec[mid] == key)
			return 1;
		if(vec[mid] > vec[low])//ǰ�벿��������
		{
			if(key >= vec[low] && key < vec[mid])
				high = mid-1;
			else
				low = mid+1;
		}
		else if(vec[mid] < vec[low]) //ǰ�벿���ǽ���
		{
			if(key > vec[mid] && key <= vec[high])
				low = mid+1;
			else
				high = mid-1;
		}
		else
			low++;
	}
	return 0;
}

int main()
{
	int array[]={4,5,6,7,0,1,2};
	vector<int> vec(array,array+sizeof(array)/sizeof(int));
	cout<<RotateArray2(vec,9)<<endl;
}
