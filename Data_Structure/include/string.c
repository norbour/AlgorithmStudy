#include <stdio.h>
#include "string.h"

String StrNeg(String &Str) {
	String nstr;
	
	for (int i = 0; i < Str->length; i++)
		nstr->ch[i] = Str->ch[Str->length - 1 - i];
		
	nstr->length = Str->length;
	
	return nstr;
}