#include <stdio.h>
#include <stdlib.h>

//������
void HeapAdjust(int* array,int s,int length)
{
	int temp = array[s];//��������Ԫ��
	int child = 2*s+1;//�������ڵ�����ӵ�λ��

	//��ʼ����
	while(child < length)
	{
		//����Һ��Ӵ������ӣ��ҵ��ȵ�ǰ�������ڵ��ĺ��ӽڵ�
		if(child+1 < length&& array[child] < array[child+1])
			child++;
		//����ϴ�ĺ��Ӵ��ڴ������Ľڵ�
		if(array[s] < array[child])
		{
			array[s] = array[child];//��ô�ϴ�Ľڵ�������
			s = child;//���´������ڵ��λ��
			child = 2*s+1;//���´������ڵ������
		}

		else
			break;
		array[s] = temp;

	}
}

//������
void HeapSort(int* array,int length)
{
	int i;
	//��������
	for(i=(length-1)/2;i>=0;i--)
	{
		HeapAdjust(array,i,length);
	}

	//�����һ��Ԫ�ؿ�ʼ�����н��е���
	for(i=length-1;i>0;i--)
	{
		//�����Ѷ�Ԫ�غͶ������һ��Ԫ��
		int tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;
		//ÿ�ν���Ԫ��֮�󣬾���Ҫ���µ�����
		HeapAdjust(array,0,i);
	}
}

int main()
{
	int array[]={3,4,5,1,9,8,6,2,7,10};
	HeapSort(array,10);
	int i;
	for(i=0;i<10;i++)
		printf("%d\n",array[i]);
	return 0;
}
