#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include "../include/assert.h"
#include "../include/mem.h"
#include "../include/list.h"

#define T List_T

T List_push(T list, void *x) {
	T p;
	
	NEW(p);
	p->first = x;
	p->rest = list;
	
	return p;
}