//����������
//	��ͼ���Ϻ�ĳУ����ѧ�ڿ�ѧ����콫��������˹��Ҳ������ɾ��΢����ж��QQ��������ԣ������ֻ�������ipad������wifi��ʹ�����������Ȼ�󣬾��桢�������£�Ȼ��˼�������顢���������ǡ����򡢾���������سɴ���Ҳ��
//	����Ҫ����д�������������ѧУ����ʦ�������ѧ������Ʒ��������ɴ�����
//�����ʽ��
//	�����һ�и�������������N�� <= 1000����M�� <= 6�����ֱ���ѧ����������Ҫ����ɵ���Ʒ���������ڶ��и���M����Ҫ����ɵ���Ʒ��ţ����б��Ϊ4λ���֡�
//	���N�У�ÿ�и���һλѧ����������д����1 - 4����дӢ����ĸ��ɣ���������Ʒ����K��0 <= K <= 10�����Լ�K����Ʒ�ı�š�
//�����ʽ��
//	˳�μ��ÿ��ѧ��Я������Ʒ���������Ҫ����ɵ���Ʒ���ڣ������¸�ʽ�����������Ϣ������Ҫ����ɵ���Ʒ����Ϣ��ע����ĩ�����ж���ո񣩣�
//	������д: ��Ʒ���1 ��Ʒ���2 ����
//	���һ��������������ѧ�����������ͱ������Ʒ��������
//����������
//	4 2
//	2333 6666
//	CYLL 3 1234 2345 3456
//	U 4 9966 6666 8888 6666
//	GG 2 2333 7777
//	JJ 3 0012 6666 2333
//���������
//	U: 6666 6666
//	GG: 2333
//	JJ: 6666 2333
//	3 5

#include <iostream>
#include <set>
#include <iomanip>
using namespace std;

int main() {
	int nStudentCount = 0, nGoodsCount = 0;
	cin >> nStudentCount >> nGoodsCount;
	set<int> setGoods;
	int nGoodsId = 0;
	for (int i = 0; i < nGoodsCount; ++i) {
		cin >> nGoodsId;
		setGoods.insert(nGoodsId);
	}
	char nName[5] = { 0 };
	bool bFirst = true;
	int anCheckInfo[2] = { 0 };
	for (int i = 0; i < nStudentCount; ++i) {
		cin >> nName >> nGoodsCount;
		bFirst = true;
		for (int j = 0; j < nGoodsCount; ++j) {
			cin >> nGoodsId;
			if (setGoods.find(nGoodsId) != setGoods.end()) {
				if (bFirst) {
					cout << nName << ':';
					bFirst = false;
					anCheckInfo[0] += 1;
				}
				cout << ' ' << setfill('0') << setw(4) << nGoodsId;
				anCheckInfo[1] += 1;
			}
		}
		if (!bFirst) {
			cout << '\n';
		}
	}
	cout << anCheckInfo[0] << ' ' << anCheckInfo[1] << endl;
	setGoods.clear();
	return 0;
}
