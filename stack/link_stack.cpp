#include "stack.h"

typedef int SElemType;
typedef struct SNode{
	SElemType data;
	struct SNode *next;
}SNode, *LinkStackPos;

typedef struct{
	LinkStackPos top;
	int count;
}*LinkStack;

Status InitLinkStack(LinkStack &S);
Status ClearLinkStack(LinkStack &S);
Status LinkStackEmpty(LinkStack S);
int LinkStackLength(LinkStack S);
Status GetTop(LinkStack S, SElemType &e);
Status Push(LinkStack &S, SElemType e);
Status Pop(LinkStack &S, SElemType &e);
void visit(SElemType *c);
Status LinkStackTraverse(LinkStack S, void(*visit)(SElemType *e));

int main(){
	LinkStack link;
	SElemType e;
	InitLinkStack(link);
	for(SElemType i=1; i<=8; i++){
		Push(link, i);
	}
	LinkStackTraverse(link, visit);
	GetTop(link, e);
	printf("The length of the stack is: %d\n", LinkStackLength(link));
	printf("The top element of the stack is %d\n", e);
	printf("Judge result: %d\n", LinkStackEmpty(link));
	Pop(link, e);
	printf("The pop element of the stack is %d\n", e);
	Push(link, 0);
	LinkStackTraverse(link, visit);
	ClearLinkStack(link);
	return 0;
}

Status InitLinkStack(LinkStack &S){
	if(!S) return ERROR;
	S->top = NULL;
	S->count = 0;
	return OK;
}

Status ClearLinkStack(LinkStack &S){
	if(!S || !S->count) return ERROR;
	while(S->count--){
		SNode *node = S->top;
		S->top = node->next;
		free(node);
	}
	return OK;
}

Status LinkStackEmpty(LinkStack S){
	if(!S) return ERROR;
	return S->count == 0? TRUE : FALSE;
}

int LinkStackLength(LinkStack S){
	if(!S) return ERROR;
	return S->count;
}

Status GetTop(LinkStack S, SElemType &e){
	if(!S) return ERROR;
	e = S->top->data;
	return OK;
}

Status Push(LinkStack &S, SElemType e){
	if(!S) return ERROR;
	LinkStackPos node = (LinkStackPos)malloc(sizeof(SNode));
	node->data = e;
	node->next = S->top;
	S->top = node;
	S->count++;
	return OK;
}

Status Pop(LinkStack &S, SElemType &e){
	if(!S || !S->count) return ERROR;
	SNode *node = S->top;
	e = node->data;
	S->top = node->next;
	free(node);
	S->count--;
	return OK;
}

void visit(SElemType *c){
   printf("%d ",*c);
}

Status LinkStackTraverse(LinkStack S, void(*visit)(SElemType *e)){
	if(!S || !S->count) return ERROR;
	SNode *node = S->top;
	while(node) {visit(&(node->data)); node = node->next;}
	printf("\n");
	return OK;
}