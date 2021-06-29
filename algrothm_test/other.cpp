#include "stdafx.h"
#include "other.h"

long long COther::thenumberof0(long long n)
{
	long long iCount = 0;
	while (n)
	{
		iCount += n / 5;
		n /= 5;
	}
	return iCount;
}

INT COther::ContainOne(INT x)
{
	//二进制中含1的个数
	INT i = 0;
	while (x)
	{
		i++;
		x = x&(x - 1);
	}
	return i;
}

int COther::reverse(int x) 
{
	int res = 0;
	while (x)
	{
		res = res * 10 + (x % 10);
		x /= 10;
	}
	return res;
}

int COther::gcd(int a, int b)
{
	while (b != 0)
	{
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}

int COther::lcm(INT a, INT b)
{
	return a / gcd(a, b)*b;   //最小公倍数=两数之积/最大公约数
	INT max = (a > b ? a:b);
	while (1)
	{
		if (max%a == 0 && max%b == 0)
			return max;
		else
			max++;
	}
}

int COther::sqrt(int x) {
	if (x == 0) {
		return 0;
	}
	if (x < 0) {
		return -1;
	}
	int left = 1, right = x / 2 + 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (x / mid >= mid && x / (mid + 1) < (mid + 1)) {
			return mid;
		}
		else if (x / mid > mid) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return right;
}