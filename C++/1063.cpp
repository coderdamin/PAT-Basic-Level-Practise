//��������:
//	����ѧ�У�����ġ��װ뾶����ָ������ֵ��ģ���ϵ���ȷ�硣����֮�����ڸ�����n�������ռ������ֵ{ a1 + b1i, ..., an + bni }��
//	���ǵ�ģΪʵ�����鲿��ƽ���͵Ŀ����������װ뾶���������ģ��
//	���ڸ���һЩ�����ռ������ֵ��������㲢�����Щ����ֵ���װ뾶��
//�����ʽ��
//	�����һ�и���������N�� <= 10000�������������ֵ�ĸ��������N�У�ÿ�и���1������ֵ��ʵ�����鲿������Կո�ָ���
//	ע�⣺��Ŀ��֤ʵ�����鲿��Ϊ����ֵ������1000��������
//�����ʽ��
//	��һ��������װ뾶���������뱣��С�����2λ��
//����������
//	5
//	0 1
//	2 0
//	-1 0
//	3 3
//	0 -3
//���������
//	4.24

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	float fRadius = 0.0f;
	int nCount = 0;
	int nA = 0, nB = 0;
	float fTemp = 0.0f;
	cin >> nCount;
	for (int i = 0; i < nCount; ++i) {
		cin >> nA >> nB;
		fTemp = sqrt(nA * nA + nB * nB);
		if (fTemp > fRadius) {
			fRadius = fTemp;
		}
	}
	cout.setf(ios::fixed);
	cout << setprecision(2) << fRadius << endl;
	return 0;
}