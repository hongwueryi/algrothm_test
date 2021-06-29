#pragma once

class Solution {
public:
	/**
	* 请实现有重复数字的升序数组的二分查找
	* 
	* 如果目标值存在返回下标，否则返回 -1
	* @param nums int整型vector
	* @param target int整型
	* @return int整型
	*/
	int search(vector<int>& nums, int target);

	//增序快排
	void quicksort(int a[], int first, INT end);
	//增序冒泡
	void bubblesort(int *a, int n);
	//增序冒泡优化
	void bubblesort_Ex(int *a, int n);
	//增序冒泡优化2
	void bubblesort_Ex2(int *a, int n);
	//选择排序
	void chooseSort(int*a, INT n);
	//直接插入排序
	void insertSort(int*a, int n);
	//归并排序
	void MergeSort(int arr[], int l, int r);
	//堆排序
	void heapSort(int a[], int len);
};