#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TAM 10000

int main() {
    int m, moedas[100], alvo;
    int dp[TAM];
    system("cls || clear");

    printf("Quantidade de moedas: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        printf("Moeda %d: ", i + 1);
        scanf("%d", &moedas[i]);
    }

    printf("Valor que deseja pagar: ");
    scanf("%d", &alvo);

    for (int i = 0; i <= alvo; i++) dp[i] = INT_MAX;
    dp[0] = 0;

    for (int v = 1; v <= alvo; v++) {
        for (int i = 0; i < m; i++) {
            int c = moedas[i];
            if (v - c >= 0 && dp[v - c] != INT_MAX) {

            }
        }
    }

    printf("\n\n");

    return 0;
}
