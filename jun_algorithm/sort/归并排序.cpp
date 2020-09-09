#include <stdio.h>
#include <stdlib.h>

//�ϲ���������������
void Mergearray(int* a,int left,int mid,int right,int* temp)
{
	int i = left,j = mid+1;
	int m = mid,n = right;
	int k=0;
	//��·�鲢
	while(i<=m && j<=n)
	{
		if(a[i]<=a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	//������������ʣ���Ԫ��
	while(i<=m)
		temp[k++] = a[i++];
	while(j<=n)
		temp[k++] = a[j++];

	//����ʱ�����п�����Ŀ������
	for(i=0;i<k;i++)
		a[left+i] = temp[i];
}

//�鲢����ĺ��Ĺ���
int MergeSort(int* a,int left,int right,int* temp)
{
	if(left < right)
	{
		int mid = left + (right-left)/2;

		//�鲢���� ʹ�������������
		MergeSort(a,left,mid,temp);
		//�鲢���� ʹ���ұ���������
		MergeSort(a,mid+1,right,temp);

		//�ϲ�������������
		Mergearray(a,left,mid,right,temp);
	}
}

int main()
{
	int array[]={6,3,2,1,4,10,9,8,7,5};
	int b[10];
	MergeSort(array,0,9,b);
	int i;
	for(i=0;i<10;i++)
		printf("%d\n",array[i]);
	return 0;
}

