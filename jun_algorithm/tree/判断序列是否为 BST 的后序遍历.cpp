#include <iostream>
#include <vector>
using namespace std;

/*
�ж�һ�������Ƿ�Ϊ�����������ĺ����������

���ں��������һ��Ҫ�������һ��Ԫ���Ǹ��ڵ㣬���������ȸ�Ԫ�ش�
���������ȸ�Ԫ��С,Ȼ��ݹ�����������
*/

bool helper_verify(vector<int>& vec,int begin,int end)
{
	int i,j;
	if(end-begin <=1)
		return true;
	for(i=begin;i<end;i++)
		if(vec[i] > vec[end])
			break;
	for(j=i;j<end;j++)
		if(vec[j] < vec[end])
			break;
	if(j<end-1)
		return false;
	return helper_verify(vec,begin,i-1) && helper_verify(vec,i,end-1);
}

bool verifyBST(vector<int>& vec)
{
	if(vec.size() <=1)
		return true;
	return helper_verify(vec,0,vec.size()-1);
}



int main()
{
	int array[]={1,3,2,5,6,8,7,4};
	vector<int> vec(array,array+sizeof(array)/sizeof(int));
	cout<<verifyBST(vec);
	return 0;
}
