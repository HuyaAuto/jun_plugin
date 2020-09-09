#include <stdio.h>
#include <stdlib.h>

//�����ַ����и����ַ����ֵĴ���
void FindTimes(char* str)
{
	int hash[256]={0};
	int index =0;
	while(str[index]!='\0')
	{
		hash[str[index]]++;
		index++;
	}

	for(index=0;index<256;index++)
		printf("%d ",hash[index]);
	printf("\r\n");
}
// ��η�תһ�����ӣ������������Ե���Ϊ��λ���з�ת
/**
��������������ӵķ�ת
Ȼ������ڲ����ʵĶ��η�ת
*/

//���ַ����й̶�λ�õ�������з�ת
void Reverse(char* str,int begin,int end)
{
	char tmp;
	while(begin < end)
	{
		tmp = str[begin];
		str[begin] = str[end];
		str[end] = tmp;
		begin++;
		end--;
	}
}

/*
�ַ����ڲ����ʵķ�ת ��ͷ����ʼ ÿȷ��һ�����ʾͽ��з�ת
*/

void Reverse_second(char* str,int len)
{
	int begin,i,j;
	for(i=0;i<len;)
	{
		begin =i;
		for(j=i;j<len;j++)
		   if(str[j]==' ')
		      break;
		Reverse(str,begin,j-1);
		i = j+1;
	}
}
int main()
{
	char str[]="Hello world dunso";
//	FindTimes(str);
    Reverse(str,0,16);
    Reverse_second(str,17);
    printf("%s \r\n",str);
	return 0;
}
