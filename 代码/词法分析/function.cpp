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
void getToken() {//把识别到的一个整体放入token数组
	memset(token, 0, 100 * sizeof(char));
	token_pointer = 0;
	char ch;
	int point = 0;
	do {
		 ch = input[point++];
		 if (ch == ' ' || ch == '\n' || ch == '\t') {//换行符和空格跳过
			 if (ch == '\n') {
				 row++;
			 }
			 ch = input[point++];
		 }
		 /*------处理字母的情况-------*/

		 if ((ch >= 'a' && ch <= 'z') || (ch <= 'Z' && ch >= 'A')) {
			  do{
				 token[token_pointer++] = ch;
				 ch = input[point++];
			  } while (isA_1(ch));
		 }//只可能是保留字或者是标识符,无论哪种情况遇到字母数字下划线都要继续读,直到读到非三者为止，把他们全部放入token

		 /*------处理字符的情况-------*/
		 if (isSpecialChar(ch)) {
			 token[token_pointer++] = ch;
			 ch = input[point++];
		 }
	} while (point<input_pointer);
}