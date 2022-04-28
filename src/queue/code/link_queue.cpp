#include "queue.h"

typedef int QElemType;
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q);
Status DestroyQueue(LinkQueue &Q);
Status ClearQueue(LinkQueue &Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q, QElemType &e);
Status EnQueue(LinkQueue &Q, QElemType e);
Status DeQueue(LinkQueue &Q, QElemType &e);
void visit(QElemType *c);
Status QueueTraverse(LinkQueue Q, void(*visit)(QElemType *e));

int main(){
	LinkQueue Q;
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

Status InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q){
	while(Q.front){
		QueuePtr q = Q.front->next;
		free(Q.front);
		Q.front = q;
	}
	return OK;
}

Status ClearQueue(LinkQueue &Q){
	while(Q.front->next){
		QueuePtr q = Q.front->next;
		free(Q.front);
		Q.front = q;
	}
	Q.front->next = NULL;
	Q.front->data = NULL;
	return OK;
}

Status QueueEmpty(LinkQueue Q){
	if(Q.front == Q.rear) return TRUE;
	else return FALSE;
}

int QueueLength(LinkQueue Q){
	int n = 0;
	QueuePtr p = Q.front;
	while(p != Q.rear){n++; p=p->next;}
	return n;
}

Status GetHead(LinkQueue Q, QElemType &e){
	if(Q.front == Q.rear) return ERROR;
	e = Q.front->next->data;
	return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e){
	if(Q.front == Q.rear) return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p) Q.rear = Q.front;
	free(p);
	return OK;
}

void visit(QElemType *c){
	printf("%d ", *c);
}

Status QueueTraverse(LinkQueue Q, void(*visit)(QElemType *e)){
	if(Q.front == Q.rear) return ERROR;
	QueuePtr p = Q.front->next;
	while(p){
		visit(&(p->data));
		p = p->next;
	}
	printf("\n");
	return OK;
}