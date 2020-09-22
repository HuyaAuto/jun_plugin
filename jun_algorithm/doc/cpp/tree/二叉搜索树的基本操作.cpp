#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <queue>
using namespace std;

/*
�����������Ļ�������
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


/**
���Ҷ��������������ֵ
*/

BinTree* Max(BinTree* root)
{
	if(root == NULL)
		return NULL;
	BinTree* temp = root;
	while(temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}

/*
���Ҷ�������������Сֵ
*/
BinTree* Min(BinTree* root)
{
	if(root == NULL)
		return NULL;
	BinTree* temp = root;
	while(temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp;
}

/*
�ڶ����������в���Ԫ��
*/
BinTree* Search(BinTree* root,BinTree*& parent,int value)
{
	if(root == NULL )
		return NULL;
	BinTree* temp = root;
	parent = NULL;
	while(temp != NULL)
	{
		if(temp->value == value)
			break;
		else
		{
			parent = temp;
			if(temp->value > value)
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	if(temp == NULL)
	{
		parent = NULL;
		return NULL;
	}
	return temp;
}


/*
ɾ�������������ֵ�ĳ���ڵ�
*/
void Delete(BinTree*& root,int value)
{
	BinTree* delnode = NULL;
	if(root == NULL)
		return ;
	BinTree* temp = root;
	BinTree* parent = NULL;
	//������Ҫ���Ҹ�Ԫ���Ƿ����
	while(temp != NULL)
	{
		if(temp->value == value)
			break;
		else
		{
			parent = temp;
			if(temp->value > value)
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	//���û���ҵ���ɾ���Ľڵ㣬��ôֱ�ӷ���
	if(temp == NULL)
		return ;
	delnode = temp;
	/*
	ɾ���Ľڵ㱻�ҵ�������������ɾ���Ĳ�������Ϊ���������
	��һ������Ǵ�ɾ���ڵ�û�к��ӣ���ôֱ��ɾ��
	�ڶ�������Ǵ�ɾ���ڵ���һ�����ӣ��п���������Ҳ�п������Һ��ӣ�
	����������Ǵ�ɾ���ڵ�����������
	*/
	/*
	��һ�������ֱ��ɾ���˽ڵ�
	*/
	if(delnode->right == NULL && delnode->left == NULL)
	{
		if(delnode == root)
		{
			root = NULL;
		}
		if(parent && parent->left == delnode)
		{
			parent->left = NULL;
		}
		if(parent && parent->right == delnode)
		{
			parent->right = NULL;
		}
		delete delnode;
	}
	//����˽ڵ���һ������
	if(delnode->right != NULL && delnode->left == NULL)
	{
		if(parent != NULL)
		{
			if(parent->left == delnode)
				parent->left = delnode->right;
			else if(parent->right == delnode)
				parent->right = delnode->right;
		}
		else
		{
			root = delnode->right;
		}
		delete delnode;
	}
	if(delnode->left != NULL && delnode->right == NULL)
	{
		if(parent != NULL)
		{
			if(parent->left == delnode)
				parent->left = delnode->left;
			else if(parent->right == delnode)
				parent->right = delnode->left;
		}
		else
		{
			root = delnode->left;
		}
		delete delnode;
	}
	//�����ڵ㶼��Ϊ�� ��һ�����ʵ�ֵ���
	if(delnode->left != NULL && delnode->right != NULL)
	{
		temp = delnode->right;
		parent = delnode;
		while(temp->left != NULL)
		{
			parent = temp;
			temp = temp->left;
		}
		delnode->value = temp->value;
		parent->left = temp->right;
		delete temp;
	}
}

int main()
{
	int array[]={30,22,45,15,24,40,50,10};
	BinTree* root = NULL;
	for(int i=0;i<sizeof(array)/sizeof(int);i++)
		root = InsertNode(root,array[i]);
	Delete(root,30);
	return 0;
}
