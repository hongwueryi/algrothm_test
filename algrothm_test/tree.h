#pragma once

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


class Solution_Tree {
	//分别按照二叉树先序，中序和后序打印所有的节点。
private:
	vector<int > pre, mid, post;
public:
	/**
	*
	* @param root TreeNode类 the root of binary tree
	* @return int整型vector<vector<>>
	*/
	vector<vector<int> > threeOrders(TreeNode* root);
	void preorder(TreeNode* node);
	void midorder(TreeNode* node);
	void postorder(TreeNode* node);

	//层序遍历
	vector<vector<int>> levelorder(TreeNode* root);
};