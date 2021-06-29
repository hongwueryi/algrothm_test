#pragma once

class Solution_Array {
public:
	//两个有序的整数数组A和B，请将数组A合并到数组B中,假设A足够空间存放B
	void merge(int A[], int m, int B[], int n);

	//返回数组前K个最小的数
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k);
};