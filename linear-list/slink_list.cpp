#include "linear_list.h"

typedef int ElemType;
#define MAX_SIZE 1000
typedef struct{
	ElemType data;
	int cur;
}component, SLinkList[MAX_SIZE];

Status InitList_SL(SLinkList &space){
	for(int i=0; i < MAX_SIZE; i++){
		space[i].cur = i + 1;
	}
	space[MAX_SIZE - 1].cur = 0;
	return OK;
}

Status ListEmpty_SL(SLinkList space){
	int i = space[MAX_SIZE - 1].cur;
	if(i == 0) return TRUE;
	else return FALSE;
}

int Malloc_SL(SLinkList space){
	int i = space[0].cur;
	if(space[0].cur) space[0].cur = space[i].cur;
	return i;
}

Status Free_SL(SLinkList &space, int k){
	space[k].cur = space[0].cur; space[0].cur = k;
	return OK;
}

int ListLength_SL(SLinkList S){
	int count = 0;
	int i = S[MAX_SIZE - 1].cur;
	while(i){
		i = S[i].cur;
		count++;
	}
	return count;
}

Status GetElem_SL(SLinkList S, int i, ElemType &e){
	if(i < 1 || i > ListLength_SL(S)) return ERROR;
	int k = MAX_SIZE - 1;
	for(int j=1; j<=i-1; j++) k = S[k].cur;
	e = S[S[k].cur].data;
	return OK;
}

/* Compare function */
Status equal(ElemType e1, ElemType e2){
	if(e1 == e2) return TRUE;
	else return FALSE;
}

int LocateElem_SL(SLinkList S, ElemType e, Status(*compare)(ElemType, ElemType)){
	int i = S[0].cur;
	while(i && !compare(S[i].data, e)) i = S[i].cur;
	if(!i) return ERROR;
	return i;
}

Status ListInsert_SL(SLinkList &S, int i, ElemType e){
	int k = MAX_SIZE - 1;
	if(i < 1 || i > ListLength_SL(S) + 1) return ERROR;
	int j = Malloc_SL(S);
	if(j){
		S[j].data = e;
		for(int l=1; l<=i-1; l++) k = S[k].cur;
		S[j].cur = S[k].cur;
		S[k].cur = j;
		return OK;
	}
	return ERROR;
}

Status ListDelete_SL(SLinkList &S, int i, ElemType &e){
	if(i < 1 || i > ListLength_SL(S)) return ERROR;
	int k = MAX_SIZE - 1;
	for(int j=1; j<=i-1; j++) k = S[k].cur;
	int j = S[k].cur;
	e = S[j].data;
	S[k].cur = S[j].cur;
	Free_SL(S, j);
	return OK;
}

void visit(ElemType *c){
   printf("%d ",*c);
}


Status ListTraverse_SL(SLinkList S, void(*visit)(ElemType *e)){
	int i = S[MAX_SIZE - 1].cur;
	while(i){
		visit(&(S[i].data));
		i = S[i].cur;
	}
	printf("\n");
	return OK;
}

Status ClearList_SL(SLinkList &S){
	int i = S[MAX_SIZE - 1].cur;
	ElemType e;
	for(int j=1; j<=ListLength_SL(S); j++) ListDelete_SL(S, 1, e);
	S[MAX_SIZE - 1].cur = 0;
	return OK;
}

int main(){
	SLinkList S;
	ElemType e;
	InitList_SL(S);
	printf("After initial S: L.length=%d\n", ListLength_SL(S));

	for(int j=0x1; j<=0x5; j++) ListInsert_SL(S, 1, j+5);
	printf("After input S: L.length=%d\n", ListLength_SL(S));
	ListTraverse_SL(S, visit);
	GetElem_SL(S, 2, e);
	printf("S's %d position element is %d.\n", 2, e);
	printf("S's %d is on %d position.\n", 9, LocateElem_SL(S, 9, equal));

	ListInsert_SL(S, 2, 8);
	ListTraverse_SL(S, visit);

	ListDelete_SL(S, 2, e);
	ListTraverse_SL(S, visit);
	ClearList_SL(S);
}
