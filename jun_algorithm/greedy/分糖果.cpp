#include <iostream>
#include <vector>
using namespace std;

/*
��������ɨ�裬һ�δ������ң�һ�δ�������
��һ��ɨ���ʱ��ά������ÿһ��С���������Ҫ���ٵ��ǹ�����
���������ӦԪ���У��ڶ���ɨ���ʱ��ά���ұ�����������ǹ�����
���ұȽϽ���ߺ��ұߴ���ǹ����������������ӦԪ����
*/

int candy(vector<int> &ratings)
{
    vector<int> candy(ratings.size(),1);
    int sum,i;
    for(i=1;i<ratings.size();i++)
    {
       if(ratings[i] > ratings[i-1])
         candy[i] = candy[i-1]+1;
    }

    sum = candy[ratings.size()-1];
    for(i=ratings.size()-2;i>=0;i--)
    {
       int cur =1;
       if(ratings[i] > ratings[i+1])
         cur = candy[i+1]+1;
       sum += max(cur,candy[i]);
       candy[i] = cur;
    }
    return sum;
}


/*
��������˼·
*/
int candy2(vector<int> &ratings)
{
    vector<int> candy(ratings.size(),1);
    int sum,i;
    for(i=1;i<ratings.size();i++)
    {
       if(ratings[i] > ratings[i-1])
         candy[i] = candy[i-1]+1;
    }

    sum = candy[ratings.size()-1];
    for(i=ratings.size()-2;i>=0;i--)
    {
       int cur =1;
       if(ratings[i] > ratings[i+1] && candy[i] <= candy[i+1])
        	candy[i] = candy[i+1]+1;
       sum += candy[i];

    }

    return sum;
}


int main()
{
	int array[]={4,2,6,8,5};
	vector<int> vec(array,array+sizeof(array)/sizeof(int));
	cout<<candy(vec)<<endl;
	return 0;
}
