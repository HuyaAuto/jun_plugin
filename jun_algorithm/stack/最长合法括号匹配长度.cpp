#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
��Ϸ�����ƥ�䳤��
*/

/*
ʹ��һ��bool����������Ѿ�ƥ������ַ�
ֱ�����������ǵĳ��Ⱦ�������Ľ����ֻ��Ҫ���α������飬ʱ�临�Ӷ�ΪO(n)
*/
int LongestValidParentheses(string s) {
         bool *a = new bool[s.length()];
        //memset(a, false, s.length());
         stack<int> st;
         for (int i = 0; i < s.length(); ++i) {
              if (s[i] == '(') {
                  st.push(i);
             } else if (s[i] == ')' && !st.empty()) {
                 a[i] = true;
                 a[st.top()] = true;
                 st.pop();
             }
         }
         int max_len = 0, cur_len = 0;
         for (int i = 0; i < s.length(); ++i) {
             if (a[i])
			 	cur_len++;
             else
			 	cur_len = 0;
            max_len = max(max_len, cur_len);
         }
         return max_len;
}

/*
�������ʹ��ջ��¼ĳһ���������ַ����е�λ�ã�������ڵ�ǰ�ַ���ջ��λ�õ�
�ַ�����ƥ�䣬��ô���Ը���ջ�Ƿ�Ϊ�����жϵ�ǰ�ƥ��������
Ȼ���Ŀ�����ƥ��
*/
int LongestValidParentheses2(string s) {
        stack<int> st;
        int pos;
        int maxlen = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == '(') st.push(i);
            else  // ')'
            {
				if(!st.empty() && s[st.top()]=='(')
				{

					st.pop();
					if(st.empty())
						pos = i+1;
					else
						pos = i-st.top();
					if(maxlen < pos)
						maxlen = pos;
				}
				else
					st.push(i);
            }

        }
        return maxlen;
}

int main()
{
	string str=")()())";
	cout<<LongestValidParentheses(str);
	//cout<<endl<<Longest_dp(str);
//	cout<<str<<endl;

	return 0;
}


