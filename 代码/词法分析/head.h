#pragma once
#ifndef head
#define head 1223

#include <iostream>
#include <cstdio>
#include <cstring>
extern char input[];
extern char token[];
extern int input_pointer, token_pointer;//����ָ��
extern int point;
extern int row;

typedef struct {
	char name[10];
	int id;
}key;

typedef struct {
	char c;
	int id;
}specialChar;

extern key keyword[];
extern specialChar sChar[];
void getToken();
#endif // !head

