#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
˼·��
����һ�����͵�DP���⣬���趨��һ�����飬dp[i]Ϊ����i���ַ����ܹ���ɵ�
���б��뷽ʽ�ĸ�������ô����dp[i+1]��˵���϶����ٺ�dp[i]һ���࣬�����i
���ַ���i+1���ַ����Ժϳ�һ���ַ�����ôdp[i+1] += dp[i-1]. 
*/

int Decode_num(string& str)
{
	vector<int> vec(str.size(),1);
	if(str.size() <2)
		return 1;
	if(str[0]=='1'||(str[0]=='2'&& str[1]<='6'))
		vec[1] =2;
	int i;
	int tmp;
	for(i=2;i<str.size();i++)
	{
		if(str[i] >= '0' && str[i] <= '9')//�ж��ǺϷ����ַ� 
			vec[i] = vec[i-1];
		else
			return 0; 
		tmp = str[i-1] -'0';
		tmp = tmp*10 + str[i]-'0';
		
		if(str[i-1]!='0' && tmp <=26)
			vec[i] += vec[i-2];
		else
			vec[i] = vec[i-1];
	}
	return vec[str.size()-1];
}

int main()
{
	string str("1231725");
	cout<<Decode_num(str)<<endl;
	return 0;
} 
