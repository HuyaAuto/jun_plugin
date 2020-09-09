#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

//����һ�������еĵ�K���Ԫ��

int Find_K(int a[],int low,int high,int k)
{
	if(k<=0)
		return -1;
	if(k>high-low+1)
		return -1;
	//���ѡ��һ��֧��
	int pivot = low+rand()%(high-low+1);
	swap(a[low],a[pivot]);
	int m = low;
	int count = 1;

	// ÿ����һ��  �ѽϴ�ķŵ���������
	for(int i=low+1;i<=high;i++)
	{
		if(a[i] > a[low])
		{
			swap(a[++m],a[i]);
			count++; //�ȹؼ��������ĸ���Ϊcount+1
		}
	}
	swap(a[m],a[low]);// ���ؼ���������������ֵķֽ��
	if(count > k)
		return Find_K(a,low,m-1,k);
	else if(count < k)
		return Find_K(a,m+1,high,k-count);
	else
		return m;
}

//������С��K����
void FindMinTopK(vector<int>& vec,int k)
{
	vector<int> heap(vec.begin(),vec.begin()+k);
	make_heap(heap.begin(),heap.end());
	int i;

	//��ʼ����ʣ�������
	for(i =k;i<vec.size();i++)
	{
		if(vec[i]<heap[0])
		{
			pop_heap(heap.begin(),heap.end());
			heap.pop_back();
			heap.push_back(vec[i]);
			push_heap(heap.begin(),heap.end());
		}
	}

	for(i=0;i<heap.size();i++)
		cout<<heap[i]<<endl;
}
int main()
{
	int a[]={5,15,4,8,2,3,9,10};
	int r = Find_K(a,0,sizeof(a)/sizeof(int)-1,3);
//	cout<<(r==-1? r : a[r])<<endl;

	int array[]={5,3,6,7,4,2,1,9,8,10};
	vector<int> vec(array,array+sizeof(array)/sizeof(int));
	FindMinTopK(vec,4);
	return 0;
}
