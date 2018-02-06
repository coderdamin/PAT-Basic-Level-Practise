//����������
//	����Ļ���Ҫ��ǳ��򵥣�����N��ʵ�����������ǵ�ƽ��ֵ�������ӵ�����Щ�������ݿ����ǷǷ��ġ�һ�����Ϸ�����������[-1000��1000]�����ڵ�ʵ����
//	������ྫȷ��С�����2λ���������ƽ��ֵ��ʱ�򣬲��ܰ���Щ�Ƿ������������ڡ�
//�����ʽ��
//	�����һ�и���������N�� <= 100�������һ�и���N��ʵ�������ּ���һ���ո�ָ���
//�����ʽ��
//	��ÿ���Ƿ����룬��һ���������ERROR : X is not a legal number��������X�����롣�����һ��������������The average of K numbers is Y����
//	����K�ǺϷ�����ĸ�����Y�����ǵ�ƽ��ֵ����ȷ��С�����2λ�����ƽ��ֵ�޷����㣬���á�Undefined���滻Y�����KΪ1���������The average of 1 number is Y����
//��������1��
//	7
//	5 -3.2 aaa 9999 2.3.4 7.123 2.35
//�������1��
//	ERROR : aaa is not a legal number
//	ERROR : 9999 is not a legal number
//	ERROR : 2.3.4 is not a legal number
//	ERROR : 7.123 is not a legal number
//	The average of 3 numbers is 1.38
//��������2��
//	2
//	aaa - 9999
//�������2��
//	ERROR : aaa is not a legal number
//	ERROR : -9999 is not a legal number
//	The average of 0 numbers is Undefined

#include <iostream>
#include <iomanip>
using namespace std;

bool StringToFloat(char* pStr, float& fResult);
int main() {
	int nCount = 0;
	cin >> nCount;
	char(*acNumber)[16] = new char[nCount][16];
	for (int i = 0; i < nCount; ++i) {
		cin >> acNumber[i];
	}
	int nValidCount = 0;
	float fSum = 0.0f;
	float fValue = 0.0f;
	bool bValid = true;
	for (int i = 0; i < nCount; ++i) {
		bValid = false;
		if (StringToFloat(acNumber[i], fValue)) {
			if (fValue >= -1000 && fValue <= 1000) {
				nValidCount += 1;
				fSum += fValue;
				bValid = true;
			}
		}
		if (!bValid) {
			cout << "ERROR : " << acNumber[i] << " is not a legal number\n";
		}
	}
	cout << "The average of " << nValidCount;
	cout.setf(ios::fixed);
	if (nValidCount == 0) {
		cout << " number is Undefined" << endl;
	}
	else if (nValidCount == 1) {
		cout << " number is " << setprecision(2) << fSum << endl;
	}
	else {
		cout << " numbers is " << setprecision(2) << fSum / (float)nValidCount << endl;
	}
	delete[] acNumber;
	return 0;
}

bool StringToFloat(char* pStr, float& fResult) {
	fResult = 0.0f;
	if (pStr == nullptr) {
		return false;
	}
	// ȥ�ո�
	while (*pStr == ' ') { ++pStr; }
	if (*pStr != '+' && *pStr != '-'
		&& (*pStr < '0' || *pStr > '9')) {
		return false;
	}

	// ����
	int nSign = (*pStr == '-') ? -1 : 1;
	if (*pStr == '+' || *pStr == '-') {
		pStr += 1;
	}
	// ����
	bool bInvalid = true;
	int nIntegerPart = 0;
	while (*pStr != '\0') {
		if (*pStr == ' ') {
			pStr += 1;
			continue;
		}
		else if (*pStr == '.') {
			pStr += 1;
			break;
		}
		else if (*pStr >= '0' && *pStr <= '9') {
			bInvalid = false;
			nIntegerPart = nIntegerPart * 10 + (*pStr - '0');
			pStr += 1;
		}
		else {
			bInvalid = true;
			goto END_CONVERT;
		}
	}
	// С��
	float fFractionalPart = 0.0f;
	float fBase = 0.1f;
	while (*pStr != '\0') {
		if (*pStr == ' ') {
			pStr += 1;
			continue;
		}
		else if (*pStr >= '0' && *pStr <= '9') {
			fFractionalPart = fFractionalPart + (*pStr - '0') * fBase;
			fBase /= 10.0f;
			pStr += 1;
		}
		else {
			bInvalid = true;
			goto END_CONVERT;
		}
	}
	if (fBase < 0.0005) {
		bInvalid = true;
	}
END_CONVERT:
	if (bInvalid) {
		return false;
	}
	else {
		fResult = (nIntegerPart + fFractionalPart)*nSign;
		return true;
	}
}
