#include <iostream>
#include <vector>
using namespace std;

/*
�ϲ�K���Ѿ�����õ�����
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
���������ںϲ������Ѿ�����õ���������˼�룬���������С�ѣ�ÿ�ν��Ѷ�Ԫ��
�����µ������У�����Ҳ����ʹ�����������б�ǣ�ÿ�δ���������ѡ��С�Ľڵ�
ֱ����������Ľڵ㶼��ѡ��
*/

List* Merge_k(vector<List*>& vec)
{
	int i;
	//ʹ��������б��
	vector<int> flag(vec.size(),1); //�������flag��ʼ��ֵΪ1
	List* head = NULL;
	List* cur = NULL;
	List* tmp = NULL; //��¼��ǰ��ʱ��Сֵ
	int pos;//��ǰ��ʱ��Сֵ�ڵڼ���������

	//��ʼ����K������
	while(1)
	{
		tmp = NULL;
		//��ʼ����������飬�ҵ����ʵĽڵ�
		for(i =0;i<vec.size();i++)
		{
			if(vec[i] == NULL)
				flag[i] = 0;
			if(flag[i])
			{
				if(tmp ==NULL)
				{
					tmp = vec[i];
					pos =i;
				}
				if(tmp && tmp->value > vec[i]->value)
				{
					tmp = vec[i];
					pos =i;
				}
			}
		}
		//��ʼ���⴦��ͷ�ڵ�
		if(head == NULL)
		{
			head = tmp;
			cur = head;
		}
		else
		{
			cur->next = tmp;
			cur= cur->next;
		}

		//����ѡ�е�������������Ҫɾ���ղŵ�Ԫ��
		vec[pos] = vec[pos]->next;
		if(vec[pos] == NULL)
			flag[pos] =0;

		//�ж��Ƿ����еĽڵ㶼�Ѿ���ѡ��
		for(i=0;i<flag.size();i++)
		{
			if(flag[i])
				break;
		}
		if(i>=flag.size())
			break;
	}
	return head;

}


int main()
{
	int array1[]={1,4,7,8,13,19};
	int array2[]={5,8,9,10,12,15,17,22,23};
	int array3[]={3,6,11,16,17,18,21,24};
	int array4[]={2,14,20,25};
	vector<List*> vec(4);
	int i;

	Init_List(vec[0],array1,sizeof(array1)/sizeof(int));
	Init_List(vec[1],array2,sizeof(array2)/sizeof(int));
	Init_List(vec[2],array3,sizeof(array3)/sizeof(int));
	Init_List(vec[3],array4,sizeof(array4)/sizeof(int));

	List* head = Merge_k(vec);
	print_list(head);
	return 0;
}
