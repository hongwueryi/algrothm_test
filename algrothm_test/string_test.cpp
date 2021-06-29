#include "stdafx.h"
#include "string_test.h"
#include <unordered_map>
#include <vector>
#include <stack>

string Solution_String::solve(string s, string t) {
	// write code here
	if (s.empty()) return t;
	if (t.empty()) return s;
	if (s.size()<t.size()) swap(t, s);
	int tail = s.size() - t.size();
	int carry = 0, tmp = 0;
	while (tail--) t = '0' + t;
	for (int i = s.size() - 1; i >= 0; i--) {
		tmp = s[i] - '0' + t[i] - '0' + carry;
		if (tmp >= 10) {
			carry = 1;
			tmp -= 10;
		}
		else {
			carry = 0;
		}
		s[i] = tmp + '0';
	}
	if (carry) s = '1' + s;
	return s;
}

bool Solution_String::PalindRome(string str)
{
	if (str.empty() || str.length() == 1)
		return true;

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] != str[str.length() - 1 - i])
			return false;
	}
	return true;
}

string Solution_String::LCS(string str1, string str2)
{
	// write code here
	int i, j, s1l = str1.length(), s2l = str2.length();
	if (s1l == 0 || s2l == 0) return "";
	string& min = s1l<s2l ? str1 : str2;
	string& max = s1l<s2l ? str2 : str1;
	std::unordered_map<char, vector<int>> mp;
	for (i = 0; i<min.length(); i++)
	{
		mp[min[i]].push_back(i);
	}
	int maxL = 0, index = 0;
	for (i = 0; i<max.length(); i++)
	{
		if (!mp.count(max[i]))
			continue;
		for (auto& it : mp[max[i]])
		{
			int len = 0, temp = i;
			while (temp<max.length() && it + len<min.length() && max[temp] == min[it + len])
			{
				temp++;
				len++;
			}
			if (len>maxL)
			{
				maxL = len;
				index = i;
			}
		}
	}
	return max.substr(index, maxL);
}

int Solution_String::LCS_DP(string strt, string strk)
{
	CONST INT tlen = strt.length();
	CONST INT klen = strk.length();
	int dp[100][100];
	INT result = 0;
	int it = 0;
	int ik = 0;
	string strRes;
	for (INT t = 0; t < tlen; t++)
	{
		for (INT k = 0; k < klen; k++)
		{
			if (strt[t] == strk[k])
			{
				if (t == 0 || k == 0)
				{
					dp[t][k] = 1;
				}
				else
				{
					dp[t][k] = dp[t - 1][k - 1] + 1;
				}
// 				if (dp[t][k] > result)
// 				{
// 					strRes.push_back(strk[k]);
// 				}
				result = max(dp[t][k], result);
				
			}
			else
			{
				dp[t][k] = 0;
			}
		}
	}
	return result;
}

int Solution_String::LCSubsequence_DP(string strt, string strk)
{
	INT lent = strt.length();
	INT lenk = strk.length();
	int dp[100][100];
	INT result = 0;
	for (INT t = 0; t < lent; t++)
	{
		for (INT k = 0; k < lenk; k++)
		{
			if (strt[t] == strk[k])
			{
				if (t == 0 || k == 0)
				{
					dp[t][k] = 1;
				}
				else if (strt[t - 1] = strk[k - 1])
				{
					dp[t][k] = dp[t - 1][k - 1] + 1;
				}
				result = max(result, dp[t][k]);
			}
			else
			{
				dp[t][k] = max(dp[t][k - 1], dp[t - 1][k]);
			}
			
		}
	}
	return result;
}

string Solution_String::LCSubsequence_DP_str(string strt, string strk)
{
	INT lent = strt.length();
	INT lenk = strk.length();
	INT dp[100][100] = { 0 };
	for (INT t = 1; t <= lent; t++)
	{
		for (INT k = 1; k <= lenk; k++)
		{
			if (strt[t - 1] == strk[k - 1])
			{
				dp[t][k] = dp[t - 1][k - 1] + 1;
			}
			else
			{
				dp[t][k] = max(dp[t - 1][k], dp[t][k - 1]);
			}
		}
	}

	INT i = lent;
	INT j = lenk;
	string strRes;
	while (dp[i][j])
	{
		if (dp[i][j] == dp[i - 1][j])
		{
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1])
		{
			j--;
		}
		else if (dp[i][j] > dp[i - 1][j - 1])
		{
			i--;
			j--;
			strRes.push_back(strt[i]);
		}
	}
	
	if (!strRes.empty())
	{
		std::reverse(strRes.begin(), strRes.end());
	}
	return strRes;
}

string Solution_String::LCS_str(string str1, string str2)
{
	int tlen = str1.length();
	int klen = str2.length();
	int maxlen = 0;
	int index = 0;
	for (int t = 0; t < tlen; t++)
	{
		for (int k = 0; k < klen; k++)
		{
			if (str1[t] == str2[k])
			{
				int pos;
				for (pos = 1; t + pos < tlen && k + pos < klen; ++pos)
				{
					if (str1[t + pos] != str2[k + pos])
						break;
				}
				if (pos > maxlen)
				{
					maxlen = pos;
					index = t;
				}
			}
		}
	}
	return str1.substr(index, maxlen);
}

bool Solution_String::isValidBracket(string s)
{
	stack<char>stack_bracket; 
	for (int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
		case '(':
			stack_bracket.push('(');
			break;
		case '{':
			stack_bracket.push('{');
			break;
		case '[':
			stack_bracket.push('[');
			break;
		case ')':
			if (stack_bracket.empty() || stack_bracket.top() != '(')
				return false;
			stack_bracket.pop();
			break;
		case '}':
			if (stack_bracket.empty() || stack_bracket.top() != '{')
				return false;
			stack_bracket.pop();
			break;
		case ']':
			if (stack_bracket.empty() || stack_bracket.top() != '[')
				return false;
			stack_bracket.pop();
			break;
		default:
			break;
		}
	}
}

int Solution_String::maxLength(vector<int>& arr) {
	// write code here
	if (arr.size() == 0) return 0;
	vector<int> v(100000);
	int res = 0, i = 0, j = 0;
	while (j < arr.size()) 
	{
		int pos = arr[j];
		if (v[arr[j]] == 0)
		{
			v[arr[j]] = 1;
			res = max(res, j - i + 1);
			j++;
		}
		else
		{
			int posi = arr[i];
			v[arr[i]] = 0;
			i++;
		}
	}
	return res;
}

char* Solution_String::myStrCpy(char*dest, char*src)
{
	if (dest == nullptr || src == nullptr)
		return nullptr;
	if (dest == src)
		return dest;
	INT len = strlen(src);
	if (dest < src || src + len <= dest)
	{
		//内存无重叠
		char* d = dest;
		char* s = src;
		while (len--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		//内存有重叠
		char*d = dest + len - 1;
		char*s = src + len - 1;
		while (len--)
		{
			*d-- = *s--;
		}
	}
	return dest;
}

