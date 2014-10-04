#include <stdio.h>

int get_strlen(char *str) {
	if (str == NULL) {
		return 0;
	} else {
		int len = 0;
		while (str[len] != '\0') {
			len++;
		}
		
		return len;
	}
}

enum Direction { FORWARD = 1, BACKWARD = -1 };

int get_word_len(char *pos, enum Direction direc) {
	
}

int main(int argc, char *argv[]) {
	char *str = "Good morning my friend!";
	printf("%d\n", get_strlen(str));
}