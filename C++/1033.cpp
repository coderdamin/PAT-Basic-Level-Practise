//����������
//	�ɼ����ϻ��˼���������������һ�����ֵ�ʱ�򣬶�Ӧ���ַ��Ͳ�����֡����ڸ���Ӧ�������һ�����֡��Լ���������Щ��������Ľ�����ֻ���������
//�����ʽ��
//	������2���зֱ������������Щ�����Լ�Ӧ����������֡����ж�ӦӢ����ĸ�Ļ����Դ�д������ÿ�������ǲ�����105���ַ��Ĵ���
//	���õ��ַ�������ĸ[a - z, A - Z]������0 - 9���Լ��»��ߡ�_��������ո񣩡���, ������.������ - ������ + ���������ϵ���������Ŀ��֤��2����������ִ��ǿա�
//	ע�⣺����ϵ��������ˣ���ô��д��Ӣ����ĸ�޷��������
//�����ʽ��
//	��һ��������ܹ�������Ľ�����֡����û��һ���ַ��ܱ��������������С�
//����������
//	7+IE.
//	7_This_is_a_test.
//���������
//	_hs_s_a_tst

#include <iostream>
#include <algorithm> 
using namespace std;

char UPPER(char acChar);
int main() {
	char acBadKey[68] = { 0 };// 26 + 26 + 10 + 5 = 67
	char acString[106] = { 0 };
	cin >> acBadKey >> acString;
	int nIndex = 0;
	bool bUpper = true;
	if (find(acBadKey, acBadKey + 68, '+') != acBadKey + 68) {
		bUpper = false;
	}

	while (acString[nIndex] != '\0') {
		if (!bUpper && (acString[nIndex] >= 'A' && acString[nIndex] <= 'Z')) {
			//}else if ((bUpper || (acString[nIndex] < 'A' || acString[nIndex] > 'Z'))
			//	&& (find(acBadKey, acBadKey + 68, UPPER(acString[nIndex])) == acBadKey + 68)) {
		}
		else if (find(acBadKey, acBadKey + 68, UPPER(acString[nIndex])) == acBadKey + 68) {
			cout << acString[nIndex];
		}
		nIndex += 1;
	}
	cout << endl;
	return 0;
}

char UPPER(char acChar) {
	if ('a' <= acChar && acChar <= 'z') {
		return acChar - 'a' + 'A';
	}
	return acChar;
}