//����������
//	��ƺ�����һԪ����ʽ�ĵ�������ע��x^n��nΪ��������һ�׵���Ϊn*x^(n-1)����
//�����ʽ��
//	��ָ���ݽ���ʽ�������ʽ������ϵ����ָ��������ֵ��Ϊ������1000�������������ּ��Կո�ָ���
//�����ʽ��
//	����������ͬ�ĸ�ʽ�����������ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո�
//	ע�⡰�����ʽ����ָ����ϵ������0�����Ǳ�ʾΪ��0 0����
//����������
//	3 4 -5 2 6 1 -2 0
//���������
//	12 3 -10 1 6 0

#include <iostream>
using namespace std;

int main() {
	int nCoefficient = 0;
	int nExponent = 0;
	bool bFirst = true;
	while (true) {
		cin >> nCoefficient >> nExponent;
		if (nExponent != 0) {
			if (bFirst) {
				cout << nCoefficient * nExponent << ' ' << nExponent - 1;
				bFirst = false;
			}
			else {
				cout << ' ' << nCoefficient * nExponent << ' ' << nExponent - 1;
			}
		}
		if (getchar() == '\n') {
			break;
		}
	}
	cout << endl;

	return 0;
}
