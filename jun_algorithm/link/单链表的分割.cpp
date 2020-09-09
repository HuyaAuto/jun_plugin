#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
˼·�������ڿ��ţ�����Ҫ�󲻸ı�ԭ�������˳�����Ա����нڵ�Ľ���
Ҫ��Ȼ֮�佻���ڵ��ڲ���ֵ���ɡ�
*/

/*
�����ڿ�������ķָ�
*/

void PartitionList(List*& list,int key)
{
	if(list == NULL)
		return ;
	List* record,*cur,*pre,*tmp;
	record = NULL;
	cur = list;
	pre = NULL;
	//��ʼ��������
	while(cur != NULL)
	{
		if(cur->value< key) //���뵽pre֮����Ҫ���⴦��ͷ�ڵ�
		{
			tmp = cur->next;
			if(pre == NULL)
				pre = cur;
			if(record ==NULL)
			{
				record = list;
				list = cur;
				cur->next = record;
				record = cur;
				pre->next = tmp;
			}
			else
			{
				if(pre != record)
				{
					cur->next = record->next;
					record->next = cur;
					pre->next = tmp;
					record = cur;
				}
				else
				{
					record = pre= cur;
				}
			}

			cur = tmp;
		}
		else
		{
			pre= cur;
			cur = cur->next;
		}
	}
}

//�ڶ��ַ��� ʹ��αָ��
List* PartitionList2(List* list,int key)
{
	List* head = new List;
	head->next = list;
	List* temp = head;
	List* pre = head,*cur = list,*next;

	//��ʼ����
	while(cur != NULL)
	{
		next = cur->next;
		if(cur->value < key)
		{
			pre->next = next;
			cur->next = temp->next;
			temp->next = cur;
			temp = cur;
			cur = next;
		}
		else
		{
			pre = cur;
			cur = next;
		}
	}
	return head->next;
}

int main()
{
	int array[]={5,1,2,7,8,4,3,6,10,9};
	List* list;
	Init_List(list,array,sizeof(array)/sizeof(int));
	list = PartitionList2(list,5);
	print_list(list);
	return 0;
}
