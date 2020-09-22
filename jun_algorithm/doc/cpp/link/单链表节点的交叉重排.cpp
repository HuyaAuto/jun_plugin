#include <iostream>
#include <vector>
using namespace std;

/*
����Ҫ������Ϊ����������
*/

typedef struct list_node List;
struct list_node
{
	struct list_node* next;
	int value;
};

void print_list(List* list)
{
	List* tmp=list;
	while(tmp != NULL)
	{
		cout<<tmp->value<<endl;
		tmp = tmp->next;
	}
}

/*
��ʼ��List  ����1~n�����ֲ��뵽������
*/
void Init_List(List*& head,int* array,int n)
{
	head = NULL;
	List* tmp;
	List* record;

	for(int i=1;i<=n;i++)
	{
		tmp = new List;
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

//��������
int Len_list(List* list)
{
	if(list == NULL)
		return 0;
	else
		return Len_list(list->next)+1;
}

/*
����ķ�ת
*/
void Reverse(List*& list)
{
	List* tmp = NULL;
	List* cur = list;
	List* next = list->next;
	while(next != NULL)
	{
		cur->next = tmp;
		tmp = cur;
		cur = next;
		next = next->next;
	}
	cur->next  = tmp;
	list = cur;
}

/*
��������������һ�������֣�Ȼ���������
�ؼ����������������ż����������
*/

void Reorder_list(List*& list)
{
	List* first = list;
	List* second;
	List* tmp_first,*tmp_second;
	//��Ҫ���������нڵ�ĸ������ָ�����
	int len = Len_list(first);
	int i;
	if(len%2 == 0)
	{
		for(i=1;i<len/2;i++)
			first = first->next;
	}
	else
	{
		for(i=1;i<len/2+1;i++)
			first = first->next;
	}
	second = first->next;
	first->next = NULL;
	//�������������з�ת
	Reverse(second);

	//���¹滮����
	first = list;
	//��ʼ���кϲ���ͬʱsecond����ĸ����϶������first����Ľڵ�����
	while(second != NULL)
	{
		tmp_first = first->next;
		tmp_second = second->next;
		first->next= second;
		second->next = tmp_first;
		second = tmp_second;
		first = tmp_first;
	} //�ܷ�ʹ��αָ�뽫����������
}

int main()
{
	int array[]={1,2,3,4,5,6,7,8,9,10,11};
	List* head;
	Init_List(head,array,sizeof(array)/sizeof(int));

	Reorder_list(head);
	print_list(head);
	return 0;
}
