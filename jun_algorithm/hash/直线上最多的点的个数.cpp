#include <iostream>
#include <vector>
using namespace std;

/*
�������ĵ�ĸ���
˼·�����Կ����������ܹ������ֱ�ߵ�б�ʣ�����б�����жϹ��ߵĵ�ĸ���
����б�ʺ͸�б���ϵ�ĸ����͹�����һ����ֵ�ԣ�����ʹ��hash�����洢
*/

int maxPoints(vector<pair<int,int> >& points )
{
	if(points.size() == 0)
		return 0;
	int max =1;
	double ratio=0.0;
	//��ʼ�����㣬�����ֵ��
	for(int i=0;i<points.size()-1;i++)
	{
		hash_map<double,int> map;
		int numofSame=0;
		int localMax=1;
		//�ӵ�ǰ�����֮��ĵ㹹�ɵ�б��
		for(int j=i+1;;j<points.size();j++)
		{
			if(points[j].first == points[j].first && points[j].second == points.second)
			{
				numofSame++;
				continue;
			}
			else if(points[j].first == points[i].first)
			{
				ratio = numeric_limits<double>::max();
			}
			else if(points[j].second == points[i].second)
			{
				ratio =0.0;
			}
			else
			{
				ratio = (double)(points[j].second-points[i].second)/(double)(points[j].first-points[i].first);

			}
			int num;
			if(map.find(ratio) != map.end())
				map[ratio]++;
			else
				map[ratio]=2;
		}
		//��ʼ����ĳһб�������ĵ�ĸ���
		hash_map<double,int>::iterator it = map.begin();
		fo(;it!=map.end();it++)
			localMax = max(localMax,it->second);
		localMax += numofSame;
		max = max(max,localMax);
	}
	return max;
}

