#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef unsigned short bool;

void prime(int n) {
    if(n < 0 || n == 0 || n == 1) {
        printf("is a not prime number\n");
    }
    else {
        bool f = TRUE;
        for (size_t i = 2; i <= n/2; i++) {
            if (n%i == 0) {
                f = FALSE;
                break;
            }
        }
        if(f == TRUE) printf("is a prime number \n");
        else printf("is a not prime number\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    prime(n);

    return 0;
}