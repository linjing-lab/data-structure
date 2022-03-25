#include "preface.h"
typedef int ElemType;
typedef ElemType *RationalNumber;

/* Initial the rational number */
Status InitRationalNumber(RationalNumber &R, int s, int m){
	R = (ElemType *) malloc(2 * sizeof(ElemType));	/* Allocate storage space for 2 elements. */
	if(!R || m == 0) exit(OVERFLOW);	/* Failed to allocate storage space. */
	R[0] = s;
	R[1] = m;
	return OK;
}

/* Destroy the rational number */
Status DestroyRationalNumber(RationalNumber &R){
	free(R);
	R = NULL;
	return OK;
}

/* Get the value of the k position of rational number */
Status Get(RationalNumber R, int k, ElemType &e){
	if(k < 1 || k > 2) return ERROR;
	e = R[k - 1];
	return OK;
}

/* Change the value of the k position */
Status Put(RationalNumber &R, int k, ElemType e){
	if(k < 1 || k > 2) return ERROR;
	R[k - 1] = e;
	return OK;
}

/* Determine whether the elements in the RationalNumber are sorted in ascending order. */
Status IsAscending(RationalNumber R){
	return R[0] <= R[1];
}

/* Determine whether the elements in the RationalNumber are sorted in descending order. */
Status IsDescending(RationalNumber R){
	return R[0] >= R[1];
}

/* Find the maximum */
Status Max(RationalNumber R, ElemType &e){
	e = R[0] >= R[1] ? R[0] : R[1];
	return OK;
}

/* Find the minimum */
Status Min(RationalNumber R, ElemType &e){
	e = R[0] <= R[1] ? R[0] : R[1];
	return OK;
}

int main(){
	ElemType *R, e;
	InitRationalNumber(R, 2, 3);
	Get(R, 1, e);
	printf("The value of %d position is %d\n", 1 e);
	Put(R, 2, 6);
	Get(R, 2, e);
	printf("The value of %d position is %d\n", 2, e);
	printf("Is the RationalNumber ascend? %d\n", IsAscending(R));
	printf("Is the RationalNumber descend? %d\n", IsDescending(R));
	Max(R, e);
	printf("The maximum of RationalNumber is %d\n", e);
	Min(R, e);
	printf("The minimum of RationalNumber is %d\n", e);
	DestroyRationalNumber(R);
	return 0;
}