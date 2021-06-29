#pragma once
class Solution_String {
public:
	/**
	* 计算两个数之和
	* @param s string字符串 表示第一个整数
	* @param t string字符串 表示第二个整数
	* @return string字符串
	*/
	string solve(string s, string t);

	//回文判断
	bool PalindRome(string str);

	//最长公共子串
	string LCS(string str1, string str2);
	int LCS_DP(string strt, string strk);
	string LCS_str(string str1, string str2);

	//最长公共子序列
	int LCSubsequence_DP(string strt, string strk);
	string LCSubsequence_DP_str(string strt, string strk);

	//判断是否为合法括号序列(){}[]
	bool isValidBracket(string s);

	//返回arr的最长无的重复子串的长度(无重复指的是所有数字都不相同)
	int maxLength(vector<int>& arr);

	//考虑有内存重叠
	char* myStrCpy(char*dest, char*src);
};