#include "linear_list.h"

typedef struct{
	float coef;	/* 系数 */
	int expn;	/* 指数 */
}term, ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *Link, *Position;

typedef struct{
	Link head, tail;
	int len;
}LinkList;

typedef LinkList polynomial;

Status MakeNode(Link &p, ElemType e){
	p = (Link)malloc(sizeof(LNode));
	if(!p) return ERROR;
	p->data = e;
	return OK;
}

Status FreeNode(Link &p){
	free(p);
	p = NULL;
	return OK;
}

Status InitList(LinkList &L){
	Link p;
	p = (Link)maloc(sizeof(LNode));
	if(!p) return ERROR;
	p->next=NULL;
	L->head = L->tail = p;
	L->len = 0;
	return OK;
}

Status ClearList(LinkList &L){
	Link p, q;
	if(L->head != L->tail){
		p = q = L->head->next;
		L->head->next = NULL;
		while(p != L->tail){
			p = q->next;
			free(q);
			q = p;
		}
		free(q);
		L->tail = L->head;
		L->len = 0;
	}
	return OK;
}

Status InsFirst(LinkList &L, Link h, Link s){
	s->next = h->next;
	h->next = s;
	if(h == L->tail)	L->tail = h->next;
	L->len++;
	return OK;
}

Status DelFirst(LinkList &L, Link h, Link &q){
	q = h->next;
	if(!q) return ERROR;
	h->next = q->next;
	if(!h->next) L->tail = h;
	L->len--;
	return OK;
}

Status Append(LinkList &L, Link s){
	int i=1;
	L->tail->next = s;
	while(s->next){
		s = s->next;
		i++;
	}
	L->tail = s;
	L->len += i;
	return OK;
}

Position PriorPos(LinkList L, Link p){
	Link q;
	q = L->head->next;
	if(q == p) return NULL;
	while(q->next != p) q = q->next;
	return q;
}

ElemType GetCurElem(Link p){
	return p->data;
}

Status ListEmpty(LinkList L){
	if(L->len) return FALSE;
	else return TRUE;
}

Position GetHead(LinkList L){
	return L->head;
}

Position NextPos(Link p){
	return p->next;
}

Status LocateElem(LinkList L, ElemType e, Position &q, int(*compare)(ElemType, ElemType)){
	Link p = L->head, pp;
	
}