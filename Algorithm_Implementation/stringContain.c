#include <stdio.h>
#include <string.h>
#define TRUE    1
#define false   0

// “最好的方法”，时间复杂度O(n + m)，空间复杂度O(1)
// “最好的方法”，时间复杂度O(n + m)，空间复杂度O(1)
int contain4(char * stra, char * strb)
{
    unsigned long long bitA = 0, bitB = 0; //必须用long long,64位才不会溢出
    while (*stra)
    {
        bitA |= (unsigned long long)(1l << (*stra++ & 0x3f)); //取8位中的后6位,a:97:01100001b A:65:01000001b 0x3f:00111111b;
    }
    while (*strb)
    {
        bitB |= (unsigned long long)(1l << (*strb++ & 0x3f));
    }
    return !((bitA ^ bitB) & bitB); //bitA ^ bitB 之后的结果,对于bitB中非0位,为1的话表示A中与B中某位不同,所以不包含
}

int main(){
    char stra[50];
    char strb[50];
    char strc[50];
    sprintf(stra, "BC");
    sprintf(strb, "D");
    sprintf(strc, "DCGSRQPZ");

    if (contain4(stra, strb))
        printf("%s contain %s\n", stra, strb);
    else
        printf("%s not contain %s\n", stra, strb);
}