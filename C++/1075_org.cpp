#include <iostream>
#include <iomanip>
using namespace std;

typedef struct ListNode_ {
	int nVal;
	int nAddress;
	struct ListNode_* pNext;
} ListNode;

bool ListInsert(ListNode&head, ListNode&node, int nParent);
int main() {
	ListNode* pHead = nullptr;
	pHead = new ListNode();
	pHead->nVal = 0;
	pHead->pNext = nullptr;
	pHead->nAddress = 0;
	int nFirstAddress = 0;
	int nNodeCount = 0;
	int nGroupVal = 0;
	cin >> nFirstAddress >> nNodeCount >> nGroupVal;
	pHead->nAddress = nFirstAddress;
	ListNode* pNode = nullptr;
	int nParent = 0;
	for (int i = 0; i < nNodeCount; ++i){
		pNode = new ListNode();
		cin >> pNode->nAddress >> pNode->nVal >> nParent;
		ListInsert(*pHead, *pNode, nParent);
	}
	ListNode* pNodeLeZero = nullptr;
	ListNode* pNodeLeGroupVal = nullptr;
	ListNode* pCurrentNode = pHead->pNext;
	ListNode* pPrevNode = pHead;
	ListNode* pParentNode = nullptr;
	while (pCurrentNode != nullptr){
		if (pCurrentNode->nVal < 0){
			pParentNode = (pNodeLeZero == nullptr) ? pPrevNode : pNodeLeZero;
			pNodeLeZero = pCurrentNode;
		}
		else if (pCurrentNode->nVal < nGroupVal){
			pParentNode = (pNodeLeGroupVal == nullptr) ? ((pNodeLeZero == nullptr) ? pPrevNode : pNodeLeZero) : pNodeLeGroupVal;
			pNodeLeGroupVal = pCurrentNode;
		}
		else{
			pPrevNode = pCurrentNode;
			pCurrentNode = pCurrentNode->pNext;
			continue;
		}
		if (pPrevNode != pParentNode){
			pPrevNode->pNext = pCurrentNode->pNext;
			pCurrentNode->pNext = pParentNode->pNext;
			pParentNode->pNext = pCurrentNode;

			pCurrentNode = pPrevNode->pNext;
		}
		else{
			pPrevNode = pCurrentNode;
			pCurrentNode = pCurrentNode->pNext;
		}
	}
	pCurrentNode = pHead->pNext;
	while (pCurrentNode != nullptr){
		cout << setfill('0') << setw(5) << pCurrentNode->nAddress << ' ' << setw(0) << pCurrentNode->nVal << ' ';
		if (pCurrentNode->pNext != nullptr) {
			cout << setfill('0') << setw(5) << pCurrentNode->pNext->nAddress << '\n';
		}
		else{
			cout << -1;
		}
		pPrevNode = pCurrentNode;
		pCurrentNode = pCurrentNode->pNext;
		delete pPrevNode;
	}
	delete pHead;

	cout << endl;
	return 0;
}

bool ListInsert(ListNode&head, ListNode&node, int nParent){
	ListNode* pParentNode = &head;
	while ((pParentNode->pNext != nullptr) && (pParentNode->nAddress != nParent)) {
		pParentNode = pParentNode->pNext;
	}
	node.pNext = pParentNode->pNext;
	pParentNode->pNext = &node;
	return true;
}
