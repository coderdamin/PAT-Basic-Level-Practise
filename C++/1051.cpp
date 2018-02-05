//问题描述：
//	复数可以写成(A + Bi)的常规形式，其中A是实部，B是虚部，i是虚数单位，满足i2 = -1；也可以写成极坐标下的指数形式(R*e(Pi))，
//	其中R是复数模，P是辐角，i是虚数单位，其等价于三角形式 R(cos(P) + isin(P))。
//	现给定两个复数的R和P，要求输出两数乘积的常规形式。
//输入格式：
//	输入在一行中依次给出两个复数的R1, P1, R2, P2，数字间以空格分隔。
//输出格式：
//	在一行中按照“A + Bi”的格式输出两数乘积的常规形式，实部和虚部均保留2位小数。注意：如果B是负数，则应该写成“A - | B | i”的形式。
//输入样例：
//	2.3 3.5 5.2 0.4
//输出样例：
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