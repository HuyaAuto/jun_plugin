#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

/*
�бƷ���
���������������ÿ�ε���ʱ�ж���ߵ���ұߵ�ָ��������ĸ���
�����ߵ��£�����ζ�����ƶ��ұߵ㲻����ʹ�ý����ø���
��Ϊƿ������ߵ㣬�ƶ��ұߵ�ֻ���С���������ʱ������ѡ����ߵ�����
��֮��ѡ���ұߵ����ƣ������������һֱά�������ݻ� 
*/

int area(vector<int> &height, int i, int j)  
{  
    int h = height[i]<height[j]?height[i]:height[j];  
    return h*(j-i);  
}  
int maxArea(vector<int> &height) 
{  
    int max=0;  
    for(int i=0;i<height.size();i++)  
    {  
        for(int j=i+1;j<height.size();j++)  
        {  
            int a = area(height,i,j);  
            if(a>max)  
            	max=a;  
        }  
    }  
    return max;  
}  

/*
�ڶ��ַ��� 
*/
int maxarea(vector<int>& vec)
{
	int maxarea=0;
	int first,second;
	int i=0,j=vec.size()-1;
	while( i<j)
	{
		if(min(vec[i],vec[j])*(j-i) > maxarea)
		{
			maxarea = min(vec[i],vec[j])*(j-i);
		}
		if(vec[i] < vec[j])
			i++;
		else
			j--;
	}
	return maxarea;
}

/*

			|
			|						 __						
			|                       |  |
			|		  __            |  |__    __ 
			|		 |	|           |  |  |  |  |
		    |	__	 | 	|__	   __   |  |  |__|  |__
			|  |  |	 |	|  |  |  |  |  |  |  |  |  |
			|__|__|__|__|__|__|__|__|__|__|__|__|__|_____
            1  2  3  4  5  6  7  8  8  9  10 11 12  
����������һ������Ϊ[0,1,0,2,1,0,1,3,2,1,2,1]��ÿ��Ԫ�ش������ӵĸ߶�
������ķ���ֵΪ6 

˼·������������������ҵ���ߵ�����λ�ã���ô����ͷ��ʼ�ҿ���
ʢˮ�Ķ��٣������ͷ��ʼ��������Ҫ������������ߵ�λ�ã���������ǰλ��
������ֵ�ǰ�����ӱ�֮ǰ��¼�����Ӹߣ���ô����
���û��֮ǰ��¼�����Ӹߣ���ô�Ϳ��Լ��㵱ǰ�������֮ǰ�ĸ����ӵ�ʢˮ�� 
*/ 
int TrapRainWater(vector<int>& vec)
{
	int i,maxhigh;
	maxhigh = 0;
	int left=0,right = 0;
	int sum =0;
	for(i=0;i<vec.size();i++)
		if(vec[i] > vec[maxhigh])
			maxhigh = i;
	
	for(i=0;i<maxhigh;i++)
	{
		if(vec[i] < left)
			sum +=(left-vec[i]);
		else
			left = vec[i];
	}
	
	for(i=vec.size()-1;i>maxhigh;i--)
	{
		if(vec[i]<right)
			sum += (right-vec[i]);
		else
			right = vec[i];
	}
	return sum;
} 

int main()
{
//	int array[]={4,3,4,5,7,9,7,6,8,5,3,2};
//	vector<int> vec(array,array+sizeof(array)/sizeof(int));
//	cout<<maxArea(vec)<<endl;
	int array[]={0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> vec(array,array+sizeof(array)/sizeof(int));
	cout<<TrapRainWater(vec)<<endl;
	return 0;
}
