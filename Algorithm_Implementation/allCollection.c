#include <stdio.h>
#include <stdlib.h>
#include "../Data_Structure/include/cstack.h"

void AllCollection(char* str, int num, CStack *S) {
	if (str == NULL) 
		return;
	
	if (num == 0) {
		for (int i = 0; i < CStackLength(S); i++) {
			printf("%c", S->elem[i]);
			if (i == CStackLength(S) - 1)
				printf("\n");
		}
		
		return;
	}
	
	if (*str == '\0') {
		return;
	} else {
		AllCollection(str + 1, num, S);
		
		Push_C(S, *str);
		AllCollection(str + 1, num - 1, S);
		Pop_C(S);
	}
}

int main(int argc, char *argv[]) {
	char str[] = "12345";
	CStack S;
	InitCStack(&S);
	AllCollection(str, 4, &S);
}