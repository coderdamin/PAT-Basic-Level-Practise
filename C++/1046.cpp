//����������
//	��ȭ�ǹ����й����Ļ���һ����Ȥ����ɲ��֡����������˻�ȭ�ķ���Ϊ��ÿ�˿��к���һ�����֣�ͬʱ���ֱȻ���һ�����֡����˭�Ȼ������������õ������˺���������֮�ͣ�
//	˭��Ӯ�ˣ���ҷ�һ���ơ�����ͬӮ������ͬ���������һ�֣�ֱ��Ψһ��Ӯ�ҳ��֡�
//	��������ס������˵Ļ�ȭ��¼������ͳ���������ֱ���˶��ٱ��ơ�
//�����ʽ��
//	�����һ���ȸ���һ��������N�� <= 100�������N�У�ÿ�и���һ�ֻ�ȭ�ļ�¼����ʽΪ��
//	�׺� �׻� �Һ� �һ�
//	���С������Ǻ��������֣��������ǻ��������֣���Ϊ������100������������ֻ��һ�𻮣���
//�����ʽ��
//	��һ�����Ⱥ�����ס������˺ȾƵı����������һ���ո�ָ���
//����������
//	5
//	8 10 9 12
//	5 10 5 10
//	3 8 5 12
//	12 18 1 13
//	4 16 12 15
//���������
//	1 2

#include <iostream>
using namespace std;

int main() {
	int nCount = 0;
	cin >> nCount;
	//int(*anMorraInfo)[4] = new int[nCount][4];
	//for (int i = 0; i < nCount; ++i) {
	//	cin >> anMorraInfo[i][0] >> anMorraInfo[i][1] >> anMorraInfo[i][2] >> anMorraInfo[i][3];
	//}
	//int nWinCountA = 0;
	//int nWinCountB = 0;
	//for (int i = 0; i < nCount; ++i) {
	//}
	//delete[] anMorraInfo;
	int nWinCountA = 0;
	int nWinCountB = 0;
	int nMorraA_1, nMorraA_2;
	int nMorraB_1, nMorraB_2;
	for (int i = 0; i < nCount; ++i) {
		cin >> nMorraA_1 >> nMorraA_2 >> nMorraB_1 >> nMorraB_2;
		if (nMorraA_2 != nMorraB_2) {
			if (nMorraA_2 == nMorraA_1 + nMorraB_1) {
				nWinCountA += 1;
			}
			else if (nMorraB_2 == nMorraA_1 + nMorraB_1){
				nWinCountB += 1;
			}
		}
	}
	cout << nWinCountB << ' ' << nWinCountA << endl;
	return 0;
}
