#include <iostream>
#include <vector>
using namespace std;

/*
����Ҫ����K��ת
*/
typedef struct list_node List;
struct list_node
{
	int value;
	struct list_node* next;
};

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
��ת����List ʹ���µ�ͷ��ΪHead���µ�β��Ϊtail
*/
void Reverse_list(List*& list,List*& head,List*& tail)
{
	if(list == NULL || list->next == NULL)
		return;
	head = list;
	tail = list;
	List* cur = NULL;
	List* next;
	while(head != NULL)
	{
		next = head->next;
		head->next = cur;
		cur = head;
		head = next;
	}
	list= cur;
	head = cur;
}

/*
��K���ڵ�ķ�ת
*/
void Reverse_k(List*& list,int k)
{
	int num =1;
	int flag =1;
	if(list == NULL ||list->next == NULL || k ==0)
		return ;
	List* head,*tail,*next,*pre;
	head = list;
	tail= list;

	while(tail != NULL && tail->next != NULL)
	{
		tail = tail->next;
		num++;
		if(num == k)
		{
			if(tail != NULL)
			{
				next = tail->next;
				tail->next = NULL;
			}
			else
				next = NULL;
			Reverse_list(head,head,tail);

			if(flag)
			{
				list = head;
				flag =0;
				pre = tail;
			}
			else//�ڶ���֮��ķ�ת
			{
				pre->next = head;
				pre = tail;
			}
			head = next;
			tail = next;
			num =1;
		}
	}
	pre->next = head;
}
List* Reverse(List* pre,List* end)
{
	if(pre == NULL || pre->next == NULL)
		return pre;
	List* head = pre->next;
	List* cur = pre->next->next;
	while(cur != end)
	{
		List* next = cur->next;
		cur->next = pre->next;
		pre->next = cur;
		cur = next;
	}
	head->next = end;
	return head;
}

//��һ�ֱȽϼ򵥵ķ���

List* Reverse_K(List* head,int k)
{
	if(head == NULL)
		return NULL;
	List* dummy = new List;
	dummy->next = head;
	int count =0;
	List* pre = dummy;
	List* cur = head;
	while(cur != NULL)
	{
		count++;
		List* next = cur->next;
		if(count == k)
		{
			pre = Reverse(pre,next);  //�˴��ǿ����䣬����ת�Ǵ�pre��һ���ڵ㵽next��һ���ڵ�
			count =0;
		}
		cur = next;
	}
	return dummy->next;
}
int main()
{
	int array[]={1,2,3,4,5,6,7,8,9,10,11};
	List* list,*head,*tail;
	Init_List(list,array,sizeof(array)/sizeof(int));
	list = Reverse_K(list,3);
	print_list(list);
	return 0;
}
