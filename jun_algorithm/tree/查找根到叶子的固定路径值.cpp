#include <iostream>
#include <stack>
#include <vector>
#include <deque>
using namespace std;

/*
����Ҷ��·��֮��Ϊָ��ֵ
*/

using namespace std;
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

//����Ҷ��·����Ϊĳһ��ֵ
void helper(BinTree* root,int key,int cur,vector<int>& vec)
{
	if(root == NULL)
		return ;
	cur+=root->value;
	vec.push_back(root->value);
	if(root->left == NULL && root->right == NULL && cur == key)
	{
		int i;
		for(i=0;i<vec.size();i++)
			cout<<vec[i]<<"  ";
		cout<<endl;

	}
	if(root->left !=NULL)
	{
		helper(root->left,key,cur,vec);
		vec.pop_back();
	}

	if(root->right !=NULL)
	{
		helper(root->right,key,cur,vec);
		vec.pop_back();
	}
}

void PathSum(BinTree* root,int key)
{
	int cur=0;
	if(root== NULL)
		return ;
	vector<int> vec;
	helper(root,key,cur,vec);

}
//�ڶ��ַ���
bool PathSum_second(BinTree* root,int value)
{
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL &&root->value == value)
		return 1;
	return PathSum_second(root->left,value-root->value)||PathSum_second(root->right,value-root->value);
}

/*
�Ӹ���Ҷ������·���У�·��������ֵ
*/
void helper_sum(BinTree* root,vector<int>& path,int& maxsum)
{
	if(root == NULL)
		return;
	path.push_back(root->value);
	if(root->left == NULL && root->right == NULL)
	{
		int tmp =0;
		for(int i=0;i<path.size();i++)
		{
			tmp += path[i];
			cout<<path[i]<<" ";
		}
		cout<<endl;
		maxsum = max(tmp,maxsum);
	}
	helper_sum(root->left,path,maxsum);
	helper_sum(root->right,path,maxsum);
	path.pop_back();
}

int MaxPathToLeaf(BinTree* root)
{
	if(root ==NULL)
		return 0;
	vector<int> path;
	int maxsum =0;
	helper_sum(root,path,maxsum);
	return maxsum;
}


int main()
{
	BinTree* root = NULL;
	BinTree* second = NULL;
	int array[]={10,6,14,3,16,5,8};
	int i;
	for(i=0;i<sizeof(array)/sizeof(int);i++)
		root = InsertNode(root,array[i]);
	PathSum(root,24);
	return 0;
}
