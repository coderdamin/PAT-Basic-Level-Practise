//����������
//	С��PAT�������֣�����֮���������΢��ת���齱�����ת���������а�˳��ÿ��N���˾ͷ���һ������������д���������ȷ���н�������
//�����ʽ��
//	�����һ�и�������������M�� <= 1000����N��S���ֱ���ת����������С���������н�������Լ���һλ�н��ߵ���ţ���Ŵ�1��ʼ����
//	���M�У�˳�����ת��΢�������ѵ��ǳƣ�������20���ַ����������ո�س��ķǿ��ַ�������
//	ע�⣺��������ת����Σ��������н���Ρ�����������ڵ�ǰ�н�λ�õ������Ѿ��й�������������˳��ȡ��һλ��
//�����ʽ��
//	���������˳������н�������ÿ���ǳ�ռһ�С����û�����н����������Keep going...����
//��������1��
//	9 3 2
//	Imgonnawin!
//	PickMe
//	PickMeMeMeee
//	LookHere
//	Imgonnawin!
//	TryAgainAgain
//	TryAgainAgain
//	Imgonnawin!
//	TryAgainAgain
//�������1��
//	PickMe
//	Imgonnawin!
//	TryAgainAgain
//
//��������2��
//	2 3 5
//	Imgonnawin!
//	PickMe
//�������2��
//	Keep going...

#include <iostream>
using namespace std;

int StringArrayFind(char(*pStrArray)[21], int nCount, char*pStr);
int main() {
	int nTotal = 0, nInterval = 0, nBegin = 0;
	cin >> nTotal >> nInterval >> nBegin;
	char(*acNickname)[21] = nullptr;
	if (nTotal >= nBegin) {
		acNickname = new char[(nTotal - nBegin + 1) / nInterval][21];
	}
	char acInput[21] = { 0 };
	for (int i = 1; i < nBegin && i <= nTotal; ++i) {
		cin >> acInput;
	}
	int nWinnerCount = 0;
	int nWinnerCD = 0;
	for (int i = nBegin; i <= nTotal; ++i) {
		cin >> acInput;
		nWinnerCD -= 1;
		if (nWinnerCD > 0) {
			continue;
		}
		if (StringArrayFind(acNickname, nWinnerCount, acInput) == -1) {
			strcpy(acNickname[nWinnerCount++], acInput);
			nWinnerCD = nInterval;
		}
		else{
			nWinnerCD += 1;
		}
	}
	if (nWinnerCount == 0) {
		cout << "Keep going..." << endl;
	}
	else{
		cout << acNickname[0];
		for (int i = 1; i < nWinnerCount; ++i) {
			cout << '\n' << acNickname[i];
		}
		cout << endl;
	}
	if (acNickname != nullptr) {
		delete[] acNickname;
	}
	return 0;
}

int StringArrayFind(char(*pStrArray)[21], int nCount, char*pStr) {
	int nPos = -1;
	for (int i = 0; i < nCount; ++i) {
		if (strcmp(pStrArray[i], pStr) == 0) {
			nPos = i;
			break;
		}
	}
	return nPos;
}
