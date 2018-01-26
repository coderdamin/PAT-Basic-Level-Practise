//题目描述：
//	1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
//	2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
//	3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
//输入格式：
//	每个测试输入包含1个测试用例。第1行给出一个自然数n(<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。
//输出格式：
//	每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。
//输入样例：
//8
//PAT
//PAAT
//AAPATAA
//AAPAATAAAA
//xPATx
//PT
//Whatever
//APAAATAA
//
//输出样例：
//YES
//YES
//YES
//YES
//NO
//NO
//NO
//NO
//解：
//根据2. 3.可得a,b,c关系：
//PAT ==> (a)PAT(a) ==>(a)P(b)T(a)==>(a)P(b)AT(a)(a)==>(a)P(bA)T(aa)==>(a)P(bA)AT(aa)(a)   (b == A)
//	==> C = (B + 1) * A
// APAAATAA <=/= (A)P(AA)AT(AA)A <== (A)P(AA)T(AA) <== APATA

#include <iostream>
using namespace std;

typedef char INT8;
typedef unsigned char UINT8;

bool CheckPATStr(const char* str);
int main() {
	int nCount = 0;
	cin >> nCount;
	if (nCount == 0) {
		return 0;
	}
	char aInput[101] = { 0 };
	cin >> aInput;
	if (CheckPATStr(aInput)) {
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	for (int i = 1; i < nCount; ++i){
		cin >> aInput;
		if (CheckPATStr(aInput)) {
			cout << "\nYES";
		}
		else{
			cout << "\nNO";
		}
	}
	cout << endl;

	return 0;
}

bool CheckPATStr(const char* str) {
	bool bRight = true;
	bool bHadP = false;
	bool bHadT = false;

	UINT8 uSerialA = 0;
	INT8 nCountPartA = 0;
	INT8 nCountPartB = 0;
	// sprintf("%sP%sAT%S",&a,&b,&c)
	while (*str != '\0') {
		switch (*str) {
		case 'P':
			if (bHadP) {
				bRight = false;
			}
			else{
				nCountPartA = uSerialA;
				uSerialA = 0;
			}
			break;
		case 'A':
			uSerialA += 1;
			break;
		case 'T':
			if (bHadT) {
				bRight = false;
			}
			else{
				nCountPartB = uSerialA - 1;
				uSerialA = 0;
			}
			break;
		default:
			bRight = false;
			break;
		}
		if (!bRight) {
			break;
		}
		str++;
	}
	if (bRight) {
		//C = (B + 1) * A
		bRight = (nCountPartB >= 0) && (uSerialA == nCountPartA * (nCountPartB + 1));
	}
	return bRight;
}
