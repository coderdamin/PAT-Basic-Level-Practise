//����������
//	����������13���Ƽ����ģ�
//	�����˵�0�������˳�Ϊtret��
//	����������1��12�Ļ����ķֱ�Ϊ��jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec��
//	�����˽���λ�Ժ��12����λ���ֱַ��Ϊ��tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou��
//	��������˵����֡�29������ɻ����ľ��ǡ�hel mar�����������ġ�elo nov����Ӧ�������֡�115����Ϊ�˷��㽻���������д����ʵ�ֵ���ͻ�������֮��Ļ��롣
//�����ʽ��
//	�����һ�и���һ��������N��<100�������N�У�ÿ�и���һ��[0, 169)�����ڵ����� ���� �����ǵ����ģ������ǻ����ġ�
//�����ʽ��
//	��Ӧ�����ÿһ�У���һ���������������һ�����Ե����֡�
//����������
//	4
//	29
//	5
//	elo nov
//	tam
//���������
//	hel mar
//	may
//	115
//	13

#include <iostream>
using namespace std;

#define ARRAY_LEN(array) sizeof(array) / sizeof(array[0])

char* acTextspeakL[] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
char* acTextspeakH[] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

int StringToInt(char* pStr);
int main() {
	int nCount = 0;
	cin >> nCount;
	char(*acNumber)[10] = new char[nCount][10];
	cin.ignore();
	for (int i = 0; i < nCount; ++i) {
		cin.getline(acNumber[i], 10);
	}
	int nNumber = 0;
	int nNumberH = 0;
	for (int i = 0; i < nCount; ++i) {
		acNumber[i];
		// If the converted value would be out of the range of representable values by an int, 
		// it causes undefined behavior. 
		//nNumber = atoi(); 
		nNumber = StringToInt(acNumber[i]);
		if (nNumber != -1) {
			nNumberH = nNumber / 13;
			if (nNumberH > 0) {
				cout << acTextspeakH[nNumberH - 1] << ' ';
			}
			cout << acTextspeakL[nNumber % 13];
		}
		else{
			int nBeganPos = 0;
			int nEndPos = 0;
			nNumberH = 0;
			nNumber = 0;
			while (acNumber[i][nEndPos] != '\0') {
				if ((acNumber[i][nEndPos] == ' ' || acNumber[i][nEndPos + 1] == '\0')
					&& (nEndPos > nBeganPos)) {
					//if (acNumber[nEndPos] == ' ' && nEndPos > nBeganPos) {
					if (nNumberH == 0) {
						for (int j = 0; j < ARRAY_LEN(acTextspeakH); ++j) {
							if (strncmp(&acNumber[i][nBeganPos], acTextspeakH[j], nEndPos - nBeganPos) == 0) {
								nNumberH = j + 1;
								break;
							}
						}
					}
					else{
						for (int j = 0; j < ARRAY_LEN(acTextspeakL); ++j) {
							if (strncmp(&acNumber[i][nBeganPos], acTextspeakL[j], nEndPos - nBeganPos) == 0) {
								nNumber = j;
								break;
							}
						}
					}
					nBeganPos = nEndPos + 1;
				}
				nEndPos += 1;
			}
			cout << nNumberH * 13 + nNumber;
		}
		if (i != nCount - 1) {
			cout << '\n';
		}
	}
	cout << endl;
	delete[] acNumber;
	return 0;
}

int StringToInt(char* pStr) {
	int nNumber = 0;
	while (*pStr != '\0' && *pStr != ' ') {
		if (*pStr < '0' || *pStr > '9') {
			nNumber = -1;
			break;
		}
		nNumber = nNumber * 10 + (*pStr - '0');
		pStr += 1;
	}
	return nNumber;
}
