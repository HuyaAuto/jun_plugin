#include <stdio.h>
#include <stdlib.h>

// �����ַ��� ʹ���ַ����д�д�ַ���ǰ Сд�ַ��ں�
void StrSort(char* str)
{
	int index =-1;
	int pos =0;
	char temp;
	for(;str[pos]!='\0';pos++)
	{
		if(str[pos] >= 'A' && str[pos]<='Z')
		{
			index++;
			temp = str[index];
			str[index] = str[pos];
			str[pos]= temp;
		}
	}
}

// ͬ����Ҫ�� ����ʹ��Сд�ַ������˳�򲻸ı�
void StrSort2(char* str)
{
	int len =0;
	while(str[len]!='\0')
		len++;
	int index =len;
	int pos = len-1;
	char temp;

	for(;pos>=0;pos--)
	{
		if(str[pos] >= 'a' && str[pos] <= 'z')
		{
			index--;
			temp = str[index];
			str[index]=str[pos];
			str[pos] = temp;
		}
	}
}


int main()
{
	char str[] ="jdfIhdHHfdslfdSFDldfaDSKdIdgHWlkfDf";
	printf("%s\n",str);
	StrSort(str);
	printf("%s\n",str);

	char str[] ="jdfIhdHHfdslfdSFDldfaDSKdIdgHWlkfDf";
	StrSort2(str);
	printf("%s\n",str);
	return 0;
}
