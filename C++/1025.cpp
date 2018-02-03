//问题描述：
//	给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。例如：给定L为1→2→3→4→5→6，K为3，则输出应该为3→2→1→6→5→4；
//	如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。
//输入格式：
//	每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址、结点总个数正整数N(<= 105)、以及正整数K(<= N)，
//	即要求反转的子链结点的个数。结点的地址是5位非负整数，NULL地址用 - 1表示。
//	接下来有N行，每行格式为：
//	Address Data Next
//	其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。
//输出格式：
//	对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。
//输入样例：
//	00100 6 4
//	00000 4 99999
//	00100 1 12309
//	68237 6 - 1
//	33218 3 00000
//	99999 5 68237
//	12309 2 33218
//输出样例：
//	00000 4 33218
//	33218 3 12309
//	12309 2 00100
//	00100 1 99999
//	99999 5 68237
//	68237 6 - 1

#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

#define SWAP(val1, val2) { \
	val1 ^= val2;		\
	val2 ^= val1;		\
	val1 ^= val2;		\
}

typedef struct _NODE_ {
	//int nAddress;
	int nData;
	int nNextAddress;
} NODE;
int main() {
	int nHeard, nCount, nLoop;
	cin >> nHeard >> nCount >> nLoop;
	//NODE* aNodeList = new NODE[nCount];
	//int* anNext = new int[nCount];
	//for (int i = 0; i < nCount; ++i) {
	//	cin >> aNodeList[i].nAddress >> aNodeList[i].nData;
	//	cin >> anNext[i];
	//}
	map<int, NODE*> mNodes;
	int nAddress = 0;
	for (int i = 0; i < nCount; ++i) {
		cin >> nAddress;
		NODE* pNode = new NODE;
		cin >> pNode->nData >> pNode->nNextAddress;
		mNodes[nAddress] = pNode;
	}
	NODE* pNode = nullptr;
	NODE* pHead1 = nullptr, *pHead2 = nullptr;
	int nNextAddr = 0;
	nAddress = nHeard;
	pHead1 = mNodes[nAddress];
	bool bResetHead = true;
	for (int i = nLoop; i <= nCount; i += nLoop) {
		for (int j = 0; j < nLoop; ++j) {
			pNode = mNodes[nAddress];
			SWAP(nNextAddr, pNode->nNextAddress)
				SWAP(nNextAddr, nAddress)
				//nAddrTmp = nAddress;
				//nAddress = pNode->nNextAddress;
				//pNode->nNextAddress = nNextAddr;
				//nNextAddr = nAddrTmp;
		}
		if (pHead1 && pHead2) {
			pHead1->nNextAddress = nNextAddr;
			pHead1 = pHead2;
			pHead2 = mNodes[nAddress];
		}
		else {
			pHead2 = mNodes[nAddress];
			if (bResetHead) {
				nHeard = nNextAddr;
				bResetHead = false;
			}
		}
	}
	if (nCount > 0 && nCount % nLoop == 0) {
		pHead1->nNextAddress = -1;
	}
	else {
		pHead1->nNextAddress = nAddress;
	}

	nAddress = nHeard;
	for (int i = 0; i < nCount; ++i) {
		pNode = mNodes[nAddress];
		cout << setfill('0') << setw(5) << nAddress << ' ' << pNode->nData << ' ' << setfill('0') << setw(5) << pNode->nNextAddress << '\n';
		nAddress = pNode->nNextAddress;
	}

	return 0;
}
