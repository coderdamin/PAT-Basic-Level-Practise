//问题描述：
//	设计函数求一元多项式的导数。（注：x^n（n为整数）的一阶导数为n*x^(n-1)。）
//输入格式：
//	以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
//输出格式：
//	以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。
//	注意“零多项式”的指数和系数都是0，但是表示为“0 0”。
//输入样例：
//	3 4 -5 2 6 1 -2 0
//输出样例：
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
