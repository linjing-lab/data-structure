#include <stdio.h>
int count = 0;
void move(char x, int n, char z){
	printf("%i. Move disk %i from %c to %c\n", ++count, n, x, z);
}

void hanoi(int n, char x, char y, char z){
	if(n==1) move(x, 1, z);
	else{
		hanoi(n-1, x, z, y);
		move(x, n, z);
		hanoi(n-1, y, x, z);
	}
}

int main(){
	int n;
	char x, y, z;
	scanf("%d %c %c %c", &n, &x, &y, &z);
	hanoi(n, x, y, z);
	return 0;
}