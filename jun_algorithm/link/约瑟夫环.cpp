#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Լɪ�����⣬ʹ��STL�е�List��
int Joseph(list<int>& ring,int k)
{
	list<int>::iterator itr = ring.begin(),temp;
	int m;
	//����ڵ��������1�ͻ�һֱɾ����ȥ
	while(ring.size()>1)
	{
		m =1;
		//�жϵ�ǰ�������Ƿ���Ҫ������λ
		if(itr == ring.end())
			itr = ring.begin();
		//���Һ��ʵĽڵ����ɾ��
		while(m <k)
		{
			//ʼ����Ҫ�ж��Ƿ���Ҫ������λ
			if(itr == ring.end())
				itr = ring.begin();
			itr++;
			m++;
			if(itr == ring.end())
				itr = ring.begin();
		}
		temp = itr;
		itr++;
		//ɾ����ѡ�еĽڵ�
		ring.erase(temp);
	}
	//ֻʣ��һ���ڵ�
	itr = ring.begin();
	return *itr;
}

int main()
{
	int i;
	list<int> ring;
	for(i=1;i<=9;i++)
		ring.insert(ring.begin(),i);
	cout<<Joseph(ring,5)<<endl;
	return 0;
}
