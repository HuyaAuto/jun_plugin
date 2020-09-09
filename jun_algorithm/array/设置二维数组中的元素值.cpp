#include <iostream>
#include <vector>

using namespace std;

/*
��һ����ά������ ���ĳһ��Ԫ�ص�ֵΪ0 �������ڵ��к�������Ԫ�ض�
��Ϊ0 ������С�Ŀռ临�Ӷ�
*/

void SetZero(vector<vector<int> >& matrix)
{
	bool firstLine = false;
	bool firstRow = false;

	//�жϵ�һ���Ƿ���ֵΪ0 ��Ԫ��
	for(int i=0;i<matrix[0].size();i++)
	{
		if(matrix[0][i] == 0)
		{
			firstLine = true;
			break;
		}
	}

	//�жϵ�һ���Ƿ���0��Ԫ��
	for(int i=0;i<matrix.size();i++)
	{
		if(matrix[i][0] == 0)
		{
			firstRow = true;
			break;
		}
	}

	//�ȴ����һ�к͵�һ��
	for(int i=1;i<matrix.size();i++)
	{
		for(int j=1;j<matrix[0].size();j++)
		{
			if(matrix[i][j] == 0)
			{
				matrix[i][0] =0;
				matrix[0][j] =0;
			}
		}
	}

	//���ݵ�һ�к͵�һ�е�Ԫ�ر��  ��������Ԫ��
	for(int i=1;i<matrix.size();i++)
	{
		for(int j=1;j<matrix[0].size();j++)
		{
			if(matrix[i][0]==0 || matrix[0][j] ==0)
			{
				matrix[i][j] =0;
			}
		}
	}

	//���µ�һ��
	if(firstLine)
	{
		for(int i=0;i<matrix[0].size();i++)
			matrix[0][i] =0;
	}

	//���µ�һ��
	if(firstRow)
	{
		for(int i=0;i<matrix.size();i++)
			matrix[i][0] = 0;
	}
}
