#include <stdio.h>
main()
{
    int num, remainder, reversed=0;
    printf("x = ");
    scanf("%d", &num);

    int original = num;

    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num = num/10;
    }

    if(original == reversed)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

}
