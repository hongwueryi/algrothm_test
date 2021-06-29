#include "stdafx.h"
#include "array.h"

void Solution_Array::merge(int A[], int m, int B[], int n)
{
	int len = m + n - 1;
	int am = m - 1;
	int an = n - 1;
	while (am >= 0 && an >= 0)
	{
		A[len--] = A[am] > B[an] ? A[am--] : B[an--];
	}
	while (an >= 0)
	{
		A[len--] = B[an--];
	}
}

vector<int> Solution_Array::GetLeastNumbers_Solution(vector<int> input, int k)
{
	vector<int>temp;
	int len = input.size();
	if (k > len)
		return temp;
	for (int i = 0; i < k; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (input[min] > input[j])
				min = j;
		}
		if (min != i)
			swap(input[min], input[i]);
		temp.push_back(input[i]);
	}
	return temp;
}