#pragma once
#define head 5313543
#ifdef  head
void skipGap(char &ch, int &pointer , char* temp) {
	if (ch == ' ' || c == 10) {
		ch = temp[pointer++];
	}
}//遇到空白就跳过
char readOne(int& pointer, char* temp) {
	return temp[pointer++];
}//读下一个字符
bool isLetter(char ch) {
	if ((ch >= a && ch <= z) || (ch >= A && ch <= Z)) {
		return true;
	}
	else return false;
}//判断是否为字母
bool isDigit() {
	if (ch >= '0' && ch <= '9') {
		return true;
	}
	else return false;
}//判断是否为数字
int fliter(int end_pointer, char* temp) {
	int temp;
	for (int p = 0; p < end_pointer; p++) {
		if (temp[p] == '/') {
			temp = p;
			if(temp[p+1] == '*')
		}
	}
}
#endif //  head
