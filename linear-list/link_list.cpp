#include "linear_list.h"

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

Status InitList_L(LinkList &L){
	L = (LinkList)malloc(sizeof(LNode));
	if(!L) exit(OVERFLOW);
	L->next = NULL;
	return OK;
}

/* Insert from head */
Status CreateList_LH(LinkList &L, int n){
	if(!L) InitList_L(L);
	for(int i=n; i>0; --i){
		LinkList p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);	/* Input the value of element */
		p->next = L->next;
		L->next = p;	/* Insert into head */
	}
	return OK;
}

/* Insert from tail */
Status CreateList_LT(LinkList &L, int n){
	if(!L) InitList_L(L);
	LinkList r=L;
	for(int i=1; i<=n; i++){
		LinkList p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = NULL;
		r->next = p;
		r = p;
	}
	return OK;
}

/* Destroy the LinkList, don't save the head node.*/
Status DestroyList_L(LinkList &L){
	LinkList p=L;
	while(p){
		L = L->next;
		free(p);
		p = L;
	}
	return OK;
}

/* 等价于一个个删除结点，但是保留头节点 */
Status ClearList_L(LinkList &L){
	LinkList p;
	while(L->next){
		p = L->next;
		L->next = p->next;
		free(p);
	}
	return OK;
}

/* Judge whether the LinkList is empty */
Status ListEmpty_L(LinkList L){
	if(L->next==NULL) return TRUE;
	else return FALSE;
}

/* Get the length of LinkList */
int ListLength_L(LinkList L){
	int length = 0;
	LinkList p = L->next;
	while(p != NULL){
		++length;
		p = p->next;
	}
	return length;
}

/* Get the i position of the LinkList */
Status GetElem_L(LinkList L, int i, ElemType &e){
	LinkList p = L->next;
	int j = 1;
	while(p && j < i){
		p = p->next;
		++j;
	}
	if(!p || j > i) return ERROR;
	e = p->data;
	return OK;
}

/* Compare function */
Status equal(ElemType e1, ElemType e2){
	if(e1 == e2) return TRUE;
	else return FALSE;
}

/* Find the element of LinkList with compare function. */
ElemType LocateElem_L(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType)){
	LinkList p=L->next;
	while(p && compare(p->data, e)){
		p = p->next;
	}
	return p->data;
}

/* Find the next element of the current element */
Status NextElem_L(LinkList L, int cur_e, int &next_e){
	next_e = cur_e->next->data;
	return OK;
}

/* Insert the element into i postion of the LinkList */
Status ListInsert_L(LinkList &L, int i, ElemType e){
	LinkList p=L;
	int j=0;
	while(p && j < i - 1){
		p = p->next;
		++j;
	}
	if(!p || j > i - 1) return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

/* Delete the i position element of the LinkList */
Status ListDelete_L(LinkList &L, int i, ElemType &e){
	LinkList p=L, q;
	int j=0;
	while(p->next && j < i - 1){	/* 让p指向它的前驱 */
		p = p->next;
		++j;
	}
	if(!(p->next) || j < i - 1) return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
}

void visit(ElemType *c){
   printf("%d ",*c);
 }

/* Print */
Status ListTraverse_L(LinkList L, void(*visit)(ElemType *e)){
	LinkList p=L;
	while(p->next != NULL){
		p = p->next;
		visit(&(p->data));
	}
	printf("\n");
	return OK;
}

/* Merge the LinkList in a ascend order */
Status MergeList_L(LinkList La, LinkList Lb, LinkList &Lc){
	LinkList pa = La->next, pb = Lb->next, pc;
	Lc = pc = La;
	while(pa && pb){
		if(pa->data <= pb->data){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}else{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	return OK;
}

