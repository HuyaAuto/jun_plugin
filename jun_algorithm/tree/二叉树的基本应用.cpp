#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

/*
�������Ļ�������
*/

typedef struct Bin_tree BinTree;
struct Bin_tree
{
       int value;
       BinTree* right;
       BinTree* left;
};
/*
  ������������
*/
BinTree* InsertNode(BinTree* root,int data)
{
         BinTree* newnode = new BinTree;
         newnode->value = data;
         newnode->right = NULL;
         newnode->left = NULL;
         if(root == NULL)
         {
                 root = newnode;
                 }
         else
         {
             BinTree* parent = root;
        //     BinTree* cur = NULL;
             while(parent != NULL)
             {
                     if(parent->value < data)
                     {
                        if(parent->right == NULL)
                          break;
                        else
                          parent = parent->right;
                     }
                     else
                     {
                         if(parent->left == NULL)
                           break;
                         else
                           parent = parent->left;
                     }
             }
             if(parent->value < data)
              parent->right = newnode;
             else
              parent->left = newnode;
             }
         return root;
}

/*
��α��������� ʹ�ö��л���˫�˶���
*/

void FloorVisit(BinTree* root)
{
	if(root == NULL)
		return ;
	deque<BinTree*> dequ;
	dequ.push_back(root);
	BinTree* current = NULL;
	//��ʼ����
	while(dequ.size())
	{
		current = dequ.front();
		dequ.pop_front();
		cout<<current->value<<endl;
		if(current->left != NULL)
			dequ.push_back(current->left);
		if(current->right != NULL)
			dequ.push_back(current->right);
	}
}

/*
�������нڵ�ĸ���
*/
int NumOfTree(BinTree* root)
{
	if(root == NULL)
		return 0;
	return (NumOfTree(root->right)+NumOfTree(root->left)) +1;
}

/*
�����������
*/

int Depth(BinTree* root)
{
	if(root == NULL)
		return 0;
	int left = Depth(root->left);
	int right = Depth(root->right);
	return (left > right ? left:right)+1;
}

/*
�������Ŀ�� ���������Ŀ�Ⱦ��ǽڵ������ǲ��нڵ�ĸ�����
*/
void Width(BinTree* root,int& width)
{
	if(root == NULL)
		return;
	deque< BinTree*> dequ;
	dequ.push_back(root);
	BinTree* current;
	width =0;
	int tempWidth= dequ.size();
	//��ʼ���ҿ��
	while(tempWidth)
	{
		if(tempWidth > width)
			width = tempWidth;
		while(tempWidth)
		{
			current = dequ.front();
			dequ.pop_front();
			if(current->left != NULL)
				dequ.push_back(current->left);
			if(current->right != NULL)
				dequ.push_back(current->right);
			tempWidth--;
		}
		tempWidth = dequ.size();
	}
}

/*
�������и���Ҷ�ӽڵ��·��
*/
void Routh(BinTree* root,vector<BinTree*>& vec)
{
	if(root == NULL)
		return ;
	vec.push_back(root);
	if(root->left == NULL && root->right == NULL)
	{
		vector<BinTree*>::iterator itr = vec.begin();
		for(;itr!=vec.end();itr++)
		{
			cout<<(*itr)->value<<endl;
		}
		cout<<"-----"<<endl;
	}
	Routh(root->left,vec);
	Routh(root->right,vec);
	vec.pop_back();
}

/*
�ж����ö������Ƿ�ṹ��ͬ
*/
bool JudeSame(BinTree* first,BinTree* second)
{
	if(first == NULL && second == NULL)
		return true;
	if((first == NULL && second!=NULL) || (first != NULL && second == NULL))
		return false;
	if(first->value != second->value)
		return false;
	return (JudeSame(first->left,second->left)&&(JudeSame(first->right,second->right)));

}

/*
�������ľ���ת��
*/
void Reverse(BinTree* root)
{
	if(root == NULL)
		return;
	BinTree* temp = NULL;
	temp = root->right;
	root->right = root->left;
	root->left = temp;
	//�ݹ���ú�����ʹ����������������ת��
	Reverse(root->left);
	Reverse(root->right);
}

int main()
{
	int array[]={30,22,45,15,24,40,50,10};
	BinTree* root = NULL;
	for(int i=0;i<sizeof(array)/sizeof(int);i++)
		root = InsertNode(root,array[i]);
	//FloorVisit(root);
	vector<BinTree*> vec;
	Routh(root,vec);
	return 0;
}
