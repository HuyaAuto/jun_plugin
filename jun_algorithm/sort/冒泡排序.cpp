#include <iostream>
#include <vector>
using namespace std;

//ð������ �Ӵ�С����
void Bulldle(int* array,int num)
{
	int i,j,temp;
	for(i=0;i<num-1;i++)
	{
		for(j = i+1;j<num;j++)
			if(array[i] < array[j])
			{
				temp  = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
	}
}


// ð������������� ��С��������
void Bulldle2(int* array,int num)
{
	int i,j,temp;
	int flag =1;
	for(i=0;i<num-1 && flag;i++)
	{
		flag =0;
		for(j=i+1;j<num;j++)
			if(array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				flag =1;
			}
	}
}
int main()
{
	int array[]={7,5,2,9,1,3};
	Bulldle2(array,6);
	int i;
	for(i=0;i<sizeof(array)/sizeof(int);i++)
		cout<<array[i]<<endl;
	return 0;
}
