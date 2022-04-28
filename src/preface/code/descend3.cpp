#include <stdio.h>

void descend3(int &x, int &y, int &z){
	int temp = 0;
	if(x < y){
		temp = x;
		x = y;
		y = temp;
	} /* 此时x > y */
	if(y < z){
		temp = z;
		z = y;	/* z拿到了y的值 */
		if(x > temp){	/* temp现在拿到了z的值，目前判断x与z哪个大 */
			y = temp;
		}else{
			y = x;
			x = temp;
		}
	}
}
int main(){
	int x = 1, y = 2, z = 3;
	descend3(x, y, z);
	printf("%d %d %d\n", x, y, z);
	return 0;
}