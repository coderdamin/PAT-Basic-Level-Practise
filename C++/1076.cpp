//����������
//	������΢����������һ����Ƭ������λ�װ���ͬѧ�ǣ����ڴ����ʱ��Ҫʹ��wifi�����µ������ǵ�ѧϰ���ֽ�wifi��������Ϊ������ѧ��𰸣�
//	A-1��B-2��C-3��D-4����ͬѧ���Լ�����ÿ����һ����лл��������~������ ��ʦ��Ϊ�˴ٽ�ѧ��ѧϰҲ��ƴ�ˡ��� 
//	�����Ҫ����д�����һϵ����Ŀ�Ĵ𰸰��վ����ϸ����Ķ�Ӧ��ϵ�����wifi�����롣����򵥼���ÿ��ѡ���ⶼ��4��ѡ�����ֻ��1����ȷ�𰸡�
//�����ʽ��
//	�����һ�и���һ��������N�� <= 100�������N�У�ÿ�а��ա����-�𰸡��ĸ�ʽ����һ�����4��ѡ���T����ʾ��ȷѡ���F����ʾ����ѡ�
//	ѡ����ÿո�ָ���
//�����ʽ��
//	��һ�������wifi���롣
//����������
//	8
//	A-T B-F C-F D-F
//	C-T B-F A-F D-F
//	A-F D-F C-F B-T
//	B-T A-F C-F D-F
//	B-F D-T A-F C-F
//	A-T C-F B-F D-F
//	D-T B-F C-F A-F
//	C-T A-F B-F D-F
//���������
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
