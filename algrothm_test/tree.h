#pragma once

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


class Solution_Tree {
	//�ֱ��ն�������������ͺ����ӡ���еĽڵ㡣
private:
	vector<int > pre, mid, post;
public:
	/**
	*
	* @param root TreeNode�� the root of binary tree
	* @return int����vector<vector<>>
	*/
	vector<vector<int> > threeOrders(TreeNode* root);
	void preorder(TreeNode* node);
	void midorder(TreeNode* node);
	void postorder(TreeNode* node);

	//�������
	vector<vector<int>> levelorder(TreeNode* root);
};