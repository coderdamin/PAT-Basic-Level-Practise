//问题描述：
//	要获得一个C语言程序的运行时间，常用的方法是调用头文件time.h，其中提供了clock()函数，可以捕捉从程序开始运行到clock()被调用时所耗费的时间。这个时间单位是clock tick，即“时钟打点”。
//	同时还有一个常数CLK_TCK，给出了机器时钟每秒所走的时钟打点数。于是为了获得一个函数f的运行时间，我们只要在调用f之前先调用clock()，获得一个时钟打点数C1；在f执行完成后再调用clock()，获得另一个时钟打点数C2；两次获得的时钟打点数之差(C2 - C1)就是f运行所消耗的时钟打点数，再除以常数CLK_TCK，就得到了以秒为单位的运行时间。
//	这里不妨简单假设常数CLK_TCK为100。现给定被测函数前后两次获得的时钟打点数，请你给出被测函数运行的时间。
//输入格式：
//	输入在一行中顺序给出2个整数C1和C2。注意两次获得的时钟打点数肯定不相同，即C1 < C2，并且取值在[0, 107]。
//输出格式：
//	在一行中输出被测函数运行的时间。运行时间必须按照“hh : mm:ss”（即2位的“时:分:秒”）格式输出；不足1秒的时间四舍五入到秒。
//输入样例：
//	123 4577973
//输出样例：
//	12:42:59

#include <iostream>
#include <iomanip>
using namespace std;

#define CLK_TCK 100
typedef unsigned int UINT32;

int main() {
	UINT32 uC1 = 0, uC2 = 0;
	cin >> uC1 >> uC2;
	uC1 = (uC2 - uC1 + (CLK_TCK >> 1)) / CLK_TCK;
	UINT32 uHour = uC1 / 3600;
	UINT32 uMin = (uC1 % 3600) / 60;
	if (uHour > 0) {
		cout << setfill('0') << setw(2) << uHour << ':';
	}
	if (uHour + uMin > 0) {
		cout << setfill('0') << setw(2) << uMin << ':';
	}
	cout << setfill('0') << setw(2) << (uC1 % 60) << endl;
	return 0;
}
