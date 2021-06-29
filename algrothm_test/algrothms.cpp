#include "stdafx.h"
#include "algrothms.h"

#include <iostream>
int Solution::search(vector<int>& nums, int target) {
	// write code here
	if (nums.empty())
		return -1;
	if (1 == nums.size() && target == nums.at(0))
		return 0;

	int left = 0; 
	int right = nums.size() - 1;
	int mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
		else
			right = mid;
	}

	if (nums[left] == target)
		return left;
	return -1;
}

void Solution::quicksort(int a[], int first, INT end)
{
	if (first >= end) return;
	int left = first;
	int right = end;
	int temp = a[first];
	while (left < right) {
		while (left < right && a[right] >= temp) {
			right--;
		}
		a[left] = a[right];

		while (left < right && a[left] <= temp) {
			left++;
		}
		a[right] = a[left];
	}

	a[left] = temp;
	quicksort(a, first, left - 1);
	quicksort(a, left + 1, end);
}

VOID swap(INT& a, INT& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void Solution::bubblesort(int *a, int n)
{
	int iCount = 0;
	for (INT i = 0; i < n - 1; i++)
	{
		for (INT j = i + 1; j < n; j++)
		{
			iCount++;
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
	printf("bubblesort iCount=%d\n", iCount);
}

void Solution::bubblesort_Ex(int*a, int n)
{
	int iCount = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			iCount++;
			int ai = a[i];
			int aj = a[j];
			if (a[j] > a[j+1])
			{
				swap(a[j], a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			printf("bubblesort_Ex iCount=%d\n", iCount);
			return;
		}
	}
	printf("bubblesort_Ex iCount=%d\n", iCount);
}

void Solution::bubblesort_Ex2(int*a, int n)
{
	int iCount = 0;
	int k = n - 1;
	int pos = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < k; j++)
		{
			iCount++;
			int ai = a[i];
			int aj = a[j];
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = 1;
				//(记录内循环中的最后一次交换的位置，如果最后一次交换的位置之后都是正序的，就无需再跑循环做比较)
				pos = j;
			}
		}
		k = pos;
		if (flag == 0)
		{
			printf("bubblesort_Ex2 iCount=%d\n", iCount);
			return;
		}
	}
	printf("bubblesort_Ex2 iCount=%d\n", iCount);
}

void Solution::chooseSort(int*a, INT length)
{ 
	int iCount = 0;
	for (INT i = 0; i < length; i++)
	{
		INT min = i;
		for (INT j = i + 1; j < length; j++)
		{
			iCount++;
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(a[min], a[i]);
		}
	}
	printf("chooseSort iCount=%d\n", iCount);
}

void Solution::insertSort(int*a, int n)
{
	int iCount = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j--)
		{
			iCount++;
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
			}
			else
				break;
		}
	}
	printf("insertSort iCount=%d\n", iCount);
}

void Merge(int arr[], int l, int q, int r) {
	//合并两个有序区间{l，q} {q+1, r}
	int n = r - l + 1;//临时数组存合并后的有序序列
	int* tmp = new int[n];
	int i = 0;
	int left = l;
	int right = q + 1;
	while (left <= q && right <= r)
		tmp[i++] = arr[left] <= arr[right] ? arr[left++] : arr[right++];
	while (left <= q) //若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
		tmp[i++] = arr[left++];
	while (right <= r)//同上
		tmp[i++] = arr[right++];
	for (int j = 0; j < n; ++j)  //将排好序的存回arr中low到high这区间
		arr[l + j] = tmp[j];
	delete[] tmp;//删掉堆区的内存
}

void Solution::MergeSort(int arr[], int l, int r) {
	if (l == r)
		return;  //递归基是让数组中的每个数单独成为长度为1的区间
	int q = (l + r) / 2;
	MergeSort(arr, l, q);
	MergeSort(arr, q + 1, r);
	Merge(arr, l, q, r);
}

///////////////////////////////////////////////////////////////////////////////////
//堆排序的核心是建堆,传入参数为数组，根节点位置，数组长度
void Heap_build(int a[], int root, int length)
{
	int lchild = root * 2 + 1;//根节点的左子结点下标
	if (lchild < length)//左子结点下标不能超出数组的长度
	{
		int flag = lchild;//flag保存左右节点中最大值的下标
		int rchild = lchild + 1;//根节点的右子结点下标
		if (rchild < length)//右子结点下标不能超出数组的长度(如果有的话)
		{
			if (a[rchild] > a[flag])//找出左右子结点中的最大值
			{
				flag = rchild;
			}
		}
		if (a[root] < a[flag])
		{
			//交换父结点和比父结点大的最大子节点
			swap(a[root], a[flag]);
			//从此次最大子节点的那个位置开始递归建堆
			Heap_build(a, flag, length);
		}
	}
}

void Solution::heapSort(int a[], int len)
{
	for (int i = len / 2; i >= 0; --i)//从最后一个非叶子节点的父结点开始建堆
	{
		Heap_build(a, i, len);
	}

	for (int j = len - 1; j > 0; --j)//j表示数组此时的长度，因为len长度已经建过了，从len-1开始
	{
		swap(a[0], a[j]);//交换首尾元素,将最大值交换到数组的最后位置保存
		Heap_build(a, 0, j);//去除最后位置的元素重新建堆，此处j表示数组的长度，最后一个位置下标变为len-2
	}
}
////////////////////////////////////////////////////////////////////////////////////////////

static CONST auto io_sync_off = [] {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
};