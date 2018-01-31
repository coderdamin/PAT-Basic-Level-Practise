//问题描述：
//	正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
//	现给定A、DA、B、DB，请编写程序计算PA + PB。
//输入格式：
//	输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 10^10。
//输出格式：
//	在一行中输出PA + PB的值。
//输入样例1：
//	3862767 6 13530293 3
//输出样例1：
//	399
//
//输入样例2：
//	3862767 1 13530293 8
//输出样例2：
//	0

#include <iostream>
using namespace std;

typedef unsigned char UINT8;

int GetDPart(int nNumber, UINT8 nD);
int main() {
	int nA = 0;
	int nDA = 0;
	int nB = 0;
	int nDB = 0;
	cin >> nA >> nDA >> nB >> nDB;
	cout << GetDPart(nA, nDA) + GetDPart(nB, nDB) << endl;
	return 0;
}

int GetDPart(int nNumber, UINT8 nD) {
	if (nNumber == 0 || nD == 0) {
		return 0;
	}
	if (nD >= 10) {
		return 0;
	}
	int nRetNumber = 0;
	UINT8 uRemainder = 0;
	while (nNumber != 0) {
		uRemainder = nNumber % 10;
		nNumber /= 10;
		if (uRemainder == nD) {
			nRetNumber = nRetNumber * 10 + uRemainder;
		}
	}
	return nRetNumber;
}
