#include <stdio.h>

int arr(void) {
    int i;
    int a[40];
    a[0] = 0;
    a[1] = 1;
    printf("%d ",a[0]);
    printf("%d ",a[1]);

    for (i = 2; i < 40; i++) {
        a[i] = a[i - 1] + a[i - 2];
        printf("%d ",a[i]);
    }

    printf("\n");

    return 0;
}
int fbi(int i)
{
    if (i < 2) {
        return (i == 0) ? 0 : 1;
    }
    return fbi(i -1) + fbi(i - 2);
}

void printf_fbi(void)
{
    int i;
    for (i = 0; i < 40; i++) {
        printf("%d ",fbi(i));
    }
    printf("\n");
}

int main(void)
{
    arr();
    printf_fbi();
    return 0;
}