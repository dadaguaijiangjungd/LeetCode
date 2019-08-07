// 14_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = "";
		vector<char> CommonPrefix;
		int i = 0,j = 0,MinLength = 0;
		char FlagDifferent = 0;
		if(strs.empty())
			return str;
		MinLength = strs[0].size();
		for(i = 1;i < strs.size(); i++)
		{
			if(MinLength > strs[i].size())
				MinLength = strs[i].size();
		}
		if(MinLength == 0) 
			return str;
		for(i = 0;i < MinLength; i++)
		{
			for(j = 1;j < strs.size();j++)
			{
				if(strs[0][i] != strs[j][i])
				{
					FlagDifferent = 1;
					break;
				}
			}
			if(FlagDifferent == 1)
					break;
			CommonPrefix.push_back(strs[0][i]);
		}
		//遍历vector
		for(vector<char>::iterator iter = CommonPrefix.begin(); iter != CommonPrefix.end(); ++iter)
		{
			str += *iter;
		}
		return str;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	vector<string> Str;
	string result = "";
	Str.push_back("flower");
	Str.push_back("flow");
	Str.push_back("flight");
	result = solution.longestCommonPrefix(Str);
	return 0;
}