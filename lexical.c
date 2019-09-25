#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
int isKeyword(char buffer[]){
	char keywords[32][10] ={"default","auto","break","case","char","const","continue","do","double","else","enum","extern","float",
                                  "for","goto","if","int","long","register","void","volatile","while","return","short"
                                            ,"signed","sizeof","static","struct","switch","typedef","union","unsigned"};
	

       int i, flag = 0;
	
	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}
	
	return flag;
}

int isheader(char buffer2[]){
	char header[10][10] ={"stdio","conio","assert","ctype","cocale","math","setjmp","signal","stdarg","stdlib"};
	

       int i, flag2 = 0;
	
	for(i = 0; i < 10; ++i){
		if(strcmp(header[i], buffer2) == 0){
			flag2 = 1;
			break;
		}
	}
	
	return flag2;
}
 
void main(){
	char ch, buffer[15], buffer2[15], operators[] = "+-*/%=<>";
	FILE *fp;
	int i,j=0;
	
	fp = fopen("fib.c","r");
	
	
printf("\n\nOperators :\n\n");	
while((ch = fgetc(fp)) != EOF){
   		for(i = 0; i < 6; ++i){
   			if(ch == operators[i])
   				printf("%c \t", ch);
   		}
   		
   		
   		
	}

fp = fopen("fib.c","r");
printf("\n\nIdentifiers :\n\n");
while((ch = fgetc(fp)) != EOF){
   		
   		
   		if(isalnum(ch)){
   			buffer[j++] = ch;
   		}
   		else if((ch == ' ' ||ch == ',' ||ch == '=' ||ch == '.' ||ch == '<' ||ch == '>' ||ch == '(' ||ch == ')' || ch == '\n') && (j != 0)){
   				buffer[j] = '\0';
   				j = 0;
   				   				
   				if(isKeyword(buffer) != 1)
   					printf("%s \t", buffer);
   				
   		}
   		
	}
fp = fopen("fib.c","r");
printf("\n\nKeywords :\n\n");
while((ch = fgetc(fp)) != EOF){
   		
   		
   		if(isalnum(ch)){
   			buffer[j++] = ch;
   		}
   		else if((ch == ' ' || ch == '\n') && (j != 0)){
   				buffer[j] = '\0';
   				j = 0;
   				   				
   				if(isKeyword(buffer) == 1)
   					printf("%s \t", buffer);
   				
   		}
   		
	}
fp = fopen("fib.c","r");
printf("\n\nSeparators :\n\n");
while((ch = fgetc(fp)) != EOF){
   		
   		
   		if(ch == ',' ||ch == ';' ||ch == '.' ||ch == '(' ||ch == ')'){
   				
   					printf("%c \t", ch);
   				
   		}
   		
	}

fp = fopen("fib.c","r");
printf("\n\nHeader files :\n\n");
while((ch = fgetc(fp)) != EOF){
   		
   		
   		if(isalnum(ch)){
   			buffer2[j++] = ch;
   		}
   		else if((ch == ' ' ||ch == ',' ||ch == '=' ||ch == '.' ||ch == '<' ||ch == '>' ||ch == '(' ||ch == ')' || ch == '\n') && (j != 0)){
   				buffer2[j] = '\0';
   				j = 0;
   				   				
   				if(isheader(buffer2) == 1)
   					printf("%s.h \t", buffer2);
   				
   		}
   		
	}

printf("\n");


	fclose(fp);
	
	
}
