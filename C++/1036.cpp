//问题描述：
//	美国总统奥巴马不仅呼吁所有人都学习编程，甚至以身作则编写代码，成为美国历史上首位编写计算机代码的总统。2014年底，为庆祝“计算机科学教育周”正式启动，
//	奥巴马编写了很简单的计算机代码：在屏幕上画一个正方形。现在你也跟他一起画吧！
//输入格式：
//	输入在一行中给出正方形边长N（3 <= N <= 20）和组成正方形边的某种字符C，间隔一个空格。
//输出格式：
//	输出由给定字符C画出的正方形。但是注意到行间距比列间距大，所以为了让结果看上去更像正方形，我们输出的行数实际上是列数的50%（四舍五入取整）。
//输入样例：
//	10 a
//输出样例：
//	aaaaaaaaaa
//	a        a
//	a        a
//	a        a
//	aaaaaaaaaa

#include <iostream>
using namespace std;

void DrawLine(int nLen, char cChar);
int main() {
	int nCount = 0;
	char cChar = '\0';
	cin >> nCount >> cChar;
	int nLine = (nCount + 1) >> 1;
	DrawLine(nCount, cChar); cout << '\n';
	for (int i = 1; i < nLine - 1; ++i) {
		cout << cChar; DrawLine(nCount - 2, ' '); cout << cChar << '\n';
	}
	DrawLine(nCount, cChar); cout << endl;
	return 0;
}

void DrawLine(int nLen, char cChar) {
	while (nLen-- > 0) {
		cout << cChar;
	}
}
