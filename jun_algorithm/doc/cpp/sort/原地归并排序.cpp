#include <iostream>
#include <vector>

using namespace std;

/*
��ĿҪ��
��������������a[0,mid-1]��a[mid,num-1]�� ������������鲢��ʹ����������
�ռ临�Ӷ�ΪO(1)
*/

/*
˼·����ͬһ�������������������кϲ�Ϊһ�� ����ʹ�ò��������ʽ
����벿�ֵ�Ԫ�ز��뵽ǰ�벿���� �Ժ�벿�ֵ�ÿһ��Ԫ�� ����ǰ�벿���ҵ�
���ʵ�λ��  Ȼ����루�����ڲ�������
*/

void Merge2(int* array,int begin,int end)
{
	int middle = begin + (end-begin)/2;

	int i= begin;
	int temp;

	//����벿���е�Ԫ���������ǰ��������������
	while(middle <= end)
	{
		temp = array[middle];//�������Ԫ��
		if(array[i] < array[middle]) //�ҵ����ʵ�λ��
		{
			i++;
		}
		else //���в���Ĳ���
		{
			int index = middle;
			while(index != i)
			{
				array[index] = array[index-1];
				index--;
			}
			array[i++] = temp;
			middle++;
		}

	}
}  //��������ܷ��پ���

/*
ԭ�ع鲢��˼��
������һ�����飬�����������Ѿ�����õ����鲻ʹ�ö���Ŀռ佫��������������
���кϲ� ����������ռ�ֱ�ΪA B����A���ҵ�һ������B[0]��Ԫ�ز���¼ΪA[i]
��B���ҵ�һ������A[i]��Ԫ�ز���¼ΪB[j] ����οռ��н������� Ȼ��ͱ������
*/

//�Գƽ���
void Revere(int* array,int begin,int end)
{
	int temp;
	while(begin < end)
	{
		temp = array[begin];
		array[begin]=array[end];
		array[end] = temp;
		begin++;
		end--;
	}
}

//����ת
/*
arrayΪ����ת������
begin Ϊ��ʼλ��
middle����ת����
end Ϊ����
*/
void Rotate_right(int* array,int begin,int middle,int end)
{
	Revere(array,begin,middle);
	Revere(array,middle+1,end);
	Revere(array,begin,end);
}

//ԭ�غϲ�
void Merge_second(int* array,int begin,int end)
{
	//[begin,mid-1] [mid,end]�ֱ�����
	int mid = begin + (end-begin)/2+1;
	int i = begin;
	int index;
	//ֱ���������������������е�Ԫ��������� ��ô�������������оͺϲ����
	while(mid <= end && i<mid)
	{
		//��ǰ��������������ҵ�һ��Ԫ�أ�����ں������������еĵ�һ��Ԫ��
		while(array[i] <= array[mid]&& i < mid)
		{
			i++;
		}
		//��¼��ǰ�������������еķֽ��
		index = mid;
		//�Ӻ����������������ҵ�һ��Ԫ�أ������ǰ���������еĵ�i��Ԫ��
		while(mid <= end && array[mid]<= array[i])
		{
			mid++;
		}
		//��indexΪ�ֽ�㣬Ҳ�����Ե�ǰ�������������еķֽ��Ϊ��ת����,����ת
		Rotate_right(array,i,index-1,mid-1);
		//����ǰ����������δ����Ԫ�ص�λ��
		i += (mid-index);
	}
}

//�鲢�������庯��
void Inplace_MergeSort(int* arr,int beg,int end)
{
	if(beg < end)
	{
		int mid = (beg+end)/2;
		Inplace_MergeSort(arr,beg,mid);
		Inplace_MergeSort(arr,mid+1,end);
		Merge_second(arr,beg,end);
	}
}

int main()
{
	int array[]= {2,4,6,8,10,1,3,5,7,9};
	int i;
	Inplace_MergeSort(array,0,9);
	for(i=0;i<10;i++)
		cout<<array[i]<<endl;
	return 0;
}
