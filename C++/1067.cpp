//����������
//	������ͼ��¼ĳ��ϵͳȴ��������ʱ��ϵͳһ��ֻ�������㳢�����޶�Σ��������������ʱ���˺žͻᱻ���������������ʵ�����С���ܡ�
//�����ʽ��
//	�����ڵ�һ�и���һ�����루���Ȳ�����20�ġ��������ո�Tab���س��ķǿ��ַ�������һ��������N�� <= 10�����ֱ�����ȷ�������ϵͳ�����ԵĴ�����
//	���ÿ�и���һ���Իس������ķǿ��ַ��������û�������������롣���뱣֤������һ�γ��ԡ�������һ��ֻ�е���#�ַ�ʱ�����������������һ�в����û������롣
//�����ʽ��
//	���û���ÿ�����룬�������ȷ�������ҳ��Դ���������N������һ���������Welcome in������������������Ǵ���ģ�
//	����һ���а���ʽ�����Wrong password : �û�����Ĵ������롱���������ԴﵽN��ʱ�������һ�С�Account locked��������������
//��������1��
//	Correct%pw 3
//	correct%pw
//	Correct@PW
//	whatisthepassword!
//	Correct%pw
//	#
//�������1��
//	Wrong password : correct % pw
//	Wrong password : Correct@PW
//	Wrong password : whatisthepassword!
//	Account locked
//
//��������2��
//	cool@gplt 3
//	coolman@gplt
//	coollady@gplt
//	cool@gplt
//	try again
//	#
//�������2��
//	Wrong password : coolman@gplt
//	Wrong password : coollady@gplt
//	Welcome in

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char acPassword[21] = { 0 };
	int nTryTimes = 0;
	cin >> acPassword >> nTryTimes;
	char acInput[21] = { 0 };
	cin.ignore();
	while ((cin.getline(acInput, 21), acInput[0]) != '#') {
		nTryTimes -= 1;
		if (strcmp(acPassword, acInput) == 0) {
			cout << "Welcome in" << endl;
			break;
		}
		else {
			cout << "Wrong password : " << acInput << '\n';
			if (nTryTimes <= 0) {
				cout << "Account locked" << endl;
				break;
			}
		}
	}
	return 0;
}
