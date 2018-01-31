//问题描述：
//	大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：
//	现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
//输入格式：
//	输入第1行给出正整数N（ <= 105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。
//	C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
//输出格式：
//	输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。
//输入样例：
//	10
//	C J
//	J B
//	C B
//	B B
//	B C
//	C C
//	C B
//	J B
//	B C
//	J J
//输出样例：
//	5 3 2
//	2 3 5
//	B B

#include <iostream>
using namespace std;

int MoraToIndex(char cMora);
int main() {
	int nCount = 0;
	char cMora1 = '\0';
	char cMora2 = '\0';
	int anStat1[2] = { 0 };
	int anStat2[2] = { 0 };
	int anStatMora[2][3] = { 0 };
	cin >> nCount;
	for (int i = 0; i < nCount; ++i){
		cin >> cMora1 >> cMora2;
		if (cMora1 == cMora2) {
			anStat1[1] += 1;
			anStat2[1] += 1;
		}
		// B代表“布” C代表“锤子” J代表“剪刀”
		else if ((cMora1 == 'J' && cMora2 == 'B')
			|| (cMora1 < cMora2)){
			anStat1[0] += 1;
			anStatMora[0][MoraToIndex(cMora1)] += 1;
		}
		else{
			anStat2[0] += 1;
			anStatMora[1][MoraToIndex(cMora2)] += 1;
		}
	}
	cout << anStat1[0] << ' ' << anStat1[1] << ' ' << nCount - anStat1[0] - anStat1[1] << '\n';
	cout << anStat2[0] << ' ' << anStat2[1] << ' ' << nCount - anStat2[0] - anStat2[1] << '\n';
	char aMora[] = { 'B', 'C', 'J' };
	int nWinIndex1 = anStatMora[0][0] >= anStatMora[0][1] ? 0 : (anStatMora[0][1] >= anStatMora[0][2] ? 1 : 2);
	int nWinIndex2 = anStatMora[1][0] >= anStatMora[1][1] ? 0 : (anStatMora[1][1] >= anStatMora[1][2] ? 1 : 2);
	cout << aMora[nWinIndex1] << ' ' << aMora[nWinIndex2] << endl;
	return 0;
}

int MoraToIndex(char cMora) {
	if (cMora == 'B') {
		return 0;
	}
	else if (cMora == 'C') {
		return 1;
	}
	else {
		return 2;
	}
}