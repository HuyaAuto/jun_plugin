#include <stdio.h>
#include <stdlib.h>

//��һ��������ĳһ����׼�㻮��Ϊ����������
int Partition(int* array,int left,int right)
{
	int key = array[right];//�����һ��Ԫ��Ϊ��׼��
	int i = left-1;
	int temp;

	//��ʼ�Ի�׼��Ϊ��׼�ָ�����
	for(int j = left;j<right;j++)
	{
		if(array[j] < key)
		{
			i++;

			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}
	//����׼����õ����ʵ�λ����
	temp = array[i+1];
	array[i+1] = array[right];
	array[right] = temp;
	return i+1;
}

//��������
void quicksort(int* array,int left,int right)
{
	if(left < right)
	{
		int k = Partition(array,left,right);
		quicksort(array,left,k-1);
		quicksort(array,k+1,right);
	}
}

//�ڶ��ַָ�ķ���
void swap(int* a,int* b)
{
	int temp = *a;
	*a  = *b;
	*b = temp;
}
int partition2(int* array,int low,int high)
{
	int key = array[low];

	while(low < high)
	{
		//�Ӻ����ҵ�һ�����ʵ�ֵ��ǰ��Ľ���
		while(low<high && array[high] >= key)
			high--;
		swap(&array[low],&array[high]);

		//��ǰ���ҵ�һ�����ʵ�ֵ�ͺ���Ľ���
		while(low< high && array[low] <= key)
			++low;
		swap(&array[low],&array[high]);
	}

	return low;
}

//�ڶ��ַָ���µĿ�������
void quicksort2(int* array,int left,int right)
{
	int i,j,key;
	if(left < right)
	{
		i = left;
		j = right;
		key = array[i];//������ߵ�Ԫ����Ϊ���ֵĻ�׼��
		do
		{
			while(array[j] > key && i<j)
				j--;//���������ҵ�һ��С�ڻ�׼ֵ��λ��j
			if(i<j) //�ҵ���λ��j
			{
				array[i] = array[j];
				i++;
			} //����J��Ԫ��������˲�����i

			while(array[i] < key && i<j)
				i++;//���������ҵ�һ�����ڱ�׼��λ��i
			if(i<j)
			{
				array[j] = array[i];
				j--;
			} //����I��Ԫ�������Ҷ˲�����j


		} while(i!= j);

		array[i] = key;// �ָ����
		quicksort2(array,left,i-1);
		quicksort2(array,i+1,right);
	}
}

int main()
{
	int array[]={9,4,5,2,1,3,7,8,6};
	quicksort2(array,0,8);
	int i;
	for(i=0;i<9;i++)
		printf("%d\n",array[i]);
	return 0;
}
