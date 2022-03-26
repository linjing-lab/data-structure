#include "linear_list.h"

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
typedef int ElemType;
typedef struct{
	ElemType *elem;	/* Storage space base address */
	int length;	/* Current length */
	int list_size;	/* Currently allocated storage capacity (in sizeof (ElemType)) */
}SqList;

/* Initial the SqList */
Status InitList_Sq(SqList &L){
	/* Construct an empty linear table */
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);	/* Failed to allocate storage space. */
	L.length = 0;	/* Empty table length is 0 */
	L.list_size = LIST_INIT_SIZE; /* Initial storage capacity */
	return OK;
}

/* Destroy the SqList */
Status DestroyList_Sq(SqList &L){
	if(L.elem) free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.list_size = 0;
	return OK;
}

Status ClearList_Sq(SqList &L){
	L.length = 0;
	return OK;
}

/* Judge whether the SqList is empty */
Status ListEmpty_Sq(SqList L){
	if(!L.length) return TRUE;
	else return FALSE;
}

/* Get the length of SqList */
int ListLength_Sq(SqList L){
	return L.length;
}

/* Get the i position of the SqList */
Status GetElem_Sq(SqList L, int i, ElemType &e){
	if(i < 1 || i > LIST_INIT_SIZE) return ERROR;
	e = L.elem[i - 1];
	return OK;
}

/* Compare function */
Status equal(ElemType e1, ElemType e2){
	if(e1 == e2) return TRUE;
	else return FALSE;
}

/* Find the element of SqList with compare function. */
int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)){
	int i = 1;
	ElemType *p = L.elem;
	while(i <= L.length && !(*compare)(*p++, e)) ++i;
	if(i <= L.length) return i;
	else return 0;
}

/* Find the prior element of the current element */
Status PriorElem_Sq(SqList L, int cur_e, int &pre_e){
	for(int i=1; i<=L.length; i++){
		if(L.elem[i - 1] == cur_e) {
			if(i > 1) pre_e = L.elem[i-2];
			else pre_e = INFEASIBLE; 
			break;
		}
	}
	return OK;
}

/* Find the next element of the current element */
Status NextElem_Sq(SqList L, int cur_e, int &next_e){
	for(int i=1; i<=L.length; i++){
		if(L.elem[i - 1] == cur_e) {
			if(i < L.length) next_e = L.elem[i];
			else next_e = INFEASIBLE; 
			break;
		}
	}
	return OK;
}

/* Insert the element into i postion of the SqList */
Status ListInsert_Sq(SqList &L, int i, ElemType e){
	ElemType *p, *q, *new_base;
	if(i < 1 || i > L.length + 1) return ERROR;
	if(L.length >= L.list_size){
		new_base = (ElemType *)realloc(L.elem, (L.list_size + LIST_INCREMENT) * sizeof(ElemType));
		if(!new_base) exit(OVERFLOW);
		L.elem = new_base;
		L.list_size += LIST_INCREMENT;
	}
	q = &(L.elem[i - 1]);
	for(p = &(L.elem[L.length - 1]); p >= q; --p) *(p + 1) = *p;
	*q = e;
	++L.length;
	return OK;
}

/* Delete the i position element of the SqList */
Status ListDelete_Sq(SqList &L, int i, ElemType &e){
	ElemType *p, *q;
	if(i < 1 || i > L.length) return ERROR;
	p = &(L.elem[i - 1]);
	e = *p;
	q = L.elem + L.length - 1;
	for(++p; p<=q; ++p) *(p - 1) = *p;
	--L.length;
	return OK;
}

void visit(ElemType *c){
   printf("%d ",*c);
 }

/* Print */
Status ListTraverse_Sq(SqList L, void(*visit)(ElemType *e)){
	ElemType *p = L.elem;
	for(int i=1; i<=L.length; i++){
		visit(p++);
	}
	printf("\n");
	return OK;
}

/* Union two SqList */
Status union_Sq(SqList &La, SqList Lb){
	ElemType e;
	int La_len = ListLength_Sq(La);
	int Lb_len = ListLength_Sq(Lb);
	for(int i=1; i<=Lb_len; i++){
		GetElem_Sq(Lb, i, e);
		if(!LocateElem_Sq(La, e, equal)) ListInsert_Sq(La, ++La_len, e);
	}
	return OK;
}

/* Merge the SqList in a ascend order */
Status MergeList_Sq(SqList La, SqList Lb, SqList &Lc){
	InitList_Sq(Lc);
	ElemType ai, bj;
	int i, j, k;
	i = j = 1; k = 0;
	int La_len = ListLength_Sq(La);
	int Lb_len = ListLength_Sq(Lb);
	while((i <= La_len) && (j <= Lb_len)){
		GetElem_Sq(La, i, ai); GetElem_Sq(Lb, j, bj);
		if(ai <= bj) {ListInsert_Sq(Lc, ++k, ai); ++i;}
		// else if(ai == bj) {ListInsert_Sq(Lc, ++k, ai); ++i; ++j;}
		else {ListInsert_Sq(Lc, ++k, bj); ++j;}
	}
	while(i <= La_len) {GetElem_Sq(La, i++, ai); ListInsert_Sq(Lc, ++k, ai);}
	while(j <= Lb_len) {GetElem_Sq(Lb, j++, bj); ListInsert_Sq(Lc, ++k, bj);}
	return OK;
}

int main(){
	SqList La, Lb, Lc;
	ElemType pre_e, next_e, e;
	InitList_Sq(La); InitList_Sq(Lb);
	int a[5] = {4, 2, 1, 3, 5};
	int b[5] = {6, 9, 0, 6, 3};
	int c[5] = {1, 2, 5, 8, 9};
	int d[5] = {1, 4, 7, 11, 12};

	for(int i=1; i<=5; i++){
		ListInsert_Sq(La, i, a[i-1]);
		ListInsert_Sq(Lb, i, b[i-1]);
	}
	ListTraverse_Sq(La, visit);
	ListTraverse_Sq(Lb, visit);

	GetElem_Sq(La, 2, e);
	printf("La's %d position element is %d.\n", 2, e);
	
	printf("La's %d is on %d position.\n", 3, LocateElem_Sq(La, 3, equal));

	PriorElem_Sq(La, 4, pre_e);
	printf("La's %d prior is %d.\n", 4, pre_e);

	NextElem_Sq(La, 5, next_e);
	printf("La's %d next is %d.\n", 5, next_e);

	ListInsert_Sq(La, 2, 9);
	ListTraverse_Sq(La, visit);

	ListDelete_Sq(La, 4, e);
	printf("The element %d of La has been deleted.\n", e);
	ListTraverse_Sq(La, visit);

	union_Sq(La, Lb);
	ListTraverse_Sq(La, visit);
	DestroyList_Sq(La);
	DestroyList_Sq(Lb);

	for(int i=1; i<=5; i++){
		ListInsert_Sq(La, i, c[i-1]);
		ListInsert_Sq(Lb, i, d[i-1]);
	}
	MergeList_Sq(La, Lb, Lc);
	ListTraverse_Sq(Lc, visit);
	DestroyList_Sq(Lc);
	return 0;
}