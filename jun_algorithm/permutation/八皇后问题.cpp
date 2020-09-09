#include <iostream>
#include <vector>
using namespace std;
/*
��ĿҪ��
��8*8�Ĺ��������ϰڷ��Ű˸��ʺ�ʹ�䲻�ܻ��๥��
Ҳ����˵�����������ʺ󲻵ô���ͬһ�С�ͬһ�л���ͬһ�Խ�����
�����ж����ַ���
*/

/*
�˻ʺ�����
*/
int g_number=0;
  void Print(int ColumnIndex[] , int length)
    {
        cout<<g_number<<endl;

        for(int i = 0 ; i < length; ++i)
            cout<<ColumnIndex[i]<<" ";
       cout<<endl;
    }

    bool Check(int ColumnIndex[] , int length)
    {
        int i,j;
        for(i = 0 ; i < length; ++i)
        {
            for(j = i + 1 ; j < length; ++j)
            {
                if( i - j == ColumnIndex[i] - ColumnIndex[j] || j - i == ColumnIndex[i] - ColumnIndex[j])   //���������Խ�����
                    return false;
            }
        }
        return true;
    }
    void Permutation(int ColumnIndex[] , int length , int index)
    {
        if(index == length)
        {
            if( Check(ColumnIndex , length) )   //������̵�ǰ��״̬�Ƿ�Ϸ�
            {
                ++g_number;
                Print(ColumnIndex , length);
            }
        }
        else
        {
            for(int i = index ; i < length; ++i)   //ȫ����
            {
                swap(ColumnIndex[index] , ColumnIndex[i]);
                Permutation(ColumnIndex , length , index + 1);
                swap(ColumnIndex[index] , ColumnIndex[i]);
            }
        }
    }


 void EightQueen( )
    {
        const int queens = 8;
        int ColumnIndex[queens];
        for(int i = 0 ; i < queens ; ++i)
            ColumnIndex[i] = i;    //��ʼ��
        Permutation(ColumnIndex , queens , 0);
    }
int main()
{
	EightQueen();
	return 0;
}
