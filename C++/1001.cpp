//��Ŀ������
//	������(Callatz)���룺
//	���κ�һ����Ȼ��n���������ż������ô��������һ�룻���������������ô��(3n + 1)����һ�롣����һֱ��������ȥ�����һ����ĳһ���õ�n = 1��
//�����ʽ��
//	ÿ�������������1��������������������Ȼ��n��ֵ��
//�����ʽ��
//	�����n���㵽1��Ҫ�Ĳ�����
//����������
//3
//���������
//5

#include <iostream>
using namespace std;

int main() {
	unsigned int utestNumber = 0;
	cin >> utestNumber;
	unsigned int uSteps = 0;
	while (utestNumber != 1) {
		uSteps += 1;
		utestNumber = (utestNumber & 0x00000001) ? (3 * utestNumber + 1) / 2 : utestNumber / 2;
	}
	cout << uSteps << endl;
	return 0;
}
