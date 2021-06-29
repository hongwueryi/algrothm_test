#include "stdafx.h"
#include "list.h"


bool Solution_List::hasCycle(ListNode *head) {
	ListNode *temp = new ListNode(0);//初始化一个节点值为0的空节点；
	if (head == NULL)
		return false;
	while (head) {
		if (head->next == temp)
			return true;
		ListNode *p = head;
		head = head->next;
		p->next = temp;
	}
	return false;
// 	ListNode *p = head;
// 	while (head != nullptr&&head->next != nullptr) {
// 		if (head->next == head)
// 			return head;
// 		p = head->next;
// 		head->next = head;
// 		head = p;
// 	}
// 	return nullptr;
}

ListNode* Solution_List::mergeTwoLists(ListNode* l1, ListNode* l2) {
	// write code here
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;
	if (l1->val < l2->val) {
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else {
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
	return nullptr;
}

ListNode* Solution_List::ReverseList(ListNode* pHead) {
	//https://zhuanlan.zhihu.com/p/106050123
	ListNode* pre = nullptr;
	ListNode* cur = pHead;
	while (cur) {
		ListNode* tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	return pre;
}

