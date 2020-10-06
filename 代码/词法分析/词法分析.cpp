#include "head.h"
#pragma warning(disable:4996)

char temp;
char input[100];
char token[100];
int input_pointer = 0, token_pointer = 0,row = 0;
using namespace std;

key keyword[]  {{"main",1},{"if",2},{"else",3},{"while",4},{"integer",5},
						{"do",6},{"repeat",7},{"until",8},{"for",9},{"from",10},{"to",11},
						{"step",12} ,{"switch",13},{"of",14},{"case",15},{"default",16},
						{"return",17},{"real",18},{"char",19},{"bool",20},{"and",21},{"or",22},
						{"not",23},{"mod",24},{"read",25},{"write",26} ,{"then",27}};

specialChar sChar[]  { {',',200 },{';',201 },{':',202 },{'{',203 },{'}',204 },{'[',205 },
									{']',206 },{'(',207 },{')',208 } };
int main(){
	while (scanf("%c", &input[input_pointer++]) != EOF);//读入全部的字符
	getToken();
	cout << token;
    return 0;
}