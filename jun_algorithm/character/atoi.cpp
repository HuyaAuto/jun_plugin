#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

/*
ʵ��atoi����

��Ҫע��ĵط���
1.��ֵԽ��
2.������
3.�ַ���������־
*/

int StringToInt(string& str)
{
	if(str.length() == 0)
		return 0;
	int i;
	int flag =1;
	int result =0;
	int digit;

	//��տ�ʼ�Ŀո��ַ�
	for(i=0;i<str.length();i++)
		if(str[i] !=' ')
			break;
	//����������
	if(str[i] == '+')
		i++;
	if(str[i]== '-')
	{
		flag =0;
		i++;
	}

	//��ʼ�����ַ�
	for(;i<str.length();i++)
	{
		if(str[i]<'0' || str[i] > '9')
			break;
		digit = str[i]-'0';
		//�ж�Խ��
		if(flag && (numeric_limits<int>::max() - result*10) <= digit)
			return numeric_limits<int>::max();
		else if(!flag && (numeric_limits<int>::min() + result*10) >= digit*-1)
			return numeric_limits<int>::min();
		result = result*10+digit;
	}
	return flag ==1? result:-result;
}

int main()
{
	string str("-4324324878787998797");
	cout<<StringToInt(str)<<endl;
	return 0;
}
