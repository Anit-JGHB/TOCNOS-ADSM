#include<stdio.h>
char s[20];
int ptr=0,err=0;
void fuE();
void fuEd();
void fuT();
void fuTd();
void fuF();
void main(){
	printf("Enter string ending with $\n");
	scanf("%s",s);
//	printf("%s\n",s);
	fuE();
	if(s[ptr]=='$' && err==0){
		printf("String Accepted\n");
	}
	else{
		printf("String Rejected\n");
		printf("%d\n",err);
	}
}
void fuE(){
	fuT();
	fuEd();
}
void fuEd(){
	if(s[ptr]=='+'){
		ptr++;
		fuT();
		fuEd();
	}
}
void fuT(){
	fuF();
	fuTd();
}
void fuTd(){
	if(s[ptr]=='*'){
		ptr++;
		fuF();
		fuTd();
	}
}
void fuF(){
	if(s[ptr]=='('){
		ptr++;
		fuE();
		if(s[ptr]==')'){
			ptr++;
		}
		else{
			err++;
		}
	}
	else if(s[ptr]=='i' && s[ptr+1]=='d'){
		ptr++;
		ptr++;
	}
	else{
		err++;
	}
}
