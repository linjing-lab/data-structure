#include "queue.h"

#define MAX_QSIZE 100
typedef int QElemType;
typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue &Q);
Status DestroyQueue(SqQueue &Q);
Status ClearQueue(SqQueue &Q);
Status QueueEmpty(SqQueue Q);
int QueueLength(SqQueue Q);
Status GetHead(SqQueue Q, QElemType &e);
Status EnQueue(SqQueue &Q, QElemType e);
Status DeQueue(SqQueue &Q, QElemType &e);
void visit(QElemType *c);
Status QueueTraverse(SqQueue Q, void(*visit)(QElemType *e));

int main(){
	SqQueue Q;
	if(InitQueue(Q)) for(int i=1; i<=9; i++) EnQueue(Q, i);
	printf("The length of queue is: %d\n", QueueLength(Q));
	QElemType e;
	GetHead(Q, e);
	QueueTraverse(Q, visit);
	printf("The head element of the queue is: %d\n", e);
	if(DeQueue(Q, e)) QueueTraverse(Q, visit);
	printf("Is queue empty? %d", QueueEmpty(Q));
	ClearQueue(Q);
	QueueTraverse(Q, visit);
	DestroyQueue(Q);
	return 0;
}

Status InitQueue(SqQueue &Q){
	Q.base = (QElemType *)malloc(MAX_QSIZE * sizeof(QElemType));
	if(!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

Status DestroyQueue(SqQueue &Q){
	free(Q.base);
	Q.base = NULL;
	return OK;
}

Status ClearQueue(SqQueue &Q){
	Q.front = Q.rear = 0;
	return OK;
}

Status QueueEmpty(SqQueue Q){
	if(Q.front == Q.rear) return TRUE;
	else return FALSE;
}

int QueueLength(SqQueue Q){
	return (Q.rear - Q.front + MAX_QSIZE) % MAX_QSIZE;
}

Status GetHead(SqQueue Q, QElemType &e){
	if(Q.front == Q.rear) return ERROR;
	e = Q.base[Q.front];
	return OK;
}

Status EnQueue(SqQueue &Q, QElemType e){
	if((Q.rear + 1) % MAX_QSIZE == Q.front) return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAX_QSIZE;
	return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e){
	if(Q.front == Q.rear) return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAX_QSIZE;
	return OK;
}

void visit(QElemType *c){
	printf("%d ", *c);
}

Status QueueTraverse(SqQueue Q, void(*visit)(QElemType *e)){
	if(Q.front == Q.rear) return ERROR;
	while(Q.front != Q.rear){
		visit(&(Q.base[Q.front]));
		Q.front = (Q.front + 1) % MAX_QSIZE;
	}
	printf("\n");
	return OK;
}