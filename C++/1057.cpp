//问题描述：
//	给定一串长度不超过105的字符串，本题要求你将其中所有英文字母的序号（字母a - z对应序号1 - 26，不分大小写）相加，得到整数N，
//	然后再分析一下N的二进制表示中有多少0、多少1。例如给定字符串“PAT(Basic)”，其字母序号之和为：16 + 1 + 20 + 2 + 1 + 19 + 9 + 3 = 71，而71的二进制是1000111，即有3个0、4个1。
//输入格式：
//	输入在一行中给出长度不超过105、以回车结束的字符串。
//输出格式：
//	在一行中先后输出0的个数和1的个数，其间以空格分隔。
//输入样例：
//	PAT(Basic)
//输出样例：
//	3 4

#include <iostream>
using namespace std;

int main() {
	char cTemp = '\0';
	unsigned int uNumber = 0;
	while ((cTemp = getchar()) != '\n') {
		if (cTemp >= 'a' && cTemp <= 'z') {
			uNumber += (cTemp - 'a' + 1);
		}
		else if (cTemp >= 'A' && cTemp <= 'Z') {
			uNumber += (cTemp - 'A' + 1);
		}
	}
	unsigned int uZeroCount = 0;
	unsigned int uOneCount = 0;
	while (uNumber != 0) {
		if (uNumber & 0x00000001) {
			uOneCount += 1;
		}
		else {
			uZeroCount += 1;
		}
		uNumber = uNumber >> 1;
	}
	cout << uZeroCount << ' ' << uOneCount << endl;
	return 0;
}
