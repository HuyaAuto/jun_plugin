#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

/*
�ж�һ�������ַ�����ɵ������Ƿ�Ϸ�
ʹ��ջ��˼�� ,����ж�ջ�Ƿ�Ϊ��
*/
bool isValidParenthess(string& str)
{
	stack<char> st;
	int i;
	char tmp;
	//��ʼ����ջ������ݽṹ�����������������ַ���
	for(i=0;i<str.length();i++)
	{
		if(str[i]=='(' || str[i]=='[' || str[i]=='{')
			st.push(str[i]);
		else if(str[i]==']')
		{
			tmp = st.top();
			if(tmp != '[')
				return false;
			else
				st.pop();
		}
		else if(str[i] ==')')
		{
			tmp = st.top();
			if(tmp != '(')
				return false;
			else
				st.pop();
		}
		else if(str[i]=='}')
		{
			tmp = st.top();
			if(tmp != '{')
				return false;
			else
				st.pop();
		}
		else
			return false;

	}
	if(st.empty())
		return true;
	else
		return false;
}

/*
ʹ�õݹ�ķ�����ջ�е����ݽ��з�ת
˼·�����ջΪ�գ���ôֱ�ӽ�Ԫ�طŵ�ջ�ĵײ����ɣ����ջ����Ԫ�أ�
��ôȡ��ջ�е�Ԫ�أ���ԭ����Ԫ���ٴε��ú�����ŵ�ջ�ף�Ȼ��ȡ����Ԫ��ѹ��ջ
���ɡ�
*/

//��ĳһ��Ԫ�ط���ջ�ײ�
void Push_Bottom(stack<int>& st,int value)
{
    int tmp;
    //���ջΪ�գ���ôֱ�ӽ���ǰԪ��ѹ��ջ
    if(st.size()==0)
        st.push(value);
    else  //���ջ����Ԫ�أ���ôȡ�����е�Ԫ�أ�Ȼ���ٽ�Ԫ��ѹ��
    {
        tmp = st.top();
        st.pop();
        Push_Bottom(st,value);
        st.push(tmp);
    }
}

/*
��תջ
*/
void Reverse_st(stack<int>& st)
{
    int tmp;
    if(st.size()<=1)
        return;
    else
    {
    	//ȡ��ջ��Ԫ��
        tmp = st.top();
        st.pop();
        //�ݹ���ã���תʣ���Ԫ��
        Reverse_st(st);
        //��ȡ����Ԫ�ط���ջ�ײ�
        Push_Bottom(st,tmp);
    }
}

int main()
{
	string str("{()[]{}}");
	cout<<isValidParenthess(str);
	stack<int> st;
        int i;
        int tmp;
        for(i=0;i<5;i++)
            st.push(i);

        Reverse_st(st);
    //  Push_Bottom(st,5);
        while(!st.empty())
        {
            tmp = st.top();
            cout<<tmp<<endl;
            st.pop();
        }
	return 0;
}
