#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_next(char *p, int *next) {
	int i = 0;
	int j = -1;
	
	int plen = strlen(p);
	
	next[0] = -1;
	while (i < plen - 1) {
		if (j == -1 || p[j] == p[i]) {
			++j; ++i;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
}

int kmp_search(char *s, char *p, int pos) {
	int i = pos, j = 0;
	int slen = strlen(s);
	int plen = strlen(p);
	int *next = (int *)malloc(sizeof(int) * plen);
	
	get_next(p, next);
	
	while (i < slen && j < plen) {
		if (j == -1 || s[i] == p[j]) {
			++i; ++j;
		}else {
			j = next[j];
		}
	}
	
	if (j > plen - 1) {
		return (i - plen);
	}else {
		return -1;
	}
}

int main(int argc, char *argv[]) {
	char s[] = "ababaaaba";
	char p[] = "aab";
	
	int result = kmp_search(s, p, -1);
	
	printf("%d\n", result);
}