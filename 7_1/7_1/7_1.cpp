// 7_1.cpp : �������̨Ӧ�ó������ڵ㡣
//
//�ص��ǿ��Ǳ߽�����������û�г���int�ķ�Χ��Ҳ����return 0 ������
#include "stdafx.h"
#include <limits.h>//�������ͷ�ļ����Ϳ���ʹ��INT_MAX��INT_MIN��
class Solution {
public:
    int reverse(int x) {
		int unit = 0;
        char isnega = x<0 ? 1 : 0;

		if(x == INT_MIN)//��������Сֵʱ��return 0
			return 0 ;
		x = isnega == 1 ? -x : x;//xȡ����ֵ

		unit = x%10;
		x = x/10;
		while(x)
		{
			if(unit >= INT_MAX/10.0)//��ֹunit*10 Խ��
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

