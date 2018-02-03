//����������
//	����һ������K�Լ�һ��������L�����д����L��ÿK����㷴ת�����磺����LΪ1��2��3��4��5��6��KΪ3�������Ӧ��Ϊ3��2��1��6��5��4��
//	���KΪ4�������Ӧ��Ϊ4��3��2��1��5��6������󲻵�K��Ԫ�ز���ת��
//�����ʽ��
//	ÿ���������1������������ÿ������������1�и�����1�����ĵ�ַ������ܸ���������N(<= 105)���Լ�������K(<= N)��
//	��Ҫ��ת���������ĸ��������ĵ�ַ��5λ�Ǹ�������NULL��ַ�� - 1��ʾ��
//	��������N�У�ÿ�и�ʽΪ��
//	Address Data Next
//	����Address�ǽ���ַ��Data�Ǹý�㱣����������ݣ�Next����һ���ĵ�ַ��
//�����ʽ��
//	��ÿ������������˳�������ת�����������ÿ�����ռһ�У���ʽ��������ͬ��
//����������
//	00100 6 4
//	00000 4 99999
//	00100 1 12309
//	68237 6 - 1
//	33218 3 00000
//	99999 5 68237
//	12309 2 33218
//���������
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
