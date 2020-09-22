#include <iostream>
#include <stack>
#include <vector>
#include <deque>
using namespace std;

/*
�����������Ĵ���
�������ĵݹ����
�������ķǵݹ����
*/
typedef struct Bin_Tree BinTree;
struct Bin_Tree
{
	int value;
	BinTree* right;
	BinTree* left;
};

/*
�������������
*/
BinTree* InsertNode(BinTree* root,int value)
{
	BinTree* newnode = new BinTree;
	newnode->value = value;
	newnode->right = NULL;
	newnode->left = NULL;
	//������һ���µĽڵ㣬��Ҫ���˽ڵ���뵽���ʵ�λ��
	if(root == NULL)
	{
		root = newnode;
	}
	else
	{
		//�Һ��ʵ�λ��
		BinTree* parent = root;
		while(parent != NULL)
		{
			if(parent->value < value)
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
		if(parent->value < value)
			parent->right = newnode;
		else
			parent->left = newnode;
	}
	return root;
}

/*
�ݹ�ķ���ǰ�����������
*/
void Preorder(BinTree* root)
{
	if(root == NULL)
		return ;
	cout<<root->value<<endl;
	Preorder(root->left);
	Preorder(root->right);
}

/*
�ݹ�ķ����������������
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
�ݹ�ķ����������������
*/
void Postorder(BinTree* root)
{
	if(root == NULL)
		return ;
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->value<<endl;
}

/*�ǵݹ�ı���������*/

/*
�ǵݹ��ǰ�����
*/
void Preorder_Nonrecursive(BinTree* root)
{
	if(root == NULL)
		return ;
	stack<BinTree*> s;
	s.push(root);
	while(!s.empty())
	{
		BinTree* temp = s.top();
		cout<<temp->value<<" ";
		s.pop();
		if(temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);
	}
}


/*�ڶ��ַ���*/

void Preorder_Nonrecursive1(BinTree* root)
{
	if(root == NULL)
		return ;
	stack<BinTree*> s;
	BinTree* cur = root;
	while(cur != NULL || !s.empty())
	{
		while(cur != NULL)
		{
			cout<<cur->value<<" ";
			s.push(cur);
			cur = cur->left;
		}
		if(!s.empty())
		{
			cur = s.top();
			s.pop();
			cur = cur->right;
		}
	}
}

/*�ǵݹ��������*/
void Inorder_Nonre(BinTree* root)
{
	if(root == NULL)
		return ;
	BinTree* cur = root;
	stack<BinTree*> s;
	while(cur != NULL || !s.empty())
	{
		while(cur != NULL)
		{
			s.push(cur);
			cur = cur->left;
		}
		if(!s.empty())
		{
			cur = s.top();
			s.pop();
			cout<<cur->value<<" ";
			cur = cur->right;
		}
	}
}

/*
�ڶ��ַ���
*/
void  Inorder_Nonre2(BinTree* root)
{
	if(root == NULL)
		return ;
	stack<BinTree*> st;
	BinTree* p = root;
	while(p!= NULL || !st.empty())
	{
		if(p != NULL)
		{
			st.push(p);
			p = p->left;
		}
		else
		{
			p=st.top();
			st.pop();
			cout<<p->value<<endl;
			p = p->right;
		}
	}
}

/*
�ǵݹ�ĺ������
*/
void Postorder_Nonre(BinTree* root)
{
	stack<BinTree*> s;
	BinTree* cur = root;
	BinTree* pre = NULL;//ָ��ǰһ�������ʵĽڵ�
	while(cur != NULL || !s.empty())
	{
		while( cur != NULL) //һֱ������ֱ��Ϊ��
		{
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		//��ǰ�ڵ���Һ������Ϊ�ջ����Ѿ������ʣ�����ʵ�ǰ�ڵ�
		if(cur->right == NULL || cur->right == pre)
		{
			cout<<cur->value<<" ";
			pre = cur;
			s.pop();
			cur = NULL;
		}
		else
			cur = cur->right;//��������Һ���
	}
}

/*
�ڶ��ַ���
*/
void Postorder_Nonre2(BinTree* root)
{
	//ʹ��˫ջ��
	stack<BinTree*> s1,s2;
	BinTree* cur;//ָ��ǰҪ���Ľڵ�
	s1.push(root);
	//ջΪ��ʱ����
	while(!s1.empty())
	{
		cur = s1.top();
		s1.pop();
		s2.push(cur);
		if(cur->left)
			s1.push(cur->left);
		if(cur->right)
			s1.push(cur->right);
	}
	while(!s2.empty())
	{
		cout<<s2.top()->value<<" ";
		s2.pop();
	}
}

int main()
{
	BinTree* root =NULL;
	int array[]={10,6,14,4,8,12,16};
	for(int i=0;i<sizeof(array)/sizeof(int);i++)
		root = InsertNode(root,array[i]);
	Inorder_Nonre2(root);
	return 0;
}
