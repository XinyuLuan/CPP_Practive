#include <stdio.h>

int main(void){
    char ch;
    printf("Please enter a character.\n");
    int i = scanf("%c", &ch);
    printf("The code for the %c is %d.\n", ch, ch);
    return 0;
}