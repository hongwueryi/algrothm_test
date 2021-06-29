#include "stdafx.h"
#include <deque>
#include <vector>
#include "tree.h"
#include <queue>

vector<vector<int> > Solution_Tree::threeOrders(TreeNode* root) {
	// write code here
	vector<vector<int >> result;
	if (root == nullptr) return result;
	preorder(root);
	midorder(root);
	postorder(root);
	result = { pre, mid, post };
	return result;
}
void Solution_Tree::preorder(TreeNode* node) {
	if (node == nullptr) return;
	pre.push_back(node->val);
	preorder(node->left);
	preorder(node->right);
}
void Solution_Tree::midorder(TreeNode* node) {
	if (node == nullptr) return;
	midorder(node->left);
	mid.push_back(node->val);
	midorder(node->right);
}
void Solution_Tree::postorder(TreeNode* node) {
	if (node == nullptr) return;
	postorder(node->left);
	postorder(node->right);
	post.push_back(node->val);
}

vector<vector<int>> Solution_Tree::levelorder(TreeNode* root)
{
	queue<TreeNode*> Tree_deque;
	vector<vector<int>> result_vec;
	if (nullptr == root)
		return result_vec;
	Tree_deque.push(root);
	int level = 0;
	while (!Tree_deque.empty())
	{
		vector<int> vec;
		int size_deque = Tree_deque.size();
		while (size_deque--)
		{
			TreeNode* node = Tree_deque.front();
			Tree_deque.pop();
			vec.push_back(node->val);
			if (node->left)
			{
				Tree_deque.push(node->left);
			}
			if (node->right)
			{
				Tree_deque.push(node->right);
			}
		}
//		如果需要之字形，即第一层从左往右，第二层从右往左……
// 		if (level % 2 != 0)
// 		{
// 			std::reverse(vec.begin(), vec.end());
// 		}
		if (!vec.empty())
			result_vec.push_back(vec);
	}
	return result_vec;
}