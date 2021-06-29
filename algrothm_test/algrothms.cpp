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
				//(��¼��ѭ���е����һ�ν�����λ�ã�������һ�ν�����λ��֮��������ģ�����������ѭ�����Ƚ�)
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
	//�ϲ�������������{l��q} {q+1, r}
	int n = r - l + 1;//��ʱ�����ϲ������������
	int* tmp = new int[n];
	int i = 0;
	int left = l;
	int right = q + 1;
	while (left <= q && right <= r)
		tmp[i++] = arr[left] <= arr[right] ? arr[left++] : arr[right++];
	while (left <= q) //���Ƚ���֮�󣬵�һ������������ʣ�࣬��ֱ�Ӹ��Ƶ�t������
		tmp[i++] = arr[left++];
	while (right <= r)//ͬ��
		tmp[i++] = arr[right++];
	for (int j = 0; j < n; ++j)  //���ź���Ĵ��arr��low��high������
		arr[l + j] = tmp[j];
	delete[] tmp;//ɾ���������ڴ�
}

void Solution::MergeSort(int arr[], int l, int r) {
	if (l == r)
		return;  //�ݹ�����������е�ÿ����������Ϊ����Ϊ1������
	int q = (l + r) / 2;
	MergeSort(arr, l, q);
	MergeSort(arr, q + 1, r);
	Merge(arr, l, q, r);
}

///////////////////////////////////////////////////////////////////////////////////
//������ĺ����ǽ���,�������Ϊ���飬���ڵ�λ�ã����鳤��
void Heap_build(int a[], int root, int length)
{
	int lchild = root * 2 + 1;//���ڵ�����ӽ���±�
	if (lchild < length)//���ӽ���±겻�ܳ�������ĳ���
	{
		int flag = lchild;//flag�������ҽڵ������ֵ���±�
		int rchild = lchild + 1;//���ڵ�����ӽ���±�
		if (rchild < length)//���ӽ���±겻�ܳ�������ĳ���(����еĻ�)
		{
			if (a[rchild] > a[flag])//�ҳ������ӽ���е����ֵ
			{
				flag = rchild;
			}
		}
		if (a[root] < a[flag])
		{
			//���������ͱȸ����������ӽڵ�
			swap(a[root], a[flag]);
			//�Ӵ˴�����ӽڵ���Ǹ�λ�ÿ�ʼ�ݹ齨��
			Heap_build(a, flag, length);
		}
	}
}

void Solution::heapSort(int a[], int len)
{
	for (int i = len / 2; i >= 0; --i)//�����һ����Ҷ�ӽڵ�ĸ���㿪ʼ����
	{
		Heap_build(a, i, len);
	}

	for (int j = len - 1; j > 0; --j)//j��ʾ�����ʱ�ĳ��ȣ���Ϊlen�����Ѿ������ˣ���len-1��ʼ
	{
		swap(a[0], a[j]);//������βԪ��,�����ֵ��������������λ�ñ���
		Heap_build(a, 0, j);//ȥ�����λ�õ�Ԫ�����½��ѣ��˴�j��ʾ����ĳ��ȣ����һ��λ���±��Ϊlen-2
	}
}
////////////////////////////////////////////////////////////////////////////////////////////

static CONST auto io_sync_off = [] {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
};