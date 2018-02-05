//问题描述：
//	小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？
//	如果是，那么告诉她有多少多余的珠子；如果不是，那么告诉她缺了多少珠子。
//	为方便起见，我们用[0 - 9]、[a - z]、[A - Z]范围内的字符来表示颜色。例如在图1中，第3串是小红想做的珠串；那么第1串可以买，因为包含了全部她想要的珠子，
//	还多了8颗不需要的珠子；第2串不能买，因为没有黑色珠子，并且少了一颗红色的珠子。
//输入格式：
//	每个输入包含1个测试用例。每个测试用例分别在2行中先后给出摊主的珠串和小红想做的珠串，两串都不超过1000个珠子。
//输出格式：
//	如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；如果不可以买，则在一行中输出“No”以及缺了多少珠子。其间以1个空格分隔。
//输入样例1：
//	ppRYYGrrYBR2258
//	YrR8RrY
//输出样例1：
//	Yes 8
//输入样例2：
//	ppRYYGrrYB225
//	YrR8RrY
//输出样例2：
//	No 2

#include <iostream>
using namespace std;

typedef unsigned char UINT8;
typedef unsigned int UINT32;

UINT32 GetColorToIndex(UINT8 uColor);
int main() {
	UINT8 auColor[62] = { 0 };
	char cTemp = '\0';
	UINT32 uIndex = 0;
	while ((cTemp = getchar()) != '\n') {
		uIndex = GetColorToIndex(cTemp);
		if (uIndex != -1) {
			auColor[uIndex] += 1;
		}
	}
	UINT32 uLackCount = 0;
	while ((cTemp = getchar()) != '\n') {
		uIndex = GetColorToIndex(cTemp);
		if (uIndex == -1) {
			continue;
		}
		if (auColor[uIndex] > 0) {
			auColor[uIndex] -= 1;
		}
		else{
			uLackCount += 1;
		}
	}
	if (uLackCount == 0) {
		UINT32 uLeftCount = 0;
		for (int i = 0; i < 62; ++i) {
			uLeftCount += auColor[i];
		}
		cout << "Yes " << uLeftCount << endl;
	}
	else{
		cout << "No " << uLackCount << endl;
	}
	return 0;
}

UINT32 GetColorToIndex(UINT8 uColor) {
	//[0 - 9]
	if (uColor >= '0' && uColor <= '9') {
		return uColor - '0';
	}
	//[a - z]
	else if (uColor >= 'a' && uColor <= 'z'){
		return uColor - 'a' + 10;
	}
	//[A - Z]
	else if (uColor >= 'A' && uColor <= 'Z'){
		return uColor - 'A' + 36;
	}
	return -1;
}
