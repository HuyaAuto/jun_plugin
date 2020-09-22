#include <iostream>
#include <vector>
using namespace std;
/*
ȫ��������
���ַ���abcΪ��
���ȹ̶�a������������ַ�bc��ȫ���У�����֮��
�ѵ�һ���ַ�a�ͺ����b�������õ�bac�������̶���һ���ַ�b������������ַ�ac
�����У�Ȼ���c�ŵ���һλ��....
*/

int count =0;//��¼���и���
void Permutation(char* str,int begin)
{
	if(str[begin] == '\0')
	{
		cout<<str<<endl;
		count++;
	}
	for(int i= begin;str[i] != '\0';i++)
	{
		swap(str[i],str[begin]);//������ǰλ�ú͵�һ��λ��
		Permutation(str,begin+1);//�����һλ��֮����ַ���������
		swap(str[i],str[begin]);//�ع�ԭʼ״̬
	}
}

/*
ȥ���ظ���ȫ���е�ʵ��
���һ�����ͺ��������ͬ����ô���������Ͳ�����
Ҳ����˵��ȥ���ظ���ȫ���о��Ǵӵ�һ��Ԫ����ÿ��Ԫ�طֱ����������
�ظ����ֵ�Ԫ�ؽ���
*/
bool isValid(vector<int>& vec,int begin,int index)
{
	int i;
	for(i = begin;i<index;i++)
	{
		if(vec[i] == vec[index])
			return false;

	}
	return true;
}

void Permutation(vector<int>& vec,int begin,int end)
{
	int i=0;
	if(begin >= end)
	{
		for(i=0;i<vec.size();i++)
			cout<<vec[i]<<" ";
		cout<<endl;
		return ;
	}
	for(i = begin;i<= end;i++)
	{
		if(isValid(vec,begin,i))
		{
			swap(vec[begin],vec[i]);
			Permutation(vec,begin+1,end);
			swap(vec[begin],vec[i]);
		}
	}
}

int main()
{

	vector<int> vec(3);
	int i;
	for(i=0;i<vec.size();i++)
		vec[i] = i+1;
	vec[1]=1;
	int pos =0;
	Permutation(vec,pos,2);
	char str[]="abcd";
//	Permutation(str,0);
//	cout<<count<<endl;
	return 0;
}
