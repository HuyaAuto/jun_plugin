/*
����һ���ַ�����������ַ������ַ����������
*/

#include <iostream>
#include <vector>
using namespace std;
/*
˼·���ڳ���Ϊn���ַ�������m���ַ������
��ͷɨ���ַ����õ�һ���ַ�����Ե�һ���ַ���������ѡ��
������ַ��ŵ������ȥ��������������Ҫ��ʣ�µ�n-1���ַ���ѡȡm-1���ַ�
��������ַ��ŵ������ȥ����Ҫ��ʣ�µ�n-1���ַ���ѡȡm���ַ�
*/
void Combination(char* string, int number, vector<char>& result)
{
    if(number == 0)
    {
        vector<char>::iterator iter = result.begin();
        for(; iter < result.end(); ++ iter)
            cout<<(*iter);
        cout<<endl;
        return;
    }
    if(*string == '\0')
        return;
    result.push_back(*string);
    Combination(string + 1, number - 1, result);
    result.pop_back();
    Combination(string + 1, number, result);
}
void Combination(char* string)
{
    if(string == NULL)
        return;
    int length = strlen(string);
    vector<char> result;
    for(int i = 1; i <= length; ++ i)
    {
        Combination(string, i, result);
    }
}
int main()
{
	char str[] ="abc";
	Combination(str);
	return 0;
}
