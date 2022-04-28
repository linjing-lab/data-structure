#include <stdio.h>
#include <stack>
int main(){
	std::stack<char> s;
	char ch;
	while((ch=getchar())!='\n'){
		switch(ch){
			case '(': s.push(ch);
				break;
			case '{': s.push(ch);
				break;
			case '[': s.push(ch);
				break;
			case ')':
				if(!s.empty() && (s.top() == '(')) s.pop();
				break;
			case '}':
				if(!s.empty() && (s.top() == '{')) s.pop();
				break;
			case ']':
				if(!s.empty() && (s.top() == '[')) s.pop();
				break;
		}
	}
	if(s.empty()) printf("match!");
	else printf("not match!");
	return 0;
}