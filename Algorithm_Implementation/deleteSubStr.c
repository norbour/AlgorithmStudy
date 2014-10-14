#include <stdio.h>
#include <string.h>

void DeleteCharFromStr(char* str, int index) {
	if (str == NULL || index < 0) {
		return;
	}
	
	int length = strlen(str);
	if (index < length) {
		while (index < length - 1) {
			str[index] = str[index + 1];
			index ++;
		}
		
		str[length - 1] = '\0';
	}
}

void DeleteRepeatedCharInStr(char* str) {
	if (str == NULL) {
		return;
	}
	
	int hashTable[256] = { 0 };
	int length = strlen(str);
	int i = 0;
	while (i < length) {
		if (!hashTable[str[i]]) {
			hashTable[str[i]] = 1;
			++i;
		}
		else {
			DeleteCharFromStr(str, i);
			--length;
		}
	}
}

int main(int argc, char *argv[]) {
	char str[] = "google!";
	DeleteRepeatedCharInStr(str);
	printf("%s\n", str);
}