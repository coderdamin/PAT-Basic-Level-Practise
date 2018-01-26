//��Ŀ������
//	1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
//	2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
//	3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
//�����ʽ��
//	ÿ�������������1��������������1�и���һ����Ȼ��n(<10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�
//�����ʽ��
//	ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ���������YES���������NO��
//����������
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
//���������
//YES
//YES
//YES
//YES
//NO
//NO
//NO
//NO
//�⣺
//����2. 3.�ɵ�a,b,c��ϵ��
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
