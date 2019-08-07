// 20_1.cpp : 定义控制台应用程序的入口点。
//
//没有考虑到的地方
//{[}]
//第一个符号为右括号时
//符号为{{时
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
				if(i == 0) return false;//当第一个符号为右括号时，返回false
				else
				{
					PopCharacter = SaveStack.top();//取栈顶的值
					SaveStack.pop();//出栈
					if(s[i] == ')' && PopCharacter == '(')//匹配成功
						CntMatch++;
					else if(s[i] == ']' && PopCharacter == '[')//匹配成功
						CntMatch++;
					else if(s[i] == '}' && PopCharacter == '{')//匹配成功
						CntMatch++;
					else return false;
				}
			}
		}
		if(CntMatch == s.length()/2)//全部匹配成功 防止只有左括号时return true
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

