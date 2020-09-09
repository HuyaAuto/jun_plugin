#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
ʵ���ֵ����Ĵ��������롢��ѯ
*/

#define MAX_CHILD 26

typedef struct Tree
{
	int count;//������Ǹýڵ��Ƿ�����γ�һ�����ʣ�count��=0 ˵������
	struct Tree* child[MAX_CHILD];

}Node,*Trie_node;
/*
child�Ǳ�ʾÿ���ж�����������������Сд��ĸ��Ϊ26��
*/

/*
����Trie�ڵ�
*/
Node* CreateTrie()
{
	Node* node = (Node*)malloc(sizeof(Node));
	memset(node,0,sizeof(Node));
	return node;
}

/*
Trie������ڵ�
*/
void Insert_node(Trie_node root,char* str)
{
	if(root == NULL || *str == '\0')
		return ;
	Node* t = root;
	while(*str != '\0')
	{
		if(t->child[*str-'a'] == NULL)
		{
			Node* tmp = CreateTrie();
			t->child[*str-'a'] = tmp;
		}
		t = t->child[*str-'a'];
		str++;
	}
	t->count++;
}

/*
Trie�еĲ���
*/
void search_str(Trie_node root,char* str)
{
	if(NULL == root || *str == '\0')
	{
		printf("tire is empty\n");
		return;
	}
	Node* t = root;
	while(*str != '\0')
	{
		if(t->child[*str-'a'] != NULL)
		{
			t = t->child[*str-'a'];
			str++;
		}
		else
			break;
	}
	if(*str == '\0')
	{
		if(t->count == 0)
			printf("���ַ���������\n");
		else
			printf("���ַ�������\n");
	}
	else
		printf("���ַ���������\n");
}

/*
�ͷ������ֵ����Ŀռ�
*/
void del(Trie_node root)
{
	int i;
	for(i =0;i<MAX_CHILD;i++)
	{
		if(root->child[i] != NULL)
			del(root->child[i]);
	}
	free(root);
}


int main()
{
	int i,n;
	char str[20];
	printf("������Ҫ������trie���Ĵ�С��");
	scanf("%d",&n);
	Trie_node root = NULL;
	root =CreateTrie();
	if(root == NULL)
		printf("����Trie��ʧ��\n");
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		Insert_node(root,str);
	}
	printf("trie���Ѿ�����\n");
	printf("��������Ҫ��ѯ���ַ���\n");
	while(scanf("%s",str)!= NULL)
	{
		search_str(root,str);
	}
	return 0;
}
