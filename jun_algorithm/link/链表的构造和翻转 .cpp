#include <iostream>
using namespace std;

typedef struct list_node ListNode;

struct list_node
{
	struct list_node* next;
	int value;
};

/*
��ʼ��List ����1~n�����ֲ��뵽������
*/
void Init_List(ListNode*& head,int* array,int n)
{
	head = NULL;
	ListNode* tmp;
	ListNode* record;

	for(int i=1;i<=n;i++)
	{
		tmp = new ListNode;
		tmp->next = NULL;
		tmp->value = array[i-1];
		if(head == NULL)
		{
			head = tmp;
			record = head;
		}
		else
		{
			record->next = tmp;
			record = tmp;
		}
	}
}

void print_list(ListNode* list)
{
	ListNode* tmp = list;
	while(tmp != NULL)
	{
		cout<<tmp->value<<endl;
		tmp = tmp->next;
	}
}

//�������нڵ�ĸ���
int GetListLength(ListNode* phead)
{
	if(phead == NULL)
		return 0;
	int length = 0;
	ListNode* current = phead;
	while(current != NULL)
	{
		length++;
		current = current->next;
	}
	return length;
}

//�ݹ�ķ����������ĳ���
int Len_list(ListNode* list)
{
	if(list == NULL)
		return 0;
	else
		return Len_list(list->next)+1;
}


//��ת������
ListNode* ReverseList(ListNode* phead)
{
	//���������Ϊ�ջ���ֻ��һ���ڵ㣬���跭ת��ֱ�ӷ���ͷ�ڵ�
	if(phead == NULL | phead->next == NULL)
		return phead;
	ListNode* preverse = NULL;//��ת���������ͷָ�룬��ʼ��ΪNULL
	ListNode* current = phead;
	while(current != NULL)
	{
		ListNode* temp = current;
		current = current->next;
		temp->next = preverse;//����ǰ�ڵ��¼���������������ǰ��
		preverse = temp;
	}
	return preverse;
}
int main()
{
	int array[]={1,2,3,4,5,6,7,8,9,10};
	ListNode* list;
	Init_List(list,array,sizeof(array)/sizeof(int));
	print_list(list);
	list = ReverseList(list);
	print_list(list);

	return 0;
}
