//����������
//	һ���Ϸ������֤������17λ���������ڱ�ź�˳���ż�1λУ������ɡ�У����ļ���������£�
//	���ȶ�ǰ17λ���ּ�Ȩ��ͣ�Ȩ�ط���Ϊ��{ 7��9��10��5��8��4��2��1��6��3��7��9��10��5��8��4��2 }��Ȼ�󽫼���ĺͶ�11ȡģ�õ�ֵZ��
//	��������¹�ϵ��ӦZֵ��У����M��ֵ��
//	Z��0 1 2 3 4 5 6 7 8 9 10
//	M��1 0 X 9 8 7 6 5 4 3 2
//	���ڸ���һЩ���֤���룬������֤У�������Ч�ԣ������������ĺ��롣
//�����ʽ��
//	�����һ�и���������N�� <= 100������������֤����ĸ��������N�У�ÿ�и���1��18λ���֤���롣
//�����ʽ��
//	���������˳��ÿ�����1������������֤���롣���ﲢ������ǰ17λ�Ƿ����ֻ���ǰ17λ�Ƿ�ȫΪ���������1λУ�������׼ȷ��
//	������к��붼�������������All passed����
//��������1��
//	4
//	320124198808240056
//	12010X198901011234
//	110108196711301866
//	37070419881216001X
//�������1��
//	12010X198901011234
//	110108196711301866
//	37070419881216001X
//��������2��
//	2
//	320124198808240056
//	110108196711301862
//�������2��
//	All passed

#include <iostream>
using namespace std;

char CheckCodeConvert(int nCheckCode);
int main() {
	const int anWeight[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	int nCount = 0;
	cin >> nCount;
	char(*acID)[19] = new char[nCount][19];
	for (int i = 0; i < nCount; ++i) {
		cin >> acID[i];
	}
	bool bFirst = true;
	bool bAllRight = true;
	int nCheckCode = 0;
	for (int i = 0; i < nCount; ++i) {
		nCheckCode = 0;
		for (int j = 0; j < 17; ++j) {
			if (acID[i][j] >= '0' && acID[i][j] <= '9') {
				nCheckCode += (acID[i][j] - '0') * anWeight[j];
			}
			else {
				nCheckCode = -1;
				break;
			}
		}
		if (nCheckCode == -1
			|| CheckCodeConvert(nCheckCode % 11) != (acID[i][17])) {
			if (bFirst) {
				cout << acID[i];
				bFirst = false;
			}
			else {
				cout << '\n' << acID[i];
			}
			bAllRight = false;
		}
	}
	if (bAllRight) {
		cout << "All passed";
	}
	cout << endl;
	delete[] acID;
	return 0;
}

char CheckCodeConvert(int nCheckCode) {
	static const char acCheckCode[] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	if (nCheckCode < 0 || nCheckCode > 10) {
		return '\0';
	}
	return acCheckCode[nCheckCode];
}
