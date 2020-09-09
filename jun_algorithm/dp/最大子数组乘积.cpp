#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
����Ӵ��˻������ڿ��ܳ��ָ�����Ҳ��DP���⣬Ҳ�Ǿֲ����ź�ȫ���������⡣
������Ҫ��¼��Сֵ���������������飬�ֱ��¼������ǰԪ�����ڵ��Ӵ����ܹ���
��������Сֵ��Ȼ���������ٸ���ȫ��������ڵ�ǰ��󣬿�����֮ǰ���
���Ե�ǰԪ�أ�Ҳ������ǰһ��Ԫ����С���Ե�ǰԪ�أ�Ҳ�����ǵ�ǰԪ�� 
*/

int maxProduct(vector<int>& vec)
{
    if(vec.size()==0)
     return 0;
    vector<int> maxcur(vec.size(),0);
    vector<int> mincur(vec.size(),0);
    maxcur[0]=vec[0];
    mincur[0]=vec[0];
    int maxproduct = vec[0];
    int i,temp;
    for(i=1;i<vec.size();i++)
    {
       maxcur[i] = max(vec[i],max(maxcur[i-1]*vec[i],mincur[i-1]*vec[i]));
       mincur[i] = min(vec[i],min(mincur[i-1]*vec[i],maxcur[i-1]*vec[i]));
       
       maxproduct = max(maxcur[i],maxproduct);                      
                           
    }
    return maxproduct;
}
 

int main()
{
	int array[] ={2,3,-2,4};
	vector<int> vec(array,array+sizeof(array)/sizeof(int));
	cout<<maxProduct(vec)<<endl;
	return 0;
} 
