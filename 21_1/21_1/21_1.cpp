// 21_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 **/
struct ListNode {//C++中 ListNode是一个类
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	   if(!l1 && l2) return l2;
	   else if(l1 && !l2) return l1;
	   else if(!l1 && !l2) return NULL;

	   ListNode* MergeList = new ListNode(0);
	   ListNode* Ptr = MergeList;

	   while(l1 || l2)
	   {
		   ListNode* MergeListNew = new ListNode(0);//用ListNode* MergeListNew = (ListNode*)malloc(sizeof(ListNode)); LeetCode报错
		   if(!l1)
		   {
				MergeListNew->val = l2->val;
				l2 = l2->next;
		   }
		   else if(!l2)
		   {
				MergeListNew->val = l1->val;
				l1 = l1->next;
		   }
		   else if(l1 && l2)
		   {
			   if(l1->val >= l2->val)
			   {
					MergeListNew->val = l2->val;
					l2 = l2->next;
			   }
			   else
			   {
					MergeListNew->val = l1->val;
					l1 = l1->next;
			   }
		   }
		   Ptr->next = MergeListNew;
		   Ptr = Ptr->next;
	   }
	   return MergeList->next;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	ListNode * Result = NULL;
	ListNode Node1_1(1);
	ListNode Node1_2(2);
	ListNode Node1_3(4);
	Node1_1.next = &Node1_2;
	Node1_2.next = &Node1_3;

	ListNode Node2_1(1);
	ListNode Node2_2(3);
	ListNode Node2_3(4);
	Node2_1.next = &Node2_2;
	Node2_2.next = &Node2_3;
	Result = solution.mergeTwoLists(&Node1_1,&Node2_1);
	return 0;
}

