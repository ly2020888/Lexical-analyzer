#include <cstdio>
char input[4096];
char token[4096] = "";
int input_pointer = 0,token_pointer = 0;//两个指针
char temp;
int main(){
    while (scanf("%c",&input[input_pointer++])!=EOF)
    {
        printf("%c",input[input_pointer++]);
    }
    
    return 0;
}