//����������
//	�������������λ���ֵĺ���һ���ģ��򱻳�Ϊ�ǡ��������������Ǹ������ĺ;������ǵġ�����֤�š�������123��51��������������Ϊ1 + 2 + 3 = 5 + 1 = 6��
//	��6�������ǵ�����֤�š�����һЩ������Ҫ����ͳ��һ���������ж��ٸ���ͬ������֤�š�ע�⣺����Ĭ��һ�������Լ����Լ������ѡ�
//�����ʽ��
//	�����һ�и���������N�����һ�и���N�������������ּ��Կո�ָ�����Ŀ��֤��������С��104��
//�����ʽ��
//	���ȵ�һ��������������в�ͬ������֤�ŵĸ��������һ�а�����˳�������Щ����֤�ţ����ּ��һ���ո�����ĩ�����ж���ո�
//����������
//	8
//	123 899 51 998 27 33 36 12
//���������
//	4
//	3 6 9 26

#include <iostream>
#include <set>
using namespace std;

int CalcNumber(int nNumber);
int main() {
	int nCount = 0;
	cin >> nCount;
	int nNumber = 0;
	set<int> setNumber;
	for (int i = 0; i < nCount; ++i) {
		cin >> nNumber;
		setNumber.insert(CalcNumber(nNumber));
	}
	cout << setNumber.size() << '\n';
	bool bFirst = true;
	for (auto nNumber : setNumber) {
		if (bFirst) {
			bFirst = false;
			cout << nNumber;
		}
		else{
			cout << ' ' << nNumber;
		}
	}
	cout << endl;
	setNumber.clear();
	return 0;
}

int CalcNumber(int nNumber) {
	int nResult = 0;
	while (nNumber != 0) {
		nResult += nNumber % 10;
		nNumber /= 10;
	}
	return nResult;
}
