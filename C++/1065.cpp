//问题描述：
//	“单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。
//输入格式：
//	输入第一行给出一个正整数N（ <= 50000），是已知夫妻 / 伴侣的对数；随后N行，每行给出一对夫妻 / 伴侣——为方便起见，每人对应一个ID号，为5位数字（从00000到99999），
//	ID间以空格分隔；之后给出一个正整数M（ <= 10000），为参加派对的总人数；随后一行给出这M位客人的ID，以空格分隔。题目保证无人重婚或脚踩两条船。
//输出格式：
//	首先第一行输出落单客人的总人数；随后第二行按ID递增顺序列出落单的客人。ID间用1个空格分隔，行的首尾不得有多余空格。
//输入样例：
//	3
//	11111 22222
//	33333 44444
//	55555 66666
//	7
//	55555 44444 10000 88888 22222 11111 23333
//输出样例：
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