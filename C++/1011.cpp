//����������
//	��������[-2^31, 2^31]�ڵ�3������A��B��C�����ж�A + B�Ƿ����C��
//�����ʽ��
//	�����1�и���������T(<= 10)���ǲ��������ĸ�����������T�����������ÿ��ռһ�У�˳�����A��B��C���������Կո�ָ���
//�����ʽ��
//	��ÿ�������������һ���������Case #X: true�����A + B>C�����������Case #X: false��������X�ǲ��������ı�ţ���1��ʼ����
//����������
//	4
//	1 2 3
//	2 3 4
//	2147483647 0 2147483646
//	0 -2147483648 -2147483647
//���������
//	Case #1: false
//	Case #2: true
//	Case #3: true
//	Case #4: false

#include <iostream>
using namespace std;

int main() {
	int nCount = 0;
	int nNumberA = 0;
	int nNumberB = 0;
	int nNumberC = 0;
	cin >> nCount;
	for (int i = 0; i < nCount; ++i) {
		cin >> nNumberA >> nNumberB >> nNumberC;
		if ((long long)(nNumberA + nNumberB) >(long long)nNumberC) {
			cout << "Case #" << i << ':' << "true";
		}
		else {
			cout << "Case #" << i << ':' << "false";
		}
		if (i < nCount - 1) {
			cout << '\n';
		}
	}
	cout << endl;
	return 0;
}
