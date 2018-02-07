//����������
//	�������������Ķ��ڵ�����ʿ��һ�ְ��ơ���������������˵Ĵ����ɶ����ҳ��䵥�Ŀ��ˣ��Ա��������ذ���
//�����ʽ��
//	�����һ�и���һ��������N�� <= 50000��������֪���� / ���µĶ��������N�У�ÿ�и���һ�Է��� / ���¡���Ϊ���������ÿ�˶�Ӧһ��ID�ţ�Ϊ5λ���֣���00000��99999����
//	ID���Կո�ָ���֮�����һ��������M�� <= 10000����Ϊ�μ��ɶԵ������������һ�и�����Mλ���˵�ID���Կո�ָ�����Ŀ��֤�����ػ��Ų���������
//�����ʽ��
//	���ȵ�һ������䵥���˵������������ڶ��а�ID����˳���г��䵥�Ŀ��ˡ�ID����1���ո�ָ����е���β�����ж���ո�
//����������
//	3
//	11111 22222
//	33333 44444
//	55555 66666
//	7
//	55555 44444 10000 88888 22222 11111 23333
//���������
//	5
//	10000 23333 44444 55555 88888

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	int nCoupleCount = 0;
	map<int, int> mapCouple;
	int nCouple1 = 0, nCouple2 = 0;
	cin >> nCoupleCount;
	for (int i = 0; i < nCoupleCount; ++i) {
		cin >> nCouple1 >> nCouple2;
		mapCouple[nCouple1] = nCouple2;
	}
	int nPeopleCount = 0;
	int nPeople = 0;
	set<int> setSingleDog;
	cin >> nPeopleCount;
	for (int i = 0; i < nPeopleCount; ++i) {
		cin >> nPeople;
		setSingleDog.insert(nPeople);
	}
	for (auto coupleInfo : mapCouple) {
		if ((setSingleDog.find(coupleInfo.first) != setSingleDog.end())
			&& (setSingleDog.find(coupleInfo.second) != setSingleDog.end())) {
			setSingleDog.erase(coupleInfo.first);
			setSingleDog.erase(coupleInfo.second);
		}
	}
	int nSingleDogCount = setSingleDog.size();
	cout << nSingleDogCount;
	if (nSingleDogCount > 0) {
		cout << '\n' << setfill('0') << setw(5) << *setSingleDog.begin();
		*setSingleDog.erase(setSingleDog.begin());
	}
	for (auto nPeople : setSingleDog) {
		cout << ' ' << setfill('0') << setw(5) << nPeople;
	}
	cout << endl;
	setSingleDog.clear();
	mapCouple.clear();
	return 0;
}