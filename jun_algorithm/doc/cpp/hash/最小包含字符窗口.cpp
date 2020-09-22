#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
��Ŀ��һ���ַ����ܰ�����һ���ַ�����������Ļ���Ӵ�����С����
˼·��ʹ������ָ�룬һ��hash������ָ��Ϊ�˼�¼�����hash��Ϊ�˼�¼�Ƿ����
Ŀ���Ӵ�������ָ��֮������˶��ٴΣ�ֱ�������ַ�������������Ӵ��ڣ�
�ƶ�ǰ���ָ�룬ֱ��ĳһ���Ӵ��������Ӵ���һ��
��ô����ռ�ĳ��Ⱦ��ǵ�ǰ��̵ģ���������ֱ���������ַ�����������
*/

string MinLength(string& src,string& dest)
{
	int i=0,j=0;
	int flag =0;
	int len = src.size();
	int pos =0;
	vector<int> hash(26,-1);
	for(i=0;i<dest.length();i++)
		hash[dest[i]-'A'] =0;
	//��ʼ����
	for(i=0;i<src.size();i++)
	{
		if(hash[src[i]-'A'] >= 0)
		{
			hash[src[i]-'A']++;
			if(hash[src[i]-'A'] ==1)
				flag++;
		}
		if(flag == dest.length())
		{
			for(;j<i;j++)
			{
				if(hash[src[j]-'A'] ==1)
					break;
				else
					hash[src[j]-'A']--;
			}
			if(len>i-j+1)
			{
				len =i-j+1;
				pos = j;
			}

			hash[src[j]-'A'] =0;
			j++;
			flag--;
		}
	}
	cout<<string(src,pos,pos+len)<<" pos is "<<pos<<" len is "<<len<<endl;
	return string(src,pos,pos+len);
}


int main()
{
	string src("ADOBECODEBANCAAABC");
	string dest("ABC");
	cout<<MinLength(src,dest)<<endl;
	return 0;
}
