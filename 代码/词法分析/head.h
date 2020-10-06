#pragma once
#ifndef head
#define head 1223

#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iterator>
extern char input[];
extern char token[];
extern int input_pointer, token_pointer;//Á½¸öÖ¸Õë
extern int row;
extern int point;

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

