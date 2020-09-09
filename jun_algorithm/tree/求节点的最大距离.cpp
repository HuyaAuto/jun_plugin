#include <iostream>
#include <stack>
using namespace std;

/*
��������нڵ��������
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
  �ݹ� ǰ�����������
*/
void Preorder(BinTree* root)
{
     if(root == NULL)
       return ;
     cout<<root->value <<endl;
     Preorder(root->left);
     Preorder(root->right);
}

/*
  �ݹ� �������������
*/
void Inorder(BinTree* root)
{
     if(root == NULL)
       return ;
     Inorder(root->left);
     cout<<root->value<<endl;
     Inorder(root->right);
}

/*
�����������������ڵ����Զ���룬����ľ�����Ǳߵĸ���
*/
/*
��������ۣ�
��Զ�������ڵ�һ������������һ��������������ô��������������Զ�ڵ�
����ǰ�ڵ�ľ����������������Զ�ڵ㵽��ǰ�ڵ�ľ��룬���������Զ
�����Խ�˸��ڵ㡣
�ڶ������������Զ����������ڵ㶼��������
���������������Զ����������ڵ㶼��������
*/

/*
distance����rootΪ�����������
����ֵ������rootΪ�������������������Զ����
*/
int Distance(BinTree* root,int& depth)
{
	if(root == NULL)
	{
		depth = 0;
		return 0;
	}
	int left,right;
	int left_dis = Distance(root->left,left);
	int right_dis = Distance(root->right,right);
	depth = (left > right ? left: right)+1;

	return max(left_dis,max(right_dis,left+right));
}

/*
���������Ϊ�գ���ȶ�Ϊ0
�����Ϊ�գ�������Ҫô���������������룬Ҫô��������
�������룬Ҫô�������������ڵ��������+�������ڵ��е����ڵ�
������
*/

int MaxDepth(BinTree* root)
{
	int depth =0;
	if(root != NULL)
	{
		int left_depth = MaxDepth(root->left);
		int right_depth = MaxDepth(root->right);
		depth = (left_depth > right_depth? left_depth: right_depth);
		depth++;
	}
	return depth;
}

int MaxDistance(BinTree* root)
{
	int maxdis = 0;
	if(root != NULL)
	{
		maxdis = MaxDepth(root->right) + MaxDepth(root->left);
		int left_dis = MaxDistance(root->left);
		int right_dis = MaxDistance(root->right);
		int temp = left_dis > right_dis? left_dis : right_dis;
		maxdis = temp > maxdis ? temp:maxdis;
	}
	return maxdis;
}


int GetMaxDistance(BinTree* root,int& maxLeft,int& maxRight)
{
	//maxLeft���������еĽڵ���뵱ǰ���ڵ����Զ����
	//maxRight �������еĽڵ���뵱ǰ���ڵ����Զ����
	if(root == NULL)
	{
		maxLeft  =0;
		maxRight = 0;
		return 0;
	}
	int maxLL,maxLR,maxRL,maxRR;
	int maxDisLeft,maxDisRight;
	if(root->left != NULL)
	{
		maxDisLeft = GetMaxDistance(root->left,maxLL,maxLR);
		maxLeft = max(maxLL,maxLR)+1;
	}
	else
	{
		maxDisLeft = 0;
		maxLeft = 0;
	}
	if(root->right != NULL)
	{
		maxDisRight = GetMaxDistance(root->right,maxRL,maxRR);
		maxRight = max(maxRL,maxRR)+1;
	}
	else
	{
		maxDisRight = 0;
		maxRight = 0;
	}
	return max(max(maxDisLeft,maxDisRight),maxLeft+maxRight);
}

int main()
{

	BinTree* root = NULL;
	int array[]={10,6,14,4,8,12,16,5};
	int i;
	for(i=0;i<sizeof(array)/sizeof(int);i++)
		root = InsertNode(root,array[i]);
	int dis=0;
	cout<<Distance(root,dis)<<endl;
	int right = 0;
	int left = 0;
	cout<<MaxDistance(root)<<endl;
	cout<<GetMaxDistance(root,left,right)<<endl;
	return 0;
}
