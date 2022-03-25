#include "preface.h"
typedef double ElemType;
typedef ElemType *Complex;

/* Initial the complex */
Status InitComplex(Complex &C, double re, double im){
	C = (ElemType *) malloc(2 * sizeof(ElemType));	/* Allocate storage space for 2 elements. */
	if(!C) exit(OVERFLOW);	/* Failed to allocate storage space. */
	C[0] = re;
	C[1] = im;
	return OK;
}

/* Destroy the complex */
Status DestroyComplex(Complex &C){
	free(C);
	C = NULL;
	return OK;
}

/* Get the value of the k position of complex */
Status Get(Complex C, int k, ElemType &e){
	if(k < 1 || k > 2) return ERROR;
	e = C[k - 1];
	return OK;
}

/* Change the value of the k position */
Status Put(Complex &C, int k, ElemType e){
	if(k < 1 || k > 3) return ERROR;
	C[k - 1] = e;
	return OK;
}

/* Determine whether the elements in the complex are sorted in ascending order. */
Status IsAscending(Complex C){
	return C[0] <= C[1];
}

/* Determine whether the elements in the complex are sorted in descending order. */
Status IsDescending(Complex C){
	return C[0] >= C[1];
}

/* Find the maximum */
Status Max(Complex C, ElemType &e){
	e = C[0] >= C[1] ? C[0] : C[1];
	return OK;
}

/* Find the minimum */
Status Min(Complex C, ElemType &e){
	e = C[0] <= C[1] ? C[0] : C[1];
	return OK;
}

int main(){
	ElemType *C, e;
	InitComplex(C, 2.6, 3.7);
	Get(C, 1, e);
	printf("The value of %d position is %.1lf\n", 1, e);
	Put(C, 2, 3.9);
	Get(C, 2, e);
	printf("The value of %d position is %.1lf\n", 2, e);
	printf("Is the complex ascend? %d\n", IsAscending(C));
	printf("Is the complex descend? %d\n", IsDescending(C));
	Max(C, e);
	printf("The maximum of complex is %.1lf\n", e);
	Min(C, e);
	printf("The minimum of complex is %.1lf\n", e);
	DestroyComplex(C);
	return 0;
}