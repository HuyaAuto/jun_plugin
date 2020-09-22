#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
���ڼ������ţ��ж�������ȷ����Ϸ�ʽ
˼·��ʹ�õݹ�ķ�����ֻ�����ڵݹ��ʱ��
ʱ����Ҫ��֤��ߵ����ű��ұߵ����Ŷ�
ֻ���������ű������Ŷ������²��п��ܱ�֤��������Ϊ�Ϸ�������ƥ��
*/

void helper(vector<char>& str,int l,int r)
{
	if(l == 0 && r == 0)
	{
		for(int i=0;i<str.size();i++)
		{
			cout<<str[i];
		}
		cout<<endl;
	}
	if(l>0)
	{
		str.push_back('(');
		helper(str,l-1,r);
		str.pop_back();
	}
	if(r>0 && l<r)
	{
		str.push_back(')');
		helper(str,l,r-1);
		str.pop_back();
	}
}

void GenerateParenthess(int n)
{
	if(n<=0)
		return ;
	vector<char> tmp;
	helper(tmp,n,n);
}

int main()
{
	GenerateParenthess(3);
	return 0;
}
