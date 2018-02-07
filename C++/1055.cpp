//问题描述：
//	拍集体照时队形很重要，这里对给定的N个人K排的队形设计排队规则如下：
//	每排人数为N / K（向下取整），多出来的人全部站在最后一排；
//	后排所有人的个子都不比前排任何人矮；
//	每排中最高者站中间（中间位置为m / 2 + 1，其中m为该排人数，除法向下取整）；
//	每排其他人以中间人为轴，按身高非增序，先右后左交替入队站在中间人的两侧（例如5人身高为190、188、186、175、170，
//	则队形为175、188、190、186、170。这里假设你面对拍照者，所以你的左边是中间人的右边）；
//	若多人身高相同，则按名字的字典序升序排列。这里保证无重名。
//	现给定一组拍照人，请编写程序输出他们的队形。
//输入格式：
//	每个输入包含1个测试用例。每个测试用例第1行给出两个正整数N（ <= 10000，总人数）和K（ <= 10，总排数）。随后N行，
//	每行给出一个人的名字（不包含空格、长度不超过8个英文字母）和身高（[30, 300]区间内的整数）。
//输出格式：
//	输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。注意：假设你面对拍照者，后排的人输出在上方，前排输出在下方。
//输入样例：
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
//输出样例：
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
