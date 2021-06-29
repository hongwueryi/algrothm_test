#pragma once
class COther
{
public:
	COther() {}
	~COther(){}

public:
	//任意一个数的阶乘结果中末尾为0的数量
	long long thenumberof0(long long n);

	//二进制中含1的个数
	INT ContainOne(INT x);
		
	//数字反转  -123 =》 -321
	int COther::reverse(int x);

	//最大公约数
	int gcd(int a, int b);

	//最小公倍数
	int lcm(INT a, INT b);

	//求平方根
	int sqrt(int x);
};

