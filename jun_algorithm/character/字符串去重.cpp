#include <stdio.h>
#include <stdlib.h>

// һ���Ѿ�����õ��ַ��� ���ظ����ַ�������һ��

void Remove(char* str)
{
	int index =0;
	int pos =1;
	for(;str[pos]!='\0';pos++)
	{
		if(str[pos] != str[index])
		{
			index++;
			str[index]= str[pos];
		}
	}
	str[index+1] ='\0';
}

// һ���Ѿ�����õ��ַ��� ���ظ����ַ���������
void Remove2(char* str)
{
	int index =0;
	int pos =1;
	int flag =0;
	for(;str[pos]!='\0';pos++)
	{
		//�����ǰλ�õ��ַ����Ѿ�������ַ������һ��λ�õ��ַ���ͬ
		if(str[pos] != str[index])
		{
			index++;
			str[index] = str[pos];
			flag=0;
		}
		//�����ǰλ�õ��ַ����Ѿ�������ַ������һ��λ�õ��ַ���ͬ
		else
		{
			if(flag == 0)
			{
				index++;
				str[index] = str[pos];
				flag =1;
			}
		}
	}
	str[index+1]='\0';
}

//�ظ����ַ�ȫ��ɾ��
void Remove3(char* str)
{
	int flag =0;
	int index =-1;
	int pos;
	//���������ַ�
	for(pos=0;str[pos+1]!='\0';)
	{
		//�����ǰ�ַ�����һ���ַ���ͬ
		if(str[pos] == str[pos+1])
		{
			flag =1;
			pos++;
		}
	    //�����ǰ�ַ�����һ���ַ���ͬ
		else
		{
			if(flag == 1)
			{
				flag =0;
				pos++;
			}
			else
			{
				index++;
				str[index] = str[pos];
				pos++;
			}
		}
	}
	if(str[pos]!= str[pos-1])
		str[++index] = str[pos];
	str[index+1] = '\0';
}

int main()
{
	char str[]="AAABCCCDFGGIIIKKLMNNOOPQQQQ";
	printf("%s\n",str);
	Remove3(str);
	printf("%s\n",str);
	return 0;
}
