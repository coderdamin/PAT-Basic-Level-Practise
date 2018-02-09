//����������
//	���ڼ�������ԣ���ɫ���������ص��Ӧ��һ��24λ����ֵ���ָ���һ���ֱ���ΪMxN�Ļ���Ҫ�����ҳ����̴��е�һ��죬���ж�һ�޶���ɫ���Ǹ����ص㣬
//	���Ҹõ����ɫ������Χ8���������ص���ɫ���ִ�
//�����ʽ��
//	�����һ�и����������������ֱ���M��N�� <= 1000������ͼ��ķֱ��ʣ��Լ�TOL�����������ص������ڵ����ɫ����ֵ��ɫ���TOL�ĵ�ű����ǡ�
//	���N�У�ÿ�и���M�����ص���ɫֵ����Χ��[0, 224)�ڡ�����ͬ�����ּ��ÿո��TAB�ֿ���
//�����ʽ��
//	��һ���а��ա�(x, y): color���ĸ�ʽ����������ص��λ���Լ���ɫֵ������λ��x��y�ֱ��Ǹ�������ͼ������е��С��б�ţ���1��ʼ��ţ���
//	��������ĵ㲻Ψһ���������Not Unique������������ĵ㲻���ڣ��������Not Exist����
//��������1��
//	8 6 200
//	0 	 0 	  0 	   0	    0 	     0 	      0        0
//	65280 	 65280    65280    16711479 65280    65280    65280    65280
//	16711479 65280    65280    65280    16711680 65280    65280    65280
//	65280 	 65280    65280    65280    65280    65280    165280   165280
//	65280 	 65280 	  16777015 65280    65280    165280   65480    165280
//	16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215
//�������1��
//	(5, 3): 16711680
//
//��������2��
//	4 5 2
//	0 0 0 0
//	0 0 3 0
//	0 0 0 0
//	0 5 0 0
//	0 0 0 0
//�������2��
//	Not Unique
//
//��������3��
//	3 3 5
//	1 2 3
//	3 4 5
//	5 6 7
//�������3��
//	Not Exist

#include <iostream>
using namespace std;

int anColors[1 << 24] = { 0 }; // ջ����
int main() {
	int nRows = 0, nColumn = 0, nTOL = 0;
	cin >> nColumn >> nRows >> nTOL;
	int** anImage = new int*[nRows];
	for (int i = 0; i < nRows; ++i) {
		anImage[i] = new int[nColumn];
		for (int j = 0; j < nColumn; ++j) {
			cin >> anImage[i][j];
			anColors[anImage[i][j]] += 1;
		}
	}

	bool bRight = false;
	const int anOffset[8][2] = {
		{ -1, -1 }, { 0, -1 }, { 1, -1 }
		, { -1, 0 }, { 1, 0 }
		, { -1, 1 }, { 0, 1 }, { 1, 1 }
	};
	int nTagX = 0, nTagY = 0;
	int nTOLCount = 0;
	for (int i = 0; i < nRows; ++i) {
		for (int j = 0; j < nColumn; ++j) {
			if (anColors[anImage[i][j]] > 1){
				continue;
			}
			bRight = false;
			for (int k = 0; k < 8; ++k) {
				if (((j + anOffset[k][0] >= 0) && (j + anOffset[k][0] < nColumn))
					&& ((i + anOffset[k][1] >= 0) && (i + anOffset[k][1] < nRows))){
					if ((anImage[i][j] - anImage[i + anOffset[k][1]][j + anOffset[k][0]] <= nTOL)
						&& (anImage[i + anOffset[k][1]][j + anOffset[k][0]] - anImage[i][j] <= nTOL)){
						bRight = true;
						break;
					}
				}
			}
			if (!bRight) {
				if (nTOLCount == 0){
					nTagX = j; nTagY = i;
					nTOLCount = 1;
				}
				else{
					nTOLCount = 2;
					break;
				}
			}
		}
		if (nTOLCount > 1) {
			break;
		}
	}
	if (nTOLCount == 0) {
		cout << "Not Exist" << endl;
	}
	else if (nTOLCount == 1) {
		cout << '(' << nTagX + 1 << ", " << nTagY + 1 << "): " << anImage[nTagY][nTagX] << endl;
	}
	else{
		cout << "Not Unique" << endl;
	}

	for (int i = 0; i < nRows; ++i) {
		delete[] anImage[i];
	}
	delete[] anImage;

	return 0;
}
