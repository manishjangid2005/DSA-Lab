#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    printf("Factorial of %d is %d", n, fact);
    return 0;
}
