//����������
//	�����ձ������ͨ���ɡ��֡������ۡ������ڡ�������Ҫ������ɡ�����������Ǽ���һ����������ǰ����и�ʽ����ģ�
//	[����]([����][��][����])[����]
//	�ָ�����ѡ�õķ��ż��ϣ����㰴�û���Ҫ��������顣
//�����ʽ��
//	����������ǰ����˳���Ӧ�����֡��ۡ��ڵĿ�ѡ���ż���ÿ����������һ�Է�����[]�ڡ���Ŀ��֤ÿ�����϶�������һ�����ţ���������10�����ţ�ÿ�����Ű���1��4���ǿ��ַ���
//	֮��һ�и���һ��������K��Ϊ�û�����ĸ��������K�У�ÿ�и���һ���û��ķ���ѡ��˳��Ϊ���֡����ۡ��ڡ����ۡ����֡�������ֻ������������Ӧ�����е���ţ���1��ʼ�������ּ��Կո�ָ���
//�����ʽ��
//	��ÿ���û�������һ����������ɵı��顣���û�ѡ�����Ų����ڣ��������Are you kidding me ? @\ / @����
//����������
//	[�r][�q][o][~\][/ ~][<][>]
//	[�s][�t][^][-][=][>][<][@][��]
//	[��][��][_][��][^]  ...
//	4
//	1 1 2 2 2
//	6 8 1 5 5
//	3 3 4 3 3
//	2 10 3 9 3
//���������
//	�r(�s���t)�q
//	<(@��=)/ ~
//	o(^��^)o
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

	//���֡����ۡ��ڡ����ۡ�����
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
		//[����]([����][��][����])[����]
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
