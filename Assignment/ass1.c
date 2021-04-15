/*
Program : Delete Comments from program
Author: Swarnava Chakraborty
*/
#include<stdio.h>
int main(){
	FILE *f1, *f2;
	char c;
	f1=fopen("pattern.c", "r");
	f2=fopen("output_without_comments.c", "w");
	while((c=getc(f1)) != EOF){
		if(c == '/')
			if((c=getc(f1)) == '/')
				while((c=getc(f1)) != 10); // 10 denote 'enter or new line' (ignore charater until new line coming)
			else if((c == '*')){
				repeat:
				while((c=getc(f1)) != '*'); // (ignore charater until */ coming)
				if((c=getc(f1)) != '/')
					goto repeat;
				c = getc(f1);
			}
		putc(c, f2);
		printf("%c", c);
	}
	fclose(f1);
	fclose(f2);
}
