#include <iostream>
using namespace std;

//�������� ��˼�룺��һ���Ѿ�����õ������У�Ϊ��һ��Ԫ���Һ��ʵĲ���λ�ã�
void InsertSort(int* array,int n)
{
	int i,j;
	int temp;

	//�ӵڶ���Ԫ�ؿ�ʼ���в������� Ϊ����ǰ������õ��������Һ��ʵ�λ��
	for(i=1;i<n;i++)
	{
		//Ϊ��ǰԪ��ѡ����ʵ�λ��
		temp = array[i];
		for(j=i-1;j>=0;j--)
			if(array[j] > temp)
				array[j+1] = array[j];
			else
				break;

		//�ҵ����ʵ�λ�ú���䵱ǰֵ
		array[j+1] = temp;
	}

	for(i=0;i<n;i++)
		cout<<array[i]<<endl;
}

int main()
{
	int array[]={7,5,2,9,1,3};
	InsertSort(array,6);
	return 0;
}
