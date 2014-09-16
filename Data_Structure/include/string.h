#ifndef _STRING_H_
#define _STRING_H_

typedef struct {
	char *ch;
	int length;
} String;

extern String StrNeg(String &Str);

#endif