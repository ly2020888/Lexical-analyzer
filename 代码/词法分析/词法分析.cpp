#include "head.h"
#pragma warning(disable:4996)

char temp;
char input[1000];
char token[1000];
int input_pointer = 0, token_pointer = 0,row = 0,point = 0;

using namespace std;

key keyword[]  {{"main",1},{"if",2},{"else",3},{"while",4},{"integer",5},
						{"do",6},{"repeat",7},{"until",8},{"for",9},{"from",10},{"to",11},
						{"step",12} ,{"switch",13},{"of",14},{"case",15},{"default",16},
						{"return",17},{"real",18},{"char",19},{"bool",20},{"and",21},{"or",22},
						{"not",23},{"mod",24},{"read",25},{"write",26} ,{"then",27}};

specialChar sChar[]  { {',',200 },{';',201 },{':',202 },{'{',203 },{'}',204 },{'[',205 },
									{']',206 },{'(',207 },{')',208 } };
int main(){
	FILE* f = fopen("./testA.txt", "r");
	//while (fscanf(f,"%c", &input[input_pointer++]) != EOF);//读入全部的字符
	if (!f) {
		cout << "file error";
		return 0;
	}

	while (true) {
		if (feof(f)) break;
		fscanf(f, "%c", &input[input_pointer++]);
	}
	while (point < input_pointer) {
		getToken();

	}
	fclose(f);
    return 0;
}