//问题描述：
//	下面是微博上流传的一张照片：“各位亲爱的同学们，鉴于大家有时需要使用wifi，又怕耽误亲们的学习，现将wifi密码设置为下列数学题答案：
//	A-1；B-2；C-3；D-4；请同学们自己作答，每两日一换。谢谢合作！！~”—— 老师们为了促进学生学习也是拼了…… 
//	本题就要求你写程序把一系列题目的答案按照卷子上给出的对应关系翻译成wifi的密码。这里简单假设每道选择题都有4个选项，有且只有1个正确答案。
//输入格式：
//	输入第一行给出一个正整数N（ <= 100），随后N行，每行按照“编号-答案”的格式给出一道题的4个选项，“T”表示正确选项，“F”表示错误选项。
//	选项间用空格分隔。
//输出格式：
//	在一行中输出wifi密码。
//输入样例：
//	8
//	A-T B-F C-F D-F
//	C-T B-F A-F D-F
//	A-F D-F C-F B-T
//	B-T A-F C-F D-F
//	B-F D-T A-F C-F
//	A-T C-F B-F D-F
//	D-T B-F C-F A-F
//	C-T A-F B-F D-F
//输出样例：
//	13224143

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int nCount = 0;
	cin >> nCount;
	char* acPassword = new char[nCount + 1];
	char cChoose, cRight;
	int nTagNumber = 0;
	for (int i = 0; i < nCount; ++i) {
		nTagNumber = 0;
		for (int j = 0; j < 4; ++j) {
			cin.ignore();
			scanf("%c-%c", &cChoose, &cRight);
			if ((nTagNumber == 0) && (cRight == 'T')) {
				nTagNumber = cChoose - 'A' + 1;
			}
		}
		acPassword[i] = nTagNumber + '0';
	}
	acPassword[nCount] = '\0';
	cout << acPassword << endl;
	delete[] acPassword;
	return 0;
}
