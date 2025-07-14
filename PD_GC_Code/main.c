#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, moedas[100], alvo;
    system("cls || clear");

    printf("Quantidade de moedas: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        printf("Moeda %d: ", i + 1);
        scanf("%d", &moedas[i]);
    }

    printf("Valor que deseja pagar: ");
    scanf("%d", &alvo);

    printf("\n\n");

    return 0;
}
