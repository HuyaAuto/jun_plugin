#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
��Ŀ���ھŹ����ֻ������ϣ�ÿ�����ֶ���Ӧ�ż����ַ�
����һ�����ֵ��ַ������ҳ����ж�Ӧ���ַ�������ϣ�ÿ��
������һ���ַ����ж�Ӧ 
*/
void helper(string& str,int begin,vector<string>& hash,vector<char>& vec)
{
	 int i;
	 if(begin > str.length())
	 	return;
	if(begin == str.length())
	{
		for(i=0;i<vec.size();i++)
			cout<<vec[i];
		cout<<endl;
		return;
	}
	for(i=0;i<hash[str[begin]-'0'].length();i++)
	{
		vec.push_back(hash[str[begin]-'0'][i]);
		helper(str,begin+1,hash,vec);
		vec.pop_back();
	}
}

void Combination(string& str,vector<string>& hash)
{
	if(str.length()==0)
		return ;
	vector<char> vec;
	helper(str,0,hash,vec);
}

void LetterCom(string& str)
{
	int i;
	vector<string> hash(10); //���������10������ 
	hash[0]=" ";
	hash[1]="-";
	hash[2]="abc";
	hash[3]="def";
	hash[4]="ghi";
	hash[5]="jkl";
	hash[6]="mno";
	hash[7]="pqrs";
	hash[8]="tuv";
	hash[9]="wxyz";
	
	Combination(str,hash);
	return ;
} 

int main() 
{
	string str("23");
	LetterCom(str);
	return 0;
}
