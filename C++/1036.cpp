//����������
//	������ͳ�°��������������˶�ѧϰ��̣��������������д���룬��Ϊ������ʷ����λ��д������������ͳ��2014��ף�Ϊ��ף���������ѧ�����ܡ���ʽ������
//	�°����д�˺ܼ򵥵ļ�������룺����Ļ�ϻ�һ�������Ρ�������Ҳ����һ�𻭰ɣ�
//�����ʽ��
//	������һ���и��������α߳�N��3 <= N <= 20������������αߵ�ĳ���ַ�C�����һ���ո�
//�����ʽ��
//	����ɸ����ַ�C�����������Ρ�����ע�⵽�м����м�������Ϊ���ý������ȥ���������Σ��������������ʵ������������50%����������ȡ������
//����������
//	10 a
//���������
//	aaaaaaaaaa
//	a        a
//	a        a
//	a        a
//	aaaaaaaaaa

#include <iostream>
using namespace std;

void DrawLine(int nLen, char cChar);
int main() {
	int nCount = 0;
	char cChar = '\0';
	cin >> nCount >> cChar;
	int nLine = (nCount + 1) >> 1;
	DrawLine(nCount, cChar); cout << '\n';
	for (int i = 1; i < nLine - 1; ++i) {
		cout << cChar; DrawLine(nCount - 2, ' '); cout << cChar << '\n';
	}
	DrawLine(nCount, cChar); cout << endl;
	return 0;
}

void DrawLine(int nLen, char cChar) {
	while (nLen-- > 0) {
		cout << cChar;
	}
}
