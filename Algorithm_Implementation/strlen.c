#include <stdio.h>

int _strlen(char str[]) {
	if (str == NULL || str[0] == '\0')
		return 0;
		
	return 1 + _strlen(str + 1);
}

int main(int argc, char *argv[]) {
	char str1[] = "abcdef";
	char str2[] = "a";
	char str3[] = "";
	char *str4 = NULL;
	
	printf("%d\n", _strlen(str1));
	printf("%d\n", _strlen(str2));
	printf("%d\n", _strlen(str3));
	printf("%d\n", _strlen(str4));
}