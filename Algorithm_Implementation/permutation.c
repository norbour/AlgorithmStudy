#include <stdio.h>
#include <string.h>
  
void Permutation(char* pStr, char* pBegin) {  
    if (pStr == NULL || pBegin == NULL)  
        return;  
      
    if (*pBegin == '\0') {  
        printf("%s\n", pStr);  
    }  
    else {  
        for (char* pCh = pBegin; *pCh != '\0'; pCh++) {  
			if (strchr(pBegin, *pCh) == pCh) {
            // swap pCh and pBegin  
            char temp = *pCh;  
            *pCh = *pBegin;  
            *pBegin = temp;  
              
            Permutation(pStr, pBegin + 1);    
            // restore pCh and pBegin  
            temp = *pCh;  
            *pCh = *pBegin;  
            *pBegin = temp;  
			}
        }  
    }  
}  

int main(int argc, char *argv[]) {
	char str[] = "aaa";
	Permutation(str, str);
}