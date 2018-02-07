//����������
//	�ļ�����ʱ���κ���Ҫ������Ը�����N����K�ŵĶ�������Ŷӹ������£�
//	ÿ������ΪN / K������ȡ���������������ȫ��վ�����һ�ţ�
//	���������˵ĸ��Ӷ�����ǰ���κ��˰���
//	ÿ���������վ�м䣨�м�λ��Ϊm / 2 + 1������mΪ������������������ȡ������
//	ÿ�����������м���Ϊ�ᣬ����߷��������Һ��������վ���м��˵����ࣨ����5�����Ϊ190��188��186��175��170��
//	�����Ϊ175��188��190��186��170�������������������ߣ��������������м��˵��ұߣ���
//	�����������ͬ�������ֵ��ֵ����������С����ﱣ֤��������
//	�ָ���һ�������ˣ����д����������ǵĶ��Ρ�
//�����ʽ��
//	ÿ���������1������������ÿ������������1�и�������������N�� <= 10000������������K�� <= 10���������������N�У�
//	ÿ�и���һ���˵����֣��������ո񡢳��Ȳ�����8��Ӣ����ĸ������ߣ�[30, 300]�����ڵ���������
//�����ʽ��
//	������յĶ��Ρ���K������������Կո�ָ�����ĩ�����ж���ո�ע�⣺��������������ߣ����ŵ���������Ϸ���ǰ��������·���
//����������
//	10 3
//	Tom 188
//	Mike 170
//	Eva 168
//	Tim 160
//	Joe 190
//	Ann 168
//	Bob 175
//	Nick 186
//	Amy 160
//	John 159
//���������
//	Bob Tom Joe Nick
//	Ann Mike Eva
//	Tim Amy John

#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef struct {
	char acName[9];
	UINT32 uHeight;
} People;

bool PeopleListSortFunc(People& p1, People& p2);
int main() {
	int nCount = 0, nRows = 0;
	cin >> nCount >> nRows;
	People* aPeopleList = new People[nCount];
	for (int i = 0; i < nCount; ++i) {
		cin >> aPeopleList[i].acName >> aPeopleList[i].uHeight;
	}
	sort(aPeopleList, &aPeopleList[nCount], PeopleListSortFunc);

	int nColumn = nCount;
	int nCurLine = nCount;
	if (nCount > nRows){
		nColumn = (nCount / nRows);
		nCurLine = nCount - nColumn * (nRows - 1);
	}
	else{
		nRows = 1;
	}

	unsigned short uIndex = 0;
	unsigned short uIntTmp = 0;
	unsigned short uLineBase = 0;
	for (int i = 0; i <nRows; ++i){
		uIndex = uLineBase + (nCurLine & 0xfffffffe) - 1;
		for (int j = 0; j < nCurLine; ++j){
			cout << aPeopleList[uIndex].acName;
			uIntTmp = nCurLine >> 1;
			if (j < uIntTmp) {
				if (j == uIntTmp - 1) {
					uIndex = uLineBase + 0;
				}
				else{
					uIndex -= 2;
				}
			}
			else{
				uIndex += 2;
			}
			if (j < nCurLine - 1){
				cout << ' ';
			}
		}
		uLineBase += nCurLine;
		nCurLine = nColumn;
		if (i < nRows - 1){
			cout << '\n';
		}
	}
	cout << endl;
	delete[] aPeopleList;

	return 0;
}

bool PeopleListSortFunc(People& p1, People& p2) {
	if (p1.uHeight == p2.uHeight){
		return (strcmp(p1.acName, p2.acName) < 0);
	}
	return (p1.uHeight > p2.uHeight);
}
