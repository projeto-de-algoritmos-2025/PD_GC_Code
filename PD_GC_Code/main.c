#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TAM 10000

int main() {
    int m, moedas[100], alvo;
    int dp[TAM], ult[TAM];
    system("cls || clear");

    printf("Quantidade de moedas: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        printf("Moeda %d: ", i + 1);
        scanf("%d", &moedas[i]);
    }

    printf("Valor que deseja pagar: ");
    scanf("%d", &alvo);

    system("cls || clear");
    printf("Valor alvo: %d\n\n", alvo);

    for (int i = 0; i <= alvo; i++) {
        dp[i] = INT_MAX;
        ult[i] = -1;
    }
    dp[0] = 0;

    for (int v = 1; v <= alvo; v++) {
        printf("Valor %d:\n", v);
        for (int i = 0; i < m; i++) {
            int c = moedas[i];
            if (v - c >= 0 && dp[v - c] != INT_MAX) {
                int op = dp[v - c] + 1;
                if (op < dp[v]) {
                    printf(" Testando %d -> dp[%d] = min(%d, dp[%d]+1 = %d) => Atualiza!\n", c, v, dp[v], v - c, op);
                    dp[v] = op;
                    ult[v] = c;
                } else {
                    printf(" Testando %d -> dp[%d] = min(%d, dp[%d]+1 = %d) => Mantem\n", c, v, dp[v], v - c, op);
                }
            }
        }
        if (dp[v] == INT_MAX) printf(" Sem combinacao\n");
        else printf(" dp[%d] = %d\n", v, dp[v]);
        printf("\n");
    }

    printf("Resultado final:\n");
    if (dp[alvo] == INT_MAX) {
        printf("Sem solucao para pagar %d\n", alvo);
        return 0;
    }

    printf("Minimo de moedas: %d\n", dp[alvo]);

    printf("Moedas usadas: ");
    int v = alvo;
    while (v > 0) {
        printf("%d ", ult[v]);
        v -= ult[v];
    }
    printf("\n");

    return 0;
}
