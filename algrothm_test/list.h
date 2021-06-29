#pragma once

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution_List {
public:
	//�жϸ������������Ƿ��л�������л��򷵻�true�����򷵻�false,�ռ临�Ӷ�O(1)
	bool hasCycle(ListNode *head);

	//���������������ϲ�Ϊһ��������Ҫ���µ�������ͨ��ƴ����������Ľڵ������ɵģ��Һϲ�����������Ȼ����
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

	//����һ��������ת��������������ı�ͷ
	ListNode* ReverseList(ListNode* pHead);
};

