#include <iostream>
#include <vector>
using namespace std;
/*
��һ�����������Ч�ز��뵽������������
*/
typedef struct Bin_tree BinTree;
struct Bin_tree
{
	int value;
	BinTree* right;
	BinTree* left;
};

/*�������������BST*/
void InsertFromArray(BinTree*& root,int* array,int start,int end)
{
	if(start >end)
		return ;
	//��ʼ��һ���ڵ�
	root = new BinTree;
	root->left = NULL;
	root->right = NULL;
	//�ҵ�����������м����Ϊ���ڵ�
	int mid = start+(end-start)/2;
	root->value = array[mid];
	//Ȼ��ݹ���ô�����������������
	InsertFromArray(root->left,array,start,mid-1);
	//����������
	InsertFromArray(root->right,array,mid+1,end);
}

/*
�ݹ��������
*/
void Inorder(BinTree* root)
{
	if(root == NULL)
		return;
	Inorder(root->left);
	cout<<root->value<<endl;
	Inorder(root->right);
}

int main()
{
	int array[]={1,2,3,4,5,6,7,8,9};
	BinTree* root = NULL;
	InsertFromArray(root,array,0,8);
	Inorder(root);
	return 0;
}
