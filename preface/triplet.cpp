#include <stdio.h>
#include <cstdlib>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int ElemType;
typedef ElemType Status;
typedef ElemType *Triplet;

/* Initial the triple */
Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3){
	/* Construct the triple T, and set the initial value of the three elements of t as v1, v2, v3 */
	T = (ElemType *) malloc(3 * sizeof(ElemType));	/* Allocate storage space for 3 elements. */
	if(!T) exit(OVERFLOW);	/* Failed to allocate storage space. */
	T[0] = v1;
	T[1] = v2;
	T[2] = v3;
	return OK;
}

/* Destroy the triplet */
Status DestroyTriplet(Triplet &T){
	free(T);
	T = NULL;
	return OK;
}

/* Get the value of the i position of triplet */
Status Get(Triplet T, int i, ElemType &e){
	if(i < 1 || i > 3) return ERROR;
	e = T[i - 1];
	return OK;
}

/* Change the value of the i position */
Status Put(Triplet &T, int i, ElemType e){
	if(i < 1 || i > 3) return ERROR;
	T[i - 1] = e;
	return OK;
}

/* Determine whether the elements in the triplet are sorted in ascending order. */
Status IsAscending(Triplet T){
	return (T[0] <= T[1]) && (T[1] <= T[2]);
}

/* Determine whether the elements in the triplet are sorted in descending order. */
Status IsDescending(Triplet T){
	return (T[0] >= T[1]) && (T[1] >= T[2]);
}

/* Find the maximum */
Status Max(Triplet T, ElemType &e){
	e = (T[0] >= T[1]) ? ((T[0] >= T[2]) ? T[0] : T[2]) : ((T[1] >= T[2]) ? T[1] : T[2]);
	return OK;
}

/* Find the minimum */
Status Min(Triplet T, ElemType &e){
	e = (T[0] <= T[1]) ? ((T[0] <= T[2]) ? T[0] : T[2]) : ((T[1] <= T[2]) ? T[1] : T[2]);
	return OK;
}

int main(){
	ElemType *T, e;
	InitTriplet(T, 1, 2, 3);
	Get(T, 1, e);
	printf("The value of %d position is %d\n", 1, e);
	Put(T, 1, 4);
	Get(T, 1, e);
	printf("The value of %d position is %d\n", 1, e);
	printf("Is the triple ascend? %d\n", IsAscending(T));
	printf("Is the triple descend? %d\n", IsDescending(T));
	Max(T, e);
	printf("The maximum of triple is %d\n", e);
	Min(T, e);
	printf("The minimum of triple is %d\n", e);
	return 0;
}