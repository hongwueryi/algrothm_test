// algrothm_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string_test.h"
#include "algrothms.h"
#include "other.h"
#include <functional>

int main()
{
	double nsprt = sqrt(5);
	COther other;
	INT st = other.sqrt(5);
	other.reverse(-123);
	INT rlcm = other.lcm(18, 12);
	INT rgcd = other.gcd(18, 12);
	INT iCount = other.ContainOne(129);
	/*-------------------------------------------------------*/
	Solution_String SoString_obj;
	BOOL b1 = SoString_obj.PalindRome("abc");
	BOOL b2 = SoString_obj.PalindRome("abcba");
	BOOL b3 = SoString_obj.PalindRome("abcba1");
	
	string strResult = SoString_obj.solve("1234", "5");
	string lcsd = SoString_obj.LCS("helloolleh", "woof");
	INT lens = SoString_obj.LCS_DP("1AB2345CD","12345EF");
	lens = SoString_obj.LCSubsequence_DP("a1234def", "2f3a123a1234");
	lens = SoString_obj.LCSubsequence_DP("a1234", "5");
	string strlcs = SoString_obj.LCSubsequence_DP_str("a1234", "a523");
	vector<INT> vec = { 4,5,3,3,3 };
	INT len = SoString_obj.maxLength(vec);
	char src[5] = "1234";
	SoString_obj.myStrCpy(src + 1, src);
	/*-------------------------------------------------------*/

	Solution soalg;
	INT a[15] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	soalg.bubblesort(a, 15);
	INT b[15] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	soalg.bubblesort_Ex(b, 15);
	//INT c[5] = { 1,5,3,6,7 
	INT c[15] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	soalg.bubblesort_Ex2(c, 15);
	INT d[15] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	soalg.chooseSort(d, 15);
	INT e[15] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	soalg.insertSort(e, 15);
	vector<int>f = { 1,2,3,4,5 };
	INT result = soalg.search(f, 3);
	//INT g[15] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	INT g[5] = { 3,44,38,5,47};
	soalg.MergeSort(g, 0, 4);
	INT h[15] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	soalg.quicksort(h, 0, 14);
	int i[10] = { 12,45,748,12,56,3,89,4,48,2 };
	soalg.heapSort(i, 10);
	/*-------------------------------------------------------*/
    return 0;
}

