#include <iostream>
#include <vector>
using namespace std;

/*
������������� ʹ�ù鲢�������
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

void FindMid(List*& list,List*& pre,List*& last)
{
	pre = list;
	last = list->next;
	while(last != NULL && last->next !=NULL)
	{
		pre = pre->next;
		last = last->next;
		if(last->next != NULL)
			last = last->next;

	}
	last = pre->next;
	pre->next = NULL;
	pre = list;
}

//�ϲ��������������
void Merge(List*& list,List*& pre,List*& last)
{
	if(pre == NULL)
	{
		list = last;
		return;
	}
	if(last == NULL)
	{
		list =pre;
		return;
	}
	List* cur;
	List* tmp;

	if(pre->value > last->value)
		swap(pre,last);
	//ʼ�ս�Last�����еĽڵ���뵽pre������
	list = pre;
	cur = pre;
	while(cur->next != NULL && last != NULL)
	{
		if(cur->next->value > last->value)//����Ԫ��
		{
			tmp = last->next;
			last->next = cur->next;
			cur->next = last;
			cur = last;
			last = tmp;
		}
		else
			cur =cur->next;
	}
	if(last != NULL)
		 cur->next = last;
}

//����һ��ĺϲ���������αָ��
void Merge_sec(List*& list,List*& pre,List*& last)
{
	List* tmp = new List;
	list = tmp;
	while(pre != NULL && last != NULL)
	{
		if(pre->value < last->value)
		{
			tmp->next = pre;
			pre = pre->next;
		}
		else
		{
			tmp->next = last;
			last = last->next;
		}
		tmp = tmp->next;
	}
	if(last != NULL)
		tmp->next = last;
	else
		tmp->next = pre;
	list = list->next;
}
/*
�鲢���������˼��
*/
void MergeSort(List*& list)
{
	if(list == NULL || list->next == NULL)
		return ;
	//�ҵ��м��
	List* pre = NULL;
	List* last = NULL;
	FindMid(list,pre,last);//��һ������List���м�ֳ�pre��last������

	MergeSort(pre);//�鲢����ʹ��ǰ�벿������
	MergeSort(last);//�鲢����ʹ�ú�벿������
	Merge(list,pre,last);//�������ֵ�����ϲ�
}

/*
�鲢����ڶ���ʵ��
*/

List* Merge(List* first,List* second)
{
	List* head = NULL;
	List* current = NULL;
	if(first == NULL)
		return second;
	if(second == NULL)
		return first;
	if(first->value > second->value)
	{
		current = first;
		first = second;
		second = current;

	}
	head = first;
	current = first;
	first = first->next;
	//ʼ�ս�second�Ľڵ���뵽first������
	while(first != NULL && second != NULL)
	{
		List* temp = NULL;
		if(first->value > second->value)
		{
			temp = second->next;
			current->next = second;
			second->next = first;
			current = second;
			second = temp;
		}
		else
		{
			current = first;
			first = first->next;
		}
	}
	if(first == NULL)
		current->next = second;
	return head;
}

List* MergeSort(List* list,int size)
{
	if(size == 0 | size == 1)
		return list;
	//���м��
	List* middle = list;
	int i;
	for(i =1;i<size/2;i++)
		middle = middle->next;

	List* temp = middle->next;
	middle->next =NULL;
	middle = temp;

	List* left = MergeSort(list,i);
	List* right = MergeSort(middle,size-i);
	return Merge(right,left);
}

int main()
{
	int array[]={7,4,9,15,2,1,6,10,12,11};
	List* head;
	Init_List(head,array,sizeof(array)/sizeof(int));
	head = MergeSort(head,10);
	print_list(head);
	return 0;
}
