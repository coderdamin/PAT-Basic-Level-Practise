// 问题描述：
//     让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），
//     换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。
// 输入格式：
//     每个测试输入包含1个测试用例，给出正整数n（<1000）。
// 输出格式：
//     每个测试用例的输出占一行，用规定的格式输出n。
// 输入样例1：
// 234
// 输出样例1：
// BBSSS1234

// 输入样例2：
// 23
// 输出样例2：
// SS123

#include <iostream>
using namespace std;

int main() {
    //char acInput[4] = {0};
    //cin >> acInput;
	int nInput = 0;
	cin >> nInput;
	if (nInput == 0) {
		cout << 0 << endl;
		return 0;
	}
	int nPart = 0;
	// 百位
	nPart = nInput / 100;
	while (nPart > 0) {
		cout << 'B';
		--nPart;
	}
	// 十位
	nInput = nInput % 100;
	nPart = nInput / 10;
	while (nPart > 0) {
		cout << 'S';
		--nPart;
	}
	// 个位
	nInput = nInput % 10;
	nPart = nInput;
	for (int i = 1; i <= nPart; ++i) {
		cout << i;
	}
	cout << endl;
    return 0;
}
