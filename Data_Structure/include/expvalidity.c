#include <stdio.h>
#include "expvalidity.h"
#include "string.h"
#include "exptree.h"

#define TURE 1
#define FALSE 0

int ExpValidity(String Exp) {
	char check;
	int error = 0;
	int lb = 0;
	int rb = 0;
	
	if (Exp.length == 1 && Exp.ch[0] != '-')
		return FALSE;
	else if((IsOperator(Exp.ch[0]) && Exp.ch[0] != '-' || IsOperator(Exp.ch[Exp.length - 1])) && 
	        Exp.ch[0] != '(' &&
	        exp.ch[Exp.length - 1] != ')')
		return FALSE;
		
	for (int i = 0; i < Exp.length; i++) {
		check = Exp.ch[i];
		if ()
	}
}