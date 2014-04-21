#include <stdio.h>
#include <stdlib.h>
#define SIZE 80
int getGCD(int x, int y);

/**
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}*/

int main(void){
	char s[SIZE];
	int c;
	int x;
	int y;
	int i = 0;
	

	puts("Please enter two integer, and we can get GCD");

	while(i < SIZE - 1 && (c = getchar()) != '\n'){
		s[i++] = c;
	}
	s[i] = '\0';

	sscanf(s, "%d%d", &x,&y);
	int gcd = getGCD(x,y);
	printf("%d", gcd);
	system("pause");
	return 0;
}

int getGCD(int x, int y){

	int bigger = x;
	if(bigger < y){
		bigger = y;
		y = x;
	}

	int count = 0;
	for(count = y ;count <= 1; count--){
		if(bigger % count == 0 && y % count == 0){
			return count;
		}
	}
	return 1;
}

