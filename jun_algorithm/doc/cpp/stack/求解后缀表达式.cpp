#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

/*
���ʽ��⣬����ջ�������ݽṹ����Ҫע���ַ���������֮���ת��
*/

//���ַ���ת��Ϊ����
int strtoi(string& s)
{
    if(s.length() == 0)
      return 0;
    int i=0,flag=1,result=0;
    if(s[0]=='-')
    {
       flag =-1;
       i++;
    }
    if(s[0]=='+')
    {
       i++;
    }
    for(;i<s.length();i++)
    {
        result *= 10;
        result += (s[i]-'0');
    }
    return result*flag;
}

//������ת��Ϊ�ַ���
string itostr(int num)
{
    int flag =1,count = num;
    if(num <0)
    {
        flag = 0;
        count = -count;
    }

    string result;
    while(count)
    {
      result += (count%10 +'0');
      count = count/10;
    }
    if(flag == 0)
     result += '-';
    reverse(result.begin(),result.end());
    return result;
}

/*
���ʽ���������
*/
int evalRPN(vector<string> &tokens)
{
   stack<string> sk;
   int result =0,i,temp;
   string first,second;
   //��ʼ�����ַ�������
   for(i=0;i<tokens.size();i++)
   {
   	   //�����ǰ���ַ���Ϊ���ţ���Ҫ��ջ��ȡ��������
       if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
       {
          first = sk.top();
          sk.pop();
          second =sk.top();
          sk.pop();
          //��ʼ����
          if(tokens[i] == "+")
             temp = strtoi(first)+strtoi(second);
          else if(tokens[i]=="-")
             temp = strtoi(first)-strtoi(second);
          else if(tokens[i]=="*")
             temp = strtoi(first)*strtoi(second);
          else
             temp = strtoi(second)/strtoi(first);
          //���������ѹ��ջ
		  first = itostr(temp);
          sk.push(first);
       }
       else // ���������ֻ��Ҫ����ǰ�ַ���ѹ��ջ�ڼ���
        sk.push(tokens[i]);
   }
   first = sk.top();
   result = strtoi(first);
   return result;
}

int main()
{
    string array[]={"4", "13", "5", "/", "+"};
    vector<string> tokens(array,array+sizeof(array)/sizeof(array[0]));
    cout<<evalRPN(tokens)<<endl;
    return 0;
}


