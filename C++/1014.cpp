//����������
//	����̽����Ħ˹�ӵ�һ����ֵ�������
//	������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm����
//	����̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04������Ϊǰ�����ַ�����
//	��1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣��ǵ�4����ĸ'D'�����������ģ�
//	��2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����ĵ�14����ͷ������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ����
//	�������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ��ָ��������ַ��������������Ħ˹����õ�Լ���ʱ�䡣
//�����ʽ��
//	������4���зֱ����4���ǿա��������ո��ҳ��Ȳ�����60���ַ�����
//�����ʽ��
//	��һ�������Լ���ʱ�䣬��ʽΪ��DAY HH : MM�������С�DAY����ĳ���ڵ�3�ַ���д����MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ�����ģ�FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ�����ա���Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣
//����������
//	3485djDkxh4hhGE
//	2984akDfkkkkggEdsb
//	s&hgsfdk
//	d&Hyscvnm
//���������
//	THU 14:04

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	char acInput[4][61] = { 0 };
	cin >> acInput[0] >> acInput[1] >> acInput[2] >> acInput[3];
	int index = 0;
	char cWeek = '\0';
	char cHour = '\0';
	char cMM = '\0';
	while (acInput[0][index] != '\0') {
		if (acInput[0][index] == acInput[1][index]) {
			if (cWeek == '\0') {
				if (acInput[0][index] >= 'A'
					&& acInput[0][index] <= 'Z') {
					cWeek = acInput[0][index];
				}
			}
			else {
				cHour = acInput[0][index];
				break;
			}
		}
		index += 1;
	}
	index = 0;
	while (acInput[2][index] != '\0') {
		if ((acInput[2][index] >= 'A' && acInput[2][index] <= 'Z')
			|| (acInput[2][index] >= 'a' && acInput[2][index] <= 'z')) {
			if (acInput[2][index] == acInput[3][index]) {
				cMM = index;
				break;
			}
		}
		index += 1;
	}

	char *aDay[] = {
		"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
	};
	cout << aDay[cWeek - 'A'] << " ";
	cout << setfill('0') << setw(2);
	cout << (unsigned int)((cHour >= 'A') ? cHour - 'A' + 10 : cHour - '0') << ':';
	cout << setfill('0') << setw(2);
	cout << (unsigned int)cMM;
	cout << endl;
	return 0;
}
