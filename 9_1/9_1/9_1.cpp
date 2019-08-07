// 9_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <limits.h>
class Solution {
public:
    bool isPalindrome(int x) {
		int value = 0;
		int x_bak = x;
        if(x<0 || x>=INT_MAX)
			return false;
		else
		{
			value = x%10;
			x /= 10;
			while(x)
			{
				if(value>=INT_MAX/10.0)
					return false;
				value = value*10+x%10;
				x /= 10;
			}
			if(x_bak == value)
				return true;
			return false;
		}
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	bool result = 0;
	result = solution.isPalindrome(1999999991);
	return 0;
}

