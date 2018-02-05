//����������
//	��������д��(A + Bi)�ĳ�����ʽ������A��ʵ����B���鲿��i��������λ������i2 = -1��Ҳ����д�ɼ������µ�ָ����ʽ(R*e(Pi))��
//	����R�Ǹ���ģ��P�Ƿ��ǣ�i��������λ����ȼ���������ʽ R(cos(P) + isin(P))��
//	�ָ�������������R��P��Ҫ����������˻��ĳ�����ʽ��
//�����ʽ��
//	������һ�������θ�������������R1, P1, R2, P2�����ּ��Կո�ָ���
//�����ʽ��
//	��һ���а��ա�A + Bi���ĸ�ʽ��������˻��ĳ�����ʽ��ʵ�����鲿������2λС����ע�⣺���B�Ǹ�������Ӧ��д�ɡ�A - | B | i������ʽ��
//����������
//	2.3 3.5 5.2 0.4
//���������
//	-8.68-8.23i

#include <iostream>
#include <iomanip>
using namespace std;

class ComplexNumber {
public:
	ComplexNumber() {
		m_fRealPart = 0;
		m_fImaginaryPart = 0;
	}
	ComplexNumber(float fR, float fP) {
		m_fRealPart = fR * cos(fP);
		m_fImaginaryPart = fR * sin(fP);
	}
	~ComplexNumber() {}
public:
	//ComplexNumber operator+(ComplexNumber&) {}
	//ComplexNumber operator-(ComplexNumber&) {}
	//ComplexNumber operator/(ComplexNumber&) {}
	ComplexNumber operator*(ComplexNumber& number) {
		ComplexNumber result;
		result.m_fRealPart = number.m_fRealPart * m_fRealPart - number.m_fImaginaryPart * m_fImaginaryPart;
		result.m_fImaginaryPart = m_fRealPart * number.m_fImaginaryPart + number.m_fRealPart * m_fImaginaryPart;
		return result;
	}
public:
	float m_fRealPart;
	float m_fImaginaryPart;
};

int main() {
	float fR, fP;
	cin >> fR >> fP;
	ComplexNumber number1(fR, fP);
	cin >> fR >> fP;
	ComplexNumber number2(fR, fP);

	ComplexNumber result = number1 * number2;
	cout.setf(ios::fixed);
	cout << setprecision(2) << result.m_fRealPart << result.m_fImaginaryPart << 'i' << endl;
	return 0;
}