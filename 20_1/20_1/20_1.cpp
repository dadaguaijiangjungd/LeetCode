// 20_1.cpp : �������̨Ӧ�ó������ڵ㡣
//
//û�п��ǵ��ĵط�
//{[}]
//��һ������Ϊ������ʱ
//����Ϊ{{ʱ
#include "stdafx.h"
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> SaveStack;
		char PopCharacter = 0;
		int i = 0,CntMatch = 0;
		if(s.length() % 2 != 0) return false;
		for(i = 0;i < s.length();i++)
		{
			if(s[i] == '(' || s[i] == '[' || s[i] == '{')
				SaveStack.push(s[i]);
			else 
			{
				if(i == 0) return false;//����һ������Ϊ������ʱ������false
				else
				{
					PopCharacter = SaveStack.top();//ȡջ����ֵ
					SaveStack.pop();//��ջ
					if(s[i] == ')' && PopCharacter == '(')//ƥ��ɹ�
						CntMatch++;
					else if(s[i] == ']' && PopCharacter == '[')//ƥ��ɹ�
						CntMatch++;
					else if(s[i] == '}' && PopCharacter == '{')//ƥ��ɹ�
						CntMatch++;
					else return false;
				}
			}
		}
		if(CntMatch == s.length()/2)//ȫ��ƥ��ɹ� ��ֹֻ��������ʱreturn true
			return true;
		else
			return false;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	bool result = false;
	string characters = ("((");
	result = solution.isValid(characters);
	return 0;
}

