//题目描述：
//	卡拉兹(Callatz)猜想：
//	对任何一个自然数n，如果它是偶数，那么把它砍掉一半；如果它是奇数，那么把(3n + 1)砍掉一半。这样一直反复砍下去，最后一定在某一步得到n = 1。
//输入格式：
//	每个测试输入包含1个测试用例，即给出自然数n的值。
//输出格式：
//	输出从n计算到1需要的步数。
//输入样例：
//3
//输出样例：
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
