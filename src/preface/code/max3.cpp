#include <stdio.h>

/* if else */
int max3_1(int x, int y, int z){
	if(x>y){
		if(x>z) return x;
		else return z;
	}else{
		if(y>z) return y;
		else return z;
	}
}

/* 条件语句 */
int max3_2(int x, int y, int z){
	return (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
}

int main(){
	printf("maximum from max3_1 is %d, from max3_2 is %d\n", max3_1(1, 2, 5), max3_2(1, 2, 5));
	return 0;
}