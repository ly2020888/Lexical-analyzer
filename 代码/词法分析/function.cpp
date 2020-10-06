#include"head.h"
using namespace std;
void result(char a[], int id) {
	cout << "<" << id<< "," << a << ">" << endl;
}
void result(char a, int id) {
	cout << "<" << id << "," << a << ">" << endl;
}
bool isA_1(const char &ch) {
	if ((ch >= 'a' && ch <= 'z') || (ch <= 'Z' && ch >= 'A') || ch == '_' || (ch >= '0' && ch <= '9')) {
		return true;
	}
	else return false;
}
void printError(int code) {
	cout << "在" << row << "行处出现错误：" << endl;
	try {
		switch (code)
		{
		case 0:	throw "请输入正确的标识符";
			break;
		case 1: throw "请输入正确的浮点数";
			break;
		case 2: throw "无法识别的算符";
			break;
		case 3: throw "存在无法匹配的算符";
			break;
		}
	}
	catch (const char* msg) {
		cout << msg;
	}
}
bool isSpecialChar(const char& ch) {
	for (int i = 0; i <= 8; i++) {
		if (sChar[i].c == ch) {
			return true;
		}
	}
	return false;
}
specialChar* getSpecialChar(const char& ch) {
	for (int i = 0; i <= 8; i++) {
		if (sChar[i].c == ch) {
			return &sChar[i];
		}
	}
	return nullptr;
}
bool isKeyWord(const char ch[]) {
	for (int i = 0; i <= 27; i++) {
		if (!strcmp(ch,(const char*)&keyword[i].name)) {
			return true;
		}
	}
	return false;
}
key* getKeyWord(const char ch[]) {
	for (int i = 0; i <= 27; i++) {
		if (!strcmp(ch, (const char*)&keyword[i].name)) {
			return &keyword[i];
		}
	}
	return nullptr;
}
void getToken() {//把识别到的一个整体放入token数组
	memset(token, 0, 100 * sizeof(char));
	token_pointer = 0;
	char ch = input[point];
	if (point < input_pointer) {//未到文件尾
 
		 if (ch == ' ' || ch == '\n' || ch == '\t') {//换行符和空格跳过
			 if (ch == '\n') {
				 row++;
			 }
			 point++;
			 return;
		 }
		 /*------处理字母的情况-------*/

		 if ((ch >= 'a' && ch <= 'z') || (ch <= 'Z' && ch >= 'A')|| ch == '_' ) {
			  do{
				 token[token_pointer++] = ch;
				 ch = input[++point];
			  } while (isA_1(ch));
			  if (isKeyWord(token)) {
				  key* temp = getKeyWord(token);
				  result(token, temp->id);//保留字
			  }
			  else result(token, 28);// 标识符
			  return;
		 }//只可能是保留字或者是标识符,无论哪种情况遇到字母数字下划线都要继续读,直到读到非三者为止，把他们全部放入token

		 /*------处理字符的情况-------*/
		 if (isSpecialChar(ch)) {
			 specialChar* temp = getSpecialChar(ch);
			 result(ch, temp->id);
			 point++;
			 return;
		 }
		 /*------处理算符的情况-------*/
		 if (ch == '+' || ch == '-' || ch == '*' || ch == '/'||ch=='=')
		 {
			 if (ch == '+') {
				 if (input[point + 1] == '+') {//++
					 token[token_pointer++] = ch;
					 ch = input[point++];
					 token[token_pointer++] = ch;
					 result(token, 52);
					 return;
				 }
				 else {//+
					 result(ch, 53);
					 point++;
					 return;
				 }

			 }
			 

				 
			 if (ch == '-') {
				 if (input[point + 1] == '-') {//--
					 token[token_pointer++] = ch;
					 ch = input[point++];
					 token[token_pointer++] = ch;
					 result(token, 54);
					 return;
				 }
				 else {//-
					 result(ch, 55);
					 point++;
					 return;
				 }
			 }
				 
			 if (ch == '/') {
				 if (input[point + 1] == '*') {//多行注释
					 for (int i = point + 1; i <= input_pointer - 1; i++) {
						 if (input[i] == '*' && input[i + 1] == '/') {
							 point = i + 2;
							 return;
						 }
						 else {
							 if (i == input_pointer - 1) {
								 point = i + 1;
								 printError(3);//到结尾都没有匹配则报错，并且全部跳过
								 return;
							 }
						 }
					 }
				 }
				 else {
					 if (input[point + 1] == '/') {//如果是单行注释符号则遇到下一个换行符之前的字符全部忽略
						 for (int i = point + 2; i <= input_pointer; i++) {
							 if (input[i] == '\n' || i == input_pointer) {
								 point = i + 1;
								 return;
							 }
						 }
						 return;
					 }
					 else {
						 if (input[point + 1] == '=') {//除号等于
							 token[token_pointer++] = ch;
							 ch = input[point++];
							 token[token_pointer++] = ch;
							 result(token, 56);
							 return;
						 }
						 else {//除于
							 result(ch, 57);
							 point++;
							 return;
						 }
					 }

				 }
			 }
				 
			 if (ch == '*') {
				 if (input[point + 1] == '=') {//*=
					 token[token_pointer++] = ch;
					 ch = input[point++];
					 token[token_pointer++] = ch;
					 result(token, 58);
					 return;
				 }
				 else {//*
					 result(ch, 59);
					 point++;
					 return;
				 }

			 }
			 if (ch == '=') {
				 if (input[point + 1] == '=') {//*=
					 token[token_pointer++] = ch;
					 ch = input[point++];
					 token[token_pointer++] = ch;
					 result(token, 60);
					 return;
				 }
				 else {//*
					 result(ch, 61);
					 point++;
					 return;
				 }

			 }
				
		 }
				 
		 /*------处理数字/小数的情况-------*/
		if (ch >= '0' && ch <= '9') {
			 bool hadDot = false;
			 do {
				 if (ch == '.'&&!hadDot) {//小数点应只出现一次且不能位于首位
					 hadDot = true;
				 }
				 else {
					 if (hadDot&& ch == '.') {
						printError(1);
						break;
					 }
				 }
				 token[token_pointer++] = ch;
				 
				 ch = input[++point];
			 } while (ch >= '0' && ch <= '9'|| (ch=='.'));
			 result(token, 51);//数字
			 return;
		 }
	}
}