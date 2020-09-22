#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
����������������Ľ���
*/

void FindElements(vector<int>& first,vector<int>& second)
{
	if(first.size() <=0 || second.size() <= 0)
		return;
	//������
	sort(first.begin(),first.end());
	sort(second.begin(),second.end());

	//����Ԫ�ظ����ٵ���������һ���������Ƿ����
	if(first.size() >second.size())
		first.swap(second);
	int i,key;
	for(i =0;i<first.size();i++)
	{
		key = first[i];
		int low = 0;
		int high = second.size()-1;
		//��first�����е�Ԫ��Ϊ��׼ ��second�����н��ж��ֲ���
		while(low<= high)
		{
			int mid = low +(high-low)/2;
			//����ҵ� ˵���ǽ����е�Ԫ�أ���ô��ӡ���������ж���һ��Ԫ���Ƿ�����ҵ�
			if(key == second[mid])
			{
				cout<<second[mid]<<endl;
				break;
			}
			else if(key > second[mid])
				low = mid+1;
			else
				high = mid-1;

		}

	}
}

int main()
{
	int array[]={5,4,3,8,9,7,0};
	int array1[]={11,8,34,3,4,8,9,2};
	vector<int> first(array,array+sizeof(array)/sizeof(int));
	vector<int> second(array1,array1+sizeof(array1)/sizeof(int));
	FindElements(first,second);
	return 0;
}
