#include"head.h"
using namespace std;
bool isA_1(const char &ch) {
	if ((ch >= 'a' && ch <= 'z') || (ch <= 'Z' && ch >= 'A') || ch == '_' || (ch >= '0' && ch <= '9')) {
		return true;
	}
	else return false;
}
bool isSpecialChar(const char& ch) {
	for (int i = 0; i <= 8; i++) {
		if (sChar[i].c == ch) {
			return true;
		}
	}
	return false;
}
void getToken() {//��ʶ�𵽵�һ���������token����
	memset(token, 0, 100 * sizeof(char));
	token_pointer = 0;
	char ch;
	int point = 0;
	do {
		 ch = input[point++];
		 if (ch == ' ' || ch == '\n' || ch == '\t') {//���з��Ϳո�����
			 if (ch == '\n') {
				 row++;
			 }
			 ch = input[point++];
		 }
		 /*------������ĸ�����-------*/

		 if ((ch >= 'a' && ch <= 'z') || (ch <= 'Z' && ch >= 'A')) {
			  do{
				 token[token_pointer++] = ch;
				 ch = input[point++];
			  } while (isA_1(ch));
		 }//ֻ�����Ǳ����ֻ����Ǳ�ʶ��,�����������������ĸ�����»��߶�Ҫ������,ֱ������������Ϊֹ��������ȫ������token

		 /*------�����ַ������-------*/
		 if (isSpecialChar(ch)) {
			 token[token_pointer++] = ch;
			 ch = input[point++];
		 }
	} while (point<input_pointer);
}