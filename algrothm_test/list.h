#pragma once

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution_List {
public:
	//判断给定的链表中是否有环。如果有环则返回true，否则返回false,空间复杂度O(1)
	bool hasCycle(ListNode *head);

	//将两个有序的链表合并为一个新链表，要求新的链表是通过拼接两个链表的节点来生成的，且合并后新链表依然有序。
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

	//输入一个链表，反转链表后，输出新链表的表头
	ListNode* ReverseList(ListNode* pHead);
};

