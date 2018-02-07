//����������
//	ͼ������ǰ�ͼ���в���Ҫ�����ض�Ⱦ�ɱ���ɫ��ʹ����Ҫ���ֱ�͹�Գ������ָ���һ���ڰ�ͼ��Ҫ���㽫�Ҷ�ֵλ��ĳָ�������ڵ�����������ɫ����һ��ָ������ɫ�滻��
//�����ʽ��
//	�����ڵ�һ�и���һ��ͼ��ķֱ��ʣ�������������M��N��0 < M, N <= 500���������Ǵ����˵ĻҶ�ֵ����˵�A��B��0 <= A < B <= 255�����Լ�ָ�����滻�Ҷ�ֵ��
//	���M�У�ÿ�и���N�����ص�ĻҶ�ֵ������Կո�ָ������лҶ�ֵ����[0, 255]�����ڡ�
//�����ʽ��
//	�����Ҫ����˺��ͼ�񡣼����M�У�ÿ��N�����ػҶ�ֵ��ÿ���Ҷ�ֵռ3λ�������ɫҪ��ʾΪ000���������һ���ո�ָ�������β�����ж���ո�
//����������
//	3 5 100 150 0
//	3 189 254 101 119
//	150 233 151 99 100
//	88 123 149 0 255
//���������
//	003 189 254 000 000
//	000 233 151 099 000
//	088 000 000 000 255

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int nRows = 0, nColumn = 0;
	int nFilterMin = 0, nFilterMax = 0;
	int nNewGray = 0;
	cin >> nRows >> nColumn >> nFilterMin >> nFilterMax >> nNewGray;
	int nImageSize = nRows * nColumn;
	int* anImage = new int[nImageSize];
	int nColor = 0;
	for (int i = 0; i < nImageSize; ++i) {
		cin >> nColor;
		if (nColor >= nFilterMin && nColor <= nFilterMax) {
			nColor = nNewGray;
		}
		anImage[i] = nColor;
	}
	for (int i = 0; i < nImageSize; ++i) {
		cout << setfill('0') << setw(3) << anImage[i];
		if (i < nImageSize - 1) {
			if ((i + 1) % nColumn == 0) {
				cout << '\n';
			}
			else {
				cout << ' ';
			}
		}
	}
	cout << endl;
	delete[] anImage;

	return 0;
}
