#include <stdio.h>
#include <limits.h> // Para INT_MAX

int main() {
    const int n = 15;
    int Vec[n];
    unsigned long long Fact[n];

    for(int i = 0; i < n; i++) {
        Vec[i] = i + 1;
    }

    for(int i = 0; i < n; i++) {
        Fact[i] = 1;

        for(int j = 1; j <= Vec[i]; j++) {
            Fact[i] *= j;
        }
    }

    printf("Número | Factorial\n");
    printf("------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%6d | %20llu\n", Vec[i], Fact[i]);
    }

    return 0;
}
