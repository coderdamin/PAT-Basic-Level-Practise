//问题描述：
//	萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：
//	[左手]([左眼][口][右眼])[右手]
//	现给出可选用的符号集合，请你按用户的要求输出表情。
//输入格式：
//	输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号[]内。题目保证每个集合都至少有一个符号，并不超过10个符号；每个符号包含1到4个非空字符。
//	之后一行给出一个正整数K，为用户请求的个数。随后K行，每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从1开始），数字间以空格分隔。
//输出格式：
//	对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出“Are you kidding me ? @\ / @”。
//输入样例：
//	[╮][╭][o][~\][/ ~][<][>]
//	[╯][╰][^][-][=][>][<][@][⊙]
//	[Д][▽][_][ε][^]  ...
//	4
//	1 1 2 2 2
//	6 8 1 5 5
//	3 3 4 3 3
//	2 10 3 9 3
//输出样例：
//	╮(╯▽╰)╭
//	<(@Д=)/ ~
//	o(^ε^)o
//	Are you kidding me? @\/@

#include <iostream>
using namespace std;

void CollectPart(char(*acCollection)[5]);
int main() {
	char acHand[10][5] = { 0 };
	char acEye[10][5] = { 0 };
	char acMouth[10][5] = { 0 };
	CollectPart(acHand);
	CollectPart(acEye);
	CollectPart(acMouth);

	int nCount = 0;
	cin >> nCount;
	int(*anEmojiInfo)[5] = new int[nCount][5];
	int nTemp = 0;
	for (int i = 0; i < nCount; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> nTemp;
			anEmojiInfo[i][j] = nTemp - 1;
		}
	}

	//左手、左眼、口、右眼、右手
	for (int i = 0; i < nCount; ++i) {
		if (i > 0) {
			cout << '\n';
		}
		if ((acHand[anEmojiInfo[i][0]][0] == '\0')
			|| (acEye[anEmojiInfo[i][1]][0] == '\0')
			|| (acMouth[anEmojiInfo[i][2]][0] == '\0')
			|| (acEye[anEmojiInfo[i][3]][0] == '\0')
			|| (acHand[anEmojiInfo[i][4]][0] == '\0')) {
			cout << "Are you kidding me? @\\/@";
			continue;
		}
		//[左手]([左眼][口][右眼])[右手]
		cout << acHand[anEmojiInfo[i][0]];
		cout << '(' << acEye[anEmojiInfo[i][1]] << acMouth[anEmojiInfo[i][2]] << acEye[anEmojiInfo[i][3]] << ')';
		cout << acHand[anEmojiInfo[i][4]];
	}

	delete[] anEmojiInfo;
	return 0;
}

void CollectPart(char(*acCollection)[5]) {
	char cTemp = '\0';
	int nRow = 0;
	int nIndex = 0;
	bool bCollecting = false;
	while ((cTemp = getchar()) != '\n') {
		if (cTemp == '[') {
			nIndex = 0;
			bCollecting = true;
		}
		else if (cTemp == ']') {
			nRow += 1;
			bCollecting = false;
		}
		//else if (cTemp != ' ' && bBegin) {
		else if (bCollecting) {
			acCollection[nRow][nIndex++] = cTemp;
		}
	}
}
