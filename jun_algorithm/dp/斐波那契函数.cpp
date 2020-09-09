/*쳲���������*/
#include<stdio.h>
#define NIL -1
#define MAX 100

int lookup[MAX];

/*��ʼ����������*/
void _initialize()
{
  int i;
  for (i = 0; i < MAX; i++)
    lookup[i] = NIL;
}

/*���仯�����϶��£���
���仯�洢��ʵ�ǶԵݹ����С���޸ģ�
��Ϊ������DP����Ĺ��ɡ�
���ǳ�ʼ��һ�������в������г�ʼֵΪ-1��
ÿ��������Ҫ���һ�������⣬
�������������������(���ұ�)�Ƿ��д𰸡�
���Ԥ�ȼ����ֵ��,��ô���Ǿͷ��ظ�ֵ��
�������Ǽ����ֵ���ѽ����������(���ұ�)�У�
�Ա����������Ժ��ظ�ʹ�á�*/
int fib1(int n)
{
   if(lookup[n] == NIL)
   {
    if ( n <= 1 )
      lookup[n] = n;
    else
      lookup[n] = fib1(n-1) + fib1(n-2);
   }

   return lookup[n];
}

int fib2(int n)
{
  int f[n+1];
  int i;
  f[0] = 0;   f[1] = 1;
  for (i = 2; i <= n; i++)
      f[i] = f[i-1] + f[i-2];

  return f[n];
}


int main ()
{
  int n = 9;
  _initialize();
  printf("Fibonacci number is %d\n", fib1(n));
  printf("Fibonacci number is %d ", fib2(n));
  getchar();
  return 0;
}
