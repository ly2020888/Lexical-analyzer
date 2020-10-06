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
	cout << "��" << row << "�д����ִ���" << endl;
	try {
		switch (code)
		{
		case 0:	throw "��������ȷ�ı�ʶ��";
			break;
		case 1: throw "��������ȷ�ĸ�����";
			break;
		case 2: throw "�޷�ʶ������";
			break;
		case 3: throw "�����޷�ƥ������";
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
void getToken() {//��ʶ�𵽵�һ���������token����
	memset(token, 0, 100 * sizeof(char));
	token_pointer = 0;
	char ch = input[point];
	if (point < input_pointer) {//δ���ļ�β
 
		 if (ch == ' ' || ch == '\n' || ch == '\t') {//���з��Ϳո�����
			 if (ch == '\n') {
				 row++;
			 }
			 point++;
			 return;
		 }
		 /*------������ĸ�����-------*/

		 if ((ch >= 'a' && ch <= 'z') || (ch <= 'Z' && ch >= 'A')|| ch == '_' ) {
			  do{
				 token[token_pointer++] = ch;
				 ch = input[++point];
			  } while (isA_1(ch));
			  if (isKeyWord(token)) {
				  key* temp = getKeyWord(token);
				  result(token, temp->id);//������
			  }
			  else result(token, 28);// ��ʶ��
			  return;
		 }//ֻ�����Ǳ����ֻ����Ǳ�ʶ��,�����������������ĸ�����»��߶�Ҫ������,ֱ������������Ϊֹ��������ȫ������token

		 /*------�����ַ������-------*/
		 if (isSpecialChar(ch)) {
			 specialChar* temp = getSpecialChar(ch);
			 result(ch, temp->id);
			 point++;
			 return;
		 }
		 /*------������������-------*/
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
				 if (input[point + 1] == '*') {//����ע��
					 for (int i = point + 1; i <= input_pointer - 1; i++) {
						 if (input[i] == '*' && input[i + 1] == '/') {
							 point = i + 2;
							 return;
						 }
						 else {
							 if (i == input_pointer - 1) {
								 point = i + 1;
								 printError(3);//����β��û��ƥ���򱨴�����ȫ������
								 return;
							 }
						 }
					 }
				 }
				 else {
					 if (input[point + 1] == '/') {//����ǵ���ע�ͷ�����������һ�����з�֮ǰ���ַ�ȫ������
						 for (int i = point + 2; i <= input_pointer; i++) {
							 if (input[i] == '\n' || i == input_pointer) {
								 point = i + 1;
								 return;
							 }
						 }
						 return;
					 }
					 else {
						 if (input[point + 1] == '=') {//���ŵ���
							 token[token_pointer++] = ch;
							 ch = input[point++];
							 token[token_pointer++] = ch;
							 result(token, 56);
							 return;
						 }
						 else {//����
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
				 
		 /*------��������/С�������-------*/
		if (ch >= '0' && ch <= '9') {
			 bool hadDot = false;
			 do {
				 if (ch == '.'&&!hadDot) {//С����Ӧֻ����һ���Ҳ���λ����λ
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
			 result(token, 51);//����
			 return;
		 }
	}
}