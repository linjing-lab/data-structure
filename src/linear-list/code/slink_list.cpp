/* 以集合运算(A-B)U(B-A)为例讨论静态链表的算法 */
#include "linear_list.h"

#define MAX_SIZE 1000
typedef int ElemType;
typedef struct{
	ElemType data;
	int cur;
}component, SLinkList[MAX_SIZE];

void InitSpace_SL(SLinkList &space);
int Malloc_SL(SLinkList &space);
void Free_SL(SLinkList &space, int k);
void difference(SLinkList &space, int &S);
void ListTraverse_SL(SLinkList space,int S);

int main(){
	SLinkList space;
	int S;
	difference(space, S);
	printf("After union the space: \n");
	ListTraverse_SL(space, S);
	return 0;
}

void InitSpace_SL(SLinkList &space){
	for(int i=0; i < MAX_SIZE - 1; i++) space[i].cur = i + 1;
	space[MAX_SIZE - 1].cur = 0;
}

int Malloc_SL(SLinkList &space){
	int i = space[0].cur;
	if(space[0].cur) space[0].cur = space[i].cur;
	return i;
}

void Free_SL(SLinkList &space, int k){
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

void difference(SLinkList &space, int &S){
	InitSpace_SL(space);
	S = Malloc_SL(space);
	int r = S, m, n;
	printf("Please input the element numbers of A and B: \n");
	scanf("%d %d", &m, &n);
	printf("Please input the elements of A: \n");
	for(int j=1; j<=m; j++){
		int i = Malloc_SL(space);
		scanf("%d", &space[i].data);
		space[r].cur = i;
		r = i;
	}
	space[r].cur = 0;
	printf("Please input the elements of B: \n");
	for(int j=1; j<=n; j++){
		ElemType b;
		scanf("%d", &b);
		int p = S;
		int k = space[S].cur;
		while(k != space[r].cur && space[k].data != b){
			p = k;
			k = space[k].cur;
		}
		if(k == space[r].cur){
			int i = Malloc_SL(space);
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;
		}else{
			space[p].cur = space[k].cur;
			Free_SL(space, k);
			if(r == k) r = p;
		}
	}
}

void ListTraverse_SL(SLinkList space,int S){//遍历静态链表 
    int k=space[S].cur;
    while(space[k].cur){
    	printf("%d ", space[k].data);
    	k = space[k].cur;
    }
    printf("%d\n", space[k].data);
} 