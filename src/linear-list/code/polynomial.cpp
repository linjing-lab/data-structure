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
	p = (Link)malloc(sizeof(LNode));
	if(!p) return ERROR;
	p->next=NULL;
	L.head = L.tail = p;
	L.len = 0;
	return OK;
}

Status ClearList(LinkList &L){
	Link p, q;
	if(L.head != L.tail){
		p = q = L.head->next;
		L.head->next = NULL;
		while(p != L.tail){
			p = q->next;
			free(q);
			q = p;
		}
		free(q);
		L.tail = L.head;
		L.len = 0;
	}
	return OK;
}

Status InsFirst(LinkList &L, Link h, Link s){
	s->next = h->next;
	h->next = s;
	if(h == L.tail)	L.tail = h->next;
	L.len++;
	return OK;
}

Status DelFirst(LinkList &L, Link h, Link &q){
	q = h->next;
	if(!q) return ERROR;
	h->next = q->next;
	if(!h->next) L.tail = h;
	L.len--;
	return OK;
}

Status Append(LinkList &L, Link s){
	int i=1;
	L.tail->next = s;
	while(s->next){
		s = s->next;
		i++;
	}
	L.tail = s;
	L.len += i;
	return OK;
}

Position PriorPos(LinkList L, Link p){
	Link q;
	q = L.head->next;
	if(q == p) return NULL;
	while(q->next != p) q = q->next;
	return q;
}

ElemType GetCurElem(Link p){
	return p->data;
}

Status ListEmpty(LinkList L){
	if(L.len) return FALSE;
	else return TRUE;
}

Position GetHead(LinkList L){
	return L.head;
}

Position NextPos(Link p){
	return p->next;
}

Status LocateElem(LinkList L, ElemType e, Position &q, int(*compare)(ElemType, ElemType)){
	Link p = L.head, pp;
	do{
		pp = p;
		p = p->next;
	}while(p && (compare(p->data, e)) < 0);
	if(!p || compare(p->data, e) > 0){
		q = pp;
		return FALSE;
	}else{
		q = p;
		return TRUE;
	}
}

Status cmp(term a, term b){
	if(a.expn == b.expn) return 0;
	else return (a.expn - b.expn) / abs(a.expn - b.expn);
}

Status CreatePolyn(polynomial &P, int m){
	Position q, s;
	term e;
	InitList(P);
	printf("Please input %d coef, expn: \n", m);
	for(int i=1; i<=m; i++){
		scanf("%f %d", &e.coef, &e.expn);
		if(!LocateElem(P, e, q, cmp)){
			if(MakeNode(s, e)) InsFirst(P, q, s);
		}
	}
	return OK;
}

Status DestroyPolyn(polynomial &P){
	ClearList(P);
	FreeNode(P.head);
	P.tail = NULL;
	P.len = 0;
	return OK;
}

Status PrintPolyn(polynomial P){
	Link q;
	q = P.head->next;
	printf("  coef    expn\n");
	while(q){
		printf("%f  %d\n", q->data.coef, q->data.expn);
		q = q->next;
	}
	return OK;
}

int PolynLength(polynomial P){
	return P.len;
}

void AddPolyn(polynomial &Pa, polynomial &Pb){
	Position ha, hb, qa, qb;
	term a, b;
	ha = GetHead(Pa);
	hb = GetHead(Pb);
	qa = NextPos(ha);
	qb = NextPos(hb);
	while(qa && qb){
		a = GetCurElem(qa);
		b = GetCurElem(qb);
		switch(cmp(a, b)){
			case -1: 
				ha = qa;
				qa = NextPos(ha);
				break;
			case 0: 
				qa->data.coef += qb->data.coef;
				if(qa->data.coef == 0){
					DelFirst(Pa, ha, qa);
					FreeNode(qa);
				}else{
					ha = qa;
				}
				DelFirst(Pb, hb, qb);
				FreeNode(qb);
				qb = NextPos(hb);
				qa = NextPos(ha);
				break;
			case 1: 
				DelFirst(Pb, hb, qb);
				InsFirst(Pa, ha, qb);
				ha = ha->next;
				qb = NextPos(hb);
		}
	}
	if(!ListEmpty(Pb)) Append(Pa, qb);
	DestroyPolyn(Pb);
}

void Opposite(polynomial &Pa){
	Position p;
	p = Pa.head;
	while(p->next){
		p = p->next;
		p->data.coef *= -1;
	}
}

void SubtractPolyn(polynomial &Pa, polynomial &Pb){
	Opposite(Pb);
	AddPolyn(Pa, Pb);
}

Status OrderInsertMerge(LinkList &L, ElemType e, Status(*compare)(term, term)){
	Position q, s;
	if(LocateElem(L, e, q, compare)){
		q->data.coef += e.coef;
		if(!q->data.coef){
			s = PriorPos(L, q);
			if(!s) s = L.head;
			DelFirst(L, s, q);
			FreeNode(q);
		}
		return OK;
	}else{
		if(!MakeNode(s, e)) return ERROR;
		InsFirst(L, q, s);
		return OK;
	}
}

void MultiplyPolyn(polynomial &Pa, polynomial &Pb){
	polynomial Pc;
	Position qa, qb;
	term a, b, c;
	InitList(Pc);
	qa = GetHead(Pa);
	qa = qa->next;
	while(qa){
		a = GetCurElem(qa);
		qb = GetHead(Pb);
		qb = qb->next;
		while(qb){
			b = GetCurElem(qb);
			c.coef = a.coef * b.coef;
			c.expn = a.expn + b.expn;
			OrderInsertMerge(Pc, c, cmp);
			qb = qb->next;
		}
		qa = qa->next;
	}
	DestroyPolyn(Pb);
	ClearList(Pa);
	Pa.head = Pc.head;
	Pa.tail = Pc.tail;
	Pa.len = Pc.len;
}

int main(){
	polynomial p, q;
	int m;
	printf("Please input the numbers of the first polynomial: ");
	scanf("%d", &m);
	CreatePolyn(p, m);
	printf("Please input the numbers of the second polynomial: ");
	scanf("%d", &m);
	CreatePolyn(q, m);
	AddPolyn(p, q);
	printf("Add: \n");
	PrintPolyn(p);
	printf("Please input the numbers of the third polynomial: ");
	scanf("%d", &m);
	CreatePolyn(q, m);
	SubtractPolyn(p, q);
	printf("Subtract: \n");
	PrintPolyn(p);
	printf("Please input the numbers of the fourth polynomial: ");
	scanf("%d", &m);
	CreatePolyn(q, m);
	MultiplyPolyn(p, q);
	printf("Multiply: \n");
	PrintPolyn(p);
	DestroyPolyn(p);
	return 0;
}