#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

/* 常规做法 */
int index_1(string S, string T, int pos){
	int i = pos, j = 1;
	int ls = S[0] + 0 - '0', lt = T[0] + 0 - '0';
	while(i <= ls && j <= lt){
		if(S[i] == T[j]) {++i; ++j;}
		else{i = i- j + 2; j = 1;}
	}
	if(j > lt) return i - lt;
	else return 0;
}

void get_next(string T, int *next){
	int lt = T[0] + 0 - '0';
	int i = 1,  j = 0;
	next[1] = 0;
	while(i < lt){
		if(j == 0 || T[i] == T[j]) {++i; ++j; next[i] = j;}
		else j = next[j];
	}
}

void get_nextval(string T, int *nextval){
	int i = 1, j = 0;
	int lt = T[0] + 0 - '0';
	nextval[1] = 0;
	while(i < lt){
		if(j == 0 || T[i] == T[j]){
			++i; ++j;
			if(T[i] != T[j]) nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else j = nextval[j];
	}
}
/* KMP算法 */
int index_2(string S, string T, int pos){
	int ls = S[0] + 0 - '0', lt = T[0] + 0 - '0';
	int next[lt + 1];
	get_nextval(T, next);
	int i = pos, j = 1;
	while(i <= ls && j <= lt){
		if(j == 0 || S[i] == T[j]) {++i; ++j;}
		else j = next[j];
	}
	if(j > lt) return i - lt;
	else return 0;
}

int main(){
	string s, t;
	cin >> s >> t;
	printf("The position of the T in S is %d\n", index_2(s, t, 1));
	return 0;
}