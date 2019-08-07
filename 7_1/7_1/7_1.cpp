// 7_1.cpp : 定义控制台应用程序的入口点。
//
//重点是考虑边界条件，看有没有超出int的范围，也就是return 0 的条件
#include "stdafx.h"
#include <limits.h>//包含这个头文件，就可以使用INT_MAX和INT_MIN了
class Solution {
public:
    int reverse(int x) {
		int unit = 0;
        char isnega = x<0 ? 1 : 0;

		if(x == INT_MIN)//当输入最小值时，return 0
			return 0 ;
		x = isnega == 1 ? -x : x;//x取绝对值

		unit = x%10;
		x = x/10;
		while(x)
		{
			if(unit >= INT_MAX/10.0)//防止unit*10 越界
				return 0;
			unit = unit*10 + x %10;
			x = x/10;
		}
		if (unit < 0 || unit > INT_MAX) 
			return 0;

		unit = isnega == 1 ? -unit : unit;
		return unit;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	int result = 0;
	Solution solution;
	result = solution.reverse(1534236469);
	printf("%d",result);
	return 0;
}

