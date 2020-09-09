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

//���ҵ������е�����K���ڵ�
ListNode* GetKthNode(ListNode* phead,int k)
{
	//����K�ļ����Ǵ�1��ʼ
	if(k == 0 || phead == NULL)
		return NULL;

	ListNode* pAhead = phead;
	ListNode* pBehind = phead;
	//ǰ���ָ�����ߵ������K���ڵ�
	while(k>1 && pAhead != NULL)
	{
		pAhead = pAhead->next;
		k--;
	}
	//�ڵ����С��K��ֱ�ӷ���NULL
	if(k>1 || pAhead == NULL)
		return NULL;
	//ǰ������ָ��һ����ǰ�ߣ�ֱ��ǰ���ָ��ָ�����һ���ڵ�
	while(pAhead->next != NULL)
	{
		pBehind = pBehind->next;
		pAhead = pAhead->next;
	}
	return pBehind;//�����ָ����ָ��Ľڵ���ǵ�����K���ڵ�
}

//��β��ͷ��ӡ����ʹ�õݹ�ķ���
void RPrintList(ListNode* phead)
{
	if(phead == NULL)
		return ;
	else
	{
		RPrintList(phead->next);
		cout<<phead->value<<endl;
	}
}

//�жϵ��������Ƿ��л�
bool HasCircle(ListNode* phead)
{
	ListNode* pfast = phead;//��ָ��ÿ��ǰ������
	ListNode* pslow = phead;//��ָ��ÿ��ǰ��һ��
	while(pfast!=NULL&& pfast->next != NULL)
	{
		pfast = pfast->next->next;
		pslow = pslow->next;
		if(pslow == pfast)
			return true;
	}
	return false;
}

/*
����һ������ͷָ��phead��һ����ɾ���Ľڵ�ָ�룬
��O(1)ʱ�临�Ӷ���ɾ���˽ڵ�
*/
void Delete(ListNode* phead,ListNode* tobedelete)
 {
 	if(tobedelete == NULL || phead == NULL)
 		return;
 	ListNode* temp = phead;

 	//����һ���ڵ�����ݸ��Ƶ����ڵ㣬Ȼ��ɾ����һ���ڵ�
	if(tobedelete->next != NULL)
	{
		tobedelete->value = tobedelete->next->value;
		ListNode* temp = tobedelete->next;
		tobedelete->next = tobedelete->next->next;
		delete temp;
	}
	else //Ҫɾ���������һ���ڵ�
	{
		if(phead == tobedelete)//������ֻ��һ���ڵ�����
		{
			phead = NULL;
			delete tobedelete;

		}
		else
		{
			ListNode* pnode = phead;
			while(pnode->next != tobedelete)//�ҵ������ڶ����ڵ�
				pnode =pnode->next;
			pnode->next = NULL;
			delete tobedelete;
		}
	}
 }

int main()
{
	int array[]={1,2,3,4,5,6,7,8,9,10};
	ListNode* list;
	Init_List(list,array,sizeof(array)/sizeof(int));
//	print_list(list);
	Delete(list,list->next->next->next);
	print_list(list);
	return 0;
}
