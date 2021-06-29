#pragma once

class Solution {
public:
	/**
	* ��ʵ�����ظ����ֵ���������Ķ��ֲ���
	* 
	* ���Ŀ��ֵ���ڷ����±꣬���򷵻� -1
	* @param nums int����vector
	* @param target int����
	* @return int����
	*/
	int search(vector<int>& nums, int target);

	//�������
	void quicksort(int a[], int first, INT end);
	//����ð��
	void bubblesort(int *a, int n);
	//����ð���Ż�
	void bubblesort_Ex(int *a, int n);
	//����ð���Ż�2
	void bubblesort_Ex2(int *a, int n);
	//ѡ������
	void chooseSort(int*a, INT n);
	//ֱ�Ӳ�������
	void insertSort(int*a, int n);
	//�鲢����
	void MergeSort(int arr[], int l, int r);
	//������
	void heapSort(int a[], int len);
};