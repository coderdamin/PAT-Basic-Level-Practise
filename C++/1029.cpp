//����������
//	�ɼ����ϻ��˼���������������һ�����ֵ�ʱ�򣬶�Ӧ���ַ��Ͳ�����֡����ڸ���Ӧ�������һ�����֡��Լ�ʵ�ʱ���������֣������г��϶���������Щ����
//�����ʽ��
//	������2���зֱ����Ӧ����������֡��Լ�ʵ�ʱ���������֡�ÿ�������ǲ�����80���ַ��Ĵ�������ĸA - Z��������Сд��������0 - 9��
//	�Լ��»��ߡ�_��������ո���ɡ���Ŀ��֤2���ַ������ǿա�
//�����ʽ��
//	���շ���˳����һ������������ļ�������Ӣ����ĸֻ�����д��ÿ������ֻ���һ�Ρ���Ŀ��֤������1��������
//����������
//	7_This_is_a_test
//	_hs_s_a_es
//���������
//	7TI

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char UPPER(char acKey);
int main() {
	char acRight[81] = { 0 };
	char acInput[81] = { 0 };
	cin >> acRight >> acInput;
	int nIndex1 = 0;
	int nIndex2 = 0;
	vector<char> vOutList;
	char cTemp = '\0';
	while (acRight[nIndex1] != '\0') {
		if (acInput[nIndex2] == '\0' || acRight[nIndex1] != acInput[nIndex2]) {
			cTemp = UPPER(acRight[nIndex1]);
			if (find(vOutList.begin(), vOutList.end(), cTemp) == vOutList.end()) {
				vOutList.push_back(cTemp);
			}
			nIndex1 += 1;
		}
		else {
			nIndex1 += 1;
			nIndex2 += 1;
		}
	}
	for (auto badKey : vOutList) {
		cout << badKey;
	}
	cout << endl;
	vOutList.clear();
	return 0;
}

char UPPER(char acKey) {
	return ('a' <= acKey && acKey <= 'z') ? acKey + 'A' - 'a' : acKey;
}