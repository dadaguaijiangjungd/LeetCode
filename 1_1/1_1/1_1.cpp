// 1_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include<algorithm> 
#include<iostream> 
#include<vector> 

using namespace std; 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
	{
		int test1 = 0,test2 = 0;
		char ptr_cnt = 0,ptr_cnt_high = 2;
		vector<int> result;
		int result_once[2] = {0};
		vector<int>::iterator head;
		vector<int>::iterator tail;
        vector<int> nums_back(nums);
		sort(nums.begin(),nums.end()); 
		head = nums.begin();
		tail = nums.end()-1;
		
		while(head != tail)
		{
			test1 = *head;
			test2 = *tail;
			if((test1 + test2)>target)
			{
				tail--;
			}
			else if((test1 + test2)<target)
			{
				head++;
			}
			else if((test1 + test2) == target)
			{
				result_once[0] = test1;//result_once[0]比result_once[1]小或相等
				result_once[1] = test2;
				break;
			}
		}
		for(int j = 0;j < nums_back.size(); j++)
		{
			for(int i = ptr_cnt;i < ptr_cnt_high;i++)
			{
				if(nums_back[j] == result_once[i])
				{
					if(i == 0)//找到result_once[0]了，开始找result_once[1]
					{
						ptr_cnt = 1;
					}
					else if(i == 1)//找到result_once[1]了，开始找result_once[0]
					{
						ptr_cnt_high = 1;
					}
					result.push_back(j);
					break;
				}
			}
		}
		return result;
    }
};




int _tmain(int argc, _TCHAR* argv[])
{
	int a[5] = {3,3,3,3,3};
	vector<int> Num(a,a+5);
	vector<int> result1;
	Solution solution;
	result1 = solution.twoSum(Num,6);
	return 0;
}

