
/*
��Ʊ�����������

����ά������������һ���ǵ�ǰ�����i�����������j�ν��ף�
��õ������Ƕ��٣�global[i][j]��
��һ���ǵ�ǰ�����i�죬�����Խ���j�ν��ף��������һ�ν����ڵ�������
��ô��õ������Ƕ��٣�local[i][j]��
���ƹ�ʽ
global[i][j] = max(local[i][j],glboal[i-1][j]),
Ҳ����ȡ��ǰ�ֲ���ú͹���ȫ����õ�����֮һ
���ھֲ����
local[i][j] = max(global[i-1][j-1]+maxdiff(diff,0),local[i-1][j]+diff);
*/

/*
�ڽ������ν��׵��������
*/
int maxProfit(vector<int>& prices)
{
	if(prices.size() <= 0)
		return 0;
	int global[3];
	int local[3];
	for(int i=0;i<prices.size()-1;i++)
	{
		int diff = prices[i+1]-prices[i];
		for(int j=2;j>=1;j--)
		{
			local[j] = max(global[j-1]+(diff>0?diff:0),local[j]+diff);
			global[j] = max(local[j],global[j]);
		}
	}
	global[2];
}


/*
��ν���֮��
*/
int helper(vector<int>& prices,int k)
{
	int len = prices.size();
	if(len == 0)
		return 0;
	int local[10][10];
	int global[10][10];//��ʱ����Ŀռ�
	for(int i=1;i<len;i++)
	{
		int diff = prices[i]-prices[i-1];
		for(j=1;j<=k;j++)
		{
			local[i][j] = max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff);
			glocal[i][j] = max(local[i][j],global[i-1][j]);
		}
	}
}

int maxProfit(vector<int>& prices)
{
	return helper(prices,2);
}
