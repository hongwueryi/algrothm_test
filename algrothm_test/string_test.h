#pragma once
class Solution_String {
public:
	/**
	* ����������֮��
	* @param s string�ַ��� ��ʾ��һ������
	* @param t string�ַ��� ��ʾ�ڶ�������
	* @return string�ַ���
	*/
	string solve(string s, string t);

	//�����ж�
	bool PalindRome(string str);

	//������Ӵ�
	string LCS(string str1, string str2);
	int LCS_DP(string strt, string strk);
	string LCS_str(string str1, string str2);

	//�����������
	int LCSubsequence_DP(string strt, string strk);
	string LCSubsequence_DP_str(string strt, string strk);

	//�ж��Ƿ�Ϊ�Ϸ���������(){}[]
	bool isValidBracket(string s);

	//����arr����޵��ظ��Ӵ��ĳ���(���ظ�ָ�����������ֶ�����ͬ)
	int maxLength(vector<int>& arr);

	//�������ڴ��ص�
	char* myStrCpy(char*dest, char*src);
};