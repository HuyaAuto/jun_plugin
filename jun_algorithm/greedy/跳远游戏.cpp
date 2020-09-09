#include <iostream>
#include <vector>
using namespace std;

/*
̰��˼�룬ʱ�̼��㵱ǰλ�ú͵�ǰλ����������Զ���ȣ���ʼ�պͽ��ޱȽ�
��������λ�ó����������Ϊ0����ô���޷���������ȥ
������λ�ó����������+��ǰλ�� >���ޣ���ô˵����������ȥ 
*/

bool canJump(vector<int>& vec)
{
	if(vec.size() <=0)
		return true;
	int maxstep = vec[0];
	for(int i=1;i<vec.size();i++)
	{
		if(maxstep == 0)
			return false;
		maxstep--;
		if(maxstep < vec[i])
			maxstep = vec[i];
		if(maxstep+i >= vec.size()-1)
			return true;
	}
}

int main()
{
	int array[]={2,3,1,1,4};
	vector<int> vec(array,array+sizeof(array)/sizeof(int));
	cout<<canJump(vec)<<endl;
	return 0;
}
