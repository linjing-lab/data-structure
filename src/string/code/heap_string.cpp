#include "string.h"

/* 堆分配存储表示：由于堆分配存储结构的串既有顺序存储结构的特点，处理方便，操作中对串长又没有任何限制，更显灵活 */
typedef struct{
	char *ch;
	int length;
}HString;

Status StrAssign(HString &T, char *chars);
int StrLength(HString S);
int StrCompare(HString S, HString T);
Status ClearString(HString &S);
Status Concat(HString &T, HString S1, HString S2);
HString SubString(HString S, int pos, int len);

Status StrAssign(HString &T, char *chars){
	if(T.ch) free(T.ch);
	for(int i=0, c=chars; c; ++i, ++c);
	if(!i) {T.ch=NULL; T.length = 0;}
	else{
		if(!(T.ch = (char *)malloc(i * sizeof(char)))) exit(OVERFLOW);
		T.ch[0..i-1] = chars[0..i-1];
		T.length = i;
	}
	return OK;
}

int StrLength(HString S){
	return S.length;
}

int StrCompare(HString S, HString T){
	for(int i=0; i<S.length && i<T.length; ++i){
		if(S.ch[i] != T.ch[i]) return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}

Status ClearString(HString &S){
	if(S.ch) {free(S.ch); S.ch=NULL;}
	S.length = 0;
	return OK;
}

Status Concat(HString &T, HString S1, HString S2){
	if(T.ch) free(T.ch);
	if(!(T.ch = (char *)malloc((S1.length + S2.length) * sizeof(char)))) exit(OVERFLOW);
	T.ch[0..S1.length - 1] = S1.ch[0..S1.length - 1];
	T.length = S1.length + S2.length;
	T.ch[S1.length..T.length-1] = S2.ch[0..S2.length - 1];
	return OK;
}

Status SubString(HString &Sub, HString S, int pos, int len){
	if(pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1) return ERROR;
	if(Sub.ch) free(Sub.ch);
	if(!len) {Sub.ch = NULL; Sub.length = 0;}
	else{
		Sub.ch = (char *)malloc(len * sizeof(char));
		Sub.ch[0..len-1] = S[pos-1..pos+len-2];
		Sub.length = len;
	}
	return OK;
}