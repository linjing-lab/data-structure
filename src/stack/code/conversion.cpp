#include <stdio.h>
#include <stack>
/* STL用法参考 */
// http://www.cplusplus.com/reference/stack/stack/
/* 把十进制转为八进制 */
void conversion(){
	std::stack<int> s;
	int n;
	scanf("%d", &n);
	while(n){
		s.push(n % 8);
		n = n / 8;
	}
	while(!s.empty()){
		int e = s.top();
		s.pop();
		printf("%d", e);
	}
}

int main(){
	conversion();
	return 0;
}