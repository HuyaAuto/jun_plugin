#include <stdio.h>
#include <stdlib.h>


//1���ݹ�ķ�ʽ���ַ�������
int RecurLength(char* str)
{
	if(str[0] == '\0')
		return 0;
	else
		return RecurLength(str+1)+1;
}

//2�����ַ��������һ�����ʵĳ���(��֪�ַ����ĳ���)
int LastWordLen(char* str,int len)
{
	int lastlen = 0;
	int index = len-1;
	while(index>=0 && str[index--] != ' ')
		lastlen++;
	return lastlen;
}

//2�����ַ��������һ�����ʵĳ���(δ֪�ַ����ĳ���)
int LastWordLen2(char* str)
{
	int lastlen = 0;
	int index =0;
	while(str[index] !='\0')
	{
		if(str[index]==' ')
		  lastlen =0;
		else
		  lastlen++;
		index++;
	}
	return lastlen;
}


//�ַ����ڴ�Ŀ��� ʵ��memmove����(�޸��ǿ���)
char* my_memmove(char* dst,char* src,int count)
{
	char* ret = dst;
	if(dst == NULL || src == NULL)
		return NULL;
	//���dst��src����û���ص�����ô�ӿ�ʼ����һ����
	if(dst <= src || dst >= (src+count))
	{
		while(count--)
		{
			*dst = *src;
			dst++;
			src++;
		}
	}
	//���dst��src�����н��棬��ô��β����ʼ����ʼλ�ÿ������������Ա��������ص�
	else
	{
		dst = dst + count-1;
		src = src + count-1;
		while(count--)
		{
			*dst = *src;
			dst--;
			src--;
		}
	}
	return ret;
}
int main()
{
	char str[]="Hello dunso";
	printf("str len is %d\r\n",RecurLength(str));
	printf("lastword len is %d\r\n",LastWordLen(str,12));
	printf("lastword len is %d\r\n",LastWordLen2(str));
	return 0;
}
