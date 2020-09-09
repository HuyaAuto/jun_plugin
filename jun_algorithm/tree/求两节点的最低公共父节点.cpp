
/*
����������������ڵ㣬����������ڵ���������͵Ĺ������ڵ�
*/
/*
�������������ҵ�һ���Ӹ��ڵ㿪ʼ��Ŀ��ڵ��·����Ȼ��
������·���ϲ��ҹ�ͬ�ĸ��ڵ�
*/

/*
�õ��Ӹ���ĳһ�ڵ��·��
*/
bool GetNodePath(BinTree* root,BinTree* node,vector<BinTree*>& path)
{
	if(root == NULL)
		return false;
	if(root == node)
		return true;
	else if(GetNodePath(root->left,node,path))
	{
		path.push_back(root->left);
		return true;
	}
	else if(GetNodePath(root->right,node,path))
	{
		path,push_back(root->right);
		return true;
	}
	return false;
}


BinTree* GetLastNode(vector<BinTree*>& path1,vector<BinTree*>& path2)
{
	vector<BinTree*>::iterator iter1 = path1.begin();
	vector<BinTree*>::iterator iter2 = path2.begin();
	BinTree* plast;
	while(iter1 != path1.end() && iter2 != path2.end())
	{
		if(*iter1 == *iter2)
			plast = *iter1;
		else
			break;
		iter1++;
		iter2++;
	}
	return plast;
}

BinTree* GetParent(BinTree* root,BinTree* node1,BinTree* node2)
{
	if(root == NULL || node1 == NULL || node2 == NULL)
		return NULL;
	vector<BinTree*> path1;
	GetNodePath(root,node1,path1);

	vector<BinTree*> path2;
	GetNodePath(root,node2,path2);
	return GetLastNode(path1,path2);
}

/*
�ڶ��ַ���
��ͷ��ʼ������һ�������нڵ�������ڵ��е�һ����ȣ���ô�νڵ����Ŀ��
�ڵ㣬Ҫô�������ڵ�����������Ҫô����������
������������ڵ�һ������������һ��������������ô��ǰ�ڵ���ǹ������ڵ�
������ֶ�������������ô�������ڵ������������
������ֶ�������������ô�������ڵ���������
*/
bool FindNode(BinTree* root,BinTree* node)
{
	if(root == NULL)
		return false;
	if(root == node)
		return true;
	return (FindNode(root->left,node) || FindNode(root->right,node));
}

BinTree* LCP(BinTree* root,BinTree* first,BinTree* second)
{
	if(root == first || root== second)
		return root;
	bool isLeft = false;
	isLeft = FindNode(root->left,first);
	if(isLeft)
	{
		if(FindNode(root->left,second))
			return LCP(root->left,first,second);
		else
			return root;
	}
	else
	{
		if(FindNode(root->right,second))
			return LCP(root->right,first,second);
		else
			return root;
	}
}

/*
��һ�ּ���
��������������ҵ��˽ڵ㣬left != NULL,��ô��һ��right�Ƿ�ΪNULL
���right != NULL ,��ô˵���������������ж����ҵ��˹������ڵ�
��ô˵����͵Ĺ������ڵ���ǵ�ǰ�Ľڵ�
*/

BinTree* LCP2(BinTree8 root,BinTree* first,BinTree* second)
{
	if(root == first || root== second)
		return root;
	if(root == NULL)
		return NULL;
	BinTree* left = LCP2(root->left,first,second);
	BinTree* right = LCP2(root->right,first,second);
	if(left == NULL)
		return right;
	else if(right == NULL)
		return left;
	else
		return root;
}
