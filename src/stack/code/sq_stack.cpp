#include "stack.h"

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2
typedef int SElemType;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stack_size;
}SqStack;

Status InitStack(SqStack &S){
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stack_size = STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack &S){
	free(S.base);
	free(S.top);
	S.base = NULL;
	return OK;
}

Status ClearStack(SqStack &S){
	S.top = S.base;
	return OK;
}

Status StackEmpty(SqStack S){
	if(S.top == S.base) return TRUE;
	else return FALSE;
}

int StackLength(SqStack S){
	if(S.base == S.top) return ERROR;
	return S.top - S.base;
}

Status GetTop(SqStack S, SElemType &e){
	if(S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S, SElemType e){
	if(S.top - S.base >= S.stack_size){
		S.base = (SElemType *)realloc(S.base, (S.stack_size + STACK_INCREMENT) * sizeof(SElemType));
		if(!S.base) exit(OVERFLOW);
		S.top = S.base + S.stack_size;
		S.stack_size += STACK_INCREMENT;
	}
	*(S.top++) = e;
	return OK;
}

Status Pop(SqStack &S, SElemType &e){
	if(S.top == S.base) return ERROR;
	e = *(--S.top);
	return OK;
}

void visit(SElemType *c){
   printf("%d ",*c);
}

Status StackTraverse(SqStack S, void(*visit)(SElemType *e)){
	if(S.top == S.base) return ERROR;
	while(S.base < S.top) visit(S.base++);
	printf("\n");
	return OK;
}

int main(){
	SqStack stack;
	SElemType e;
	InitStack(stack);
	for(SElemType i=1; i<=8; i++){
		Push(stack, i);
	}
	StackTraverse(stack, visit);
	GetTop(stack, e);
	printf("The top element of the stack is %d\n", e);
	printf("Judge result: %d\n", StackEmpty(stack));
	Push(stack, 0);
	StackTraverse(stack, visit);
	DestroyStack(stack);
	return 0;
}