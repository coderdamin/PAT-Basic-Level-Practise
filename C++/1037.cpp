//问题描述：
//	如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。
//	”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。
//输入格式：
//	输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。这里Galleon是[0, 107]区间内的整数，Sickle是[0, 17)区间内的整数，Knut是[0, 29)区间内的整数。
//输出格式：
//	在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。
//输入样例1：
//	10.16.27 14.1.28
//输出样例1：
//	3.2.1
//
//输入样例2：
//	14.1.28 10.16.27
//输出样例2：
//	-3.2.1

#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct {
	int nGalleon;
	int nSickle;
	int nKnut;
} HWMoney;

void Solution_1(HWMoney& p, HWMoney& a);
void Solution_2(HWMoney& p, HWMoney& a);
int main() {
	HWMoney p, a;
	scanf_s("%d.%d.%d %d.%d.%d", &p.nGalleon, &p.nSickle, &p.nKnut
		, &a.nGalleon, &a.nSickle, &a.nKnut);
	Solution_1(p, a);
	return 0;
}

void Solution_1(HWMoney& p, HWMoney& a) {
	a.nKnut -= p.nKnut;
	if (a.nKnut < 0) {
		a.nKnut += 29;
		a.nSickle -= 1;
	}
	a.nSickle -= p.nSickle;
	if (a.nSickle < 0) {
		a.nSickle += 17;
		a.nGalleon -= 1;
	}
	a.nGalleon -= p.nGalleon;
	if (a.nGalleon < 0) {
		a.nGalleon += 1;
		a.nSickle = 16 - a.nSickle;
		a.nKnut = 29 - a.nKnut;
	}
	cout << a.nGalleon << '.' << a.nSickle << '.' << a.nKnut << endl;
}

// 换算成nKnut相减在换算回来
void Solution_2(HWMoney& p, HWMoney& a) {

}
