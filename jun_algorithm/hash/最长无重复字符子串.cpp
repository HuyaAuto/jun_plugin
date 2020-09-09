#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
��Ŀ���û���ظ��ַ����Ӵ�
˼·���������е��ַ�����26��СдӢ���ַ����Դ˽���hash��
hash���ڼ�¼���ַ����ֵ�λ�ã�������ֵ�ǰ�ַ�����ǰ���������ַ������Ѿ�����
��ô���ϴγ�������ַ���λ�õ���һ���ַ����±���
��ô��hash����գ������ӵ�ǰλ�ÿ�ʼ����
*/

int Longest_substring(string& str)
{
	vector<int> hash(26,-1);
	int i;
	int cur =0;
	int maxlen =0;
	int tmp;
	for(i=0;i<str.size();i++)
	{
		if(hash[str[i]-'a'] ==-1)
		{
			hash[str[i]-'a'] =i;
			++cur;
			maxlen = maxlen > cur?maxlen:cur;
		}
		else
		{
			tmp = hash[str[i]-'a'];//��ʱ��¼��λ��
			i = tmp;
			cur =0;
			//memset(&hash[0],-1,sizeof(int)*hash.size());
		}
	}
	return maxlen;
}
/*
ͬ����˼�� ���ķ���
*/
int lengthOfLongeststring(string s)
{
	vector<int> charIndex(256,-1);//������չ�������е��ַ�
	int longest =0;
	int m=0;

	for(int i=0;i<s.size();i++)
	{
		m = max(charIndex[s[i]]+1,m);
		charIndex[s[i]] =i;
		longest = max(longest,i-m+1);
	}
	return longest;
}
int main()
{
	string str("abcabferafjlkcbb");
	cout<<lengthOfLongeststring(str)<<endl;
	return 0;
}
