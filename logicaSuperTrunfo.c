#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    long populacao;
    float area;
    float pib;
    float densidade_populacional;
    float pib_por_capita;
} Cidade;

void lerCidade(Cidade *c, int numero) {
    printf("Digite o estado da cidade %d:\n", numero);
    scanf("%s", c->estado);

    printf("Digite a populacao da cidade %d:\n", numero);
    scanf("%lu", &c->populacao);

    printf("Digite a area da cidade %d:\n", numero);
    scanf("%f", &c->area);

    printf("Digite o PIB da cidade %d (em bilhões):\n", numero);
    scanf("%f", &c->pib);

    c->densidade_populacional = c->populacao / c->area;
    c->pib_por_capita = (c->pib * 1e9) / c->populacao;

}
void compararCidades(Cidade c1, Cidade c2, int opcao) {
    printf("\n--- Comparação ---\n");

    if (opcao == 1) { // População
        printf("%s: %lu habitantes\n", c1.estado, c1.populacao);
        printf("%s: %lu habitantes\n", c2.estado, c2.populacao);

        if (c1.populacao > c2.populacao)
            printf("%s tem maior população.\n", c1.estado);
        else if (c1.populacao < c2.populacao)
            printf("%s tem maior população.\n", c2.estado);
        else
            printf("As duas cidades têm a mesma população.\n");
    }

    else if (opcao == 2) { // Área
        printf("%s: %.2f km²\n", c1.estado, c1.area);
        printf("%s: %.2f km²\n", c2.estado, c2.area);

        if (c1.area > c2.area)
            printf("%s tem maior área.\n", c1.estado);
        else if (c1.area < c2.area)
            printf("%s tem maior área.\n", c2.estado);
        else
            printf("As duas cidades têm a mesma área.\n");
    }

    else if (opcao == 3) { // PIB
        printf("%s: R$ %.2f bilhões\n", c1.estado, c1.pib);
        printf("%s: R$ %.2f bilhões\n", c2.estado, c2.pib);

        if (c1.pib > c2.pib)
            printf("%s tem maior PIB.\n", c1.estado);
        else if (c1.pib < c2.pib)
            printf("%s tem maior PIB.\n", c2.estado);
        else
            printf("As duas cidades têm o mesmo PIB.\n");
    }

    else if (opcao == 4) { // Densidade Populacional
        printf("%s: %.2f hab/km²\n", c1.estado, c1.densidade_populacional);
        printf("%s: %.2f hab/km²\n", c2.estado, c2.densidade_populacional);

        if (c1.densidade_populacional > c2.densidade_populacional)
            printf("%s tem maior densidade populacional.\n", c1.estado);
        else if (c1.densidade_populacional < c2.densidade_populacional)
            printf("%s tem maior densidade populacional.\n", c2.estado);
        else
            printf("As duas cidades têm a mesma densidade populacional.\n");
    }

    else if (opcao == 5) { // PIB per capita
        printf("%s: R$ %.2f por pessoa\n", c1.estado, c1.pib_por_capita);
        printf("%s: R$ %.2f por pessoa\n", c2.estado, c2.pib_por_capita);

        if (c1.pib_por_capita > c2.pib_por_capita)
            printf("%s tem maior PIB per capita.\n", c1.estado);
        else if (c1.pib_por_capita < c2.pib_por_capita)
            printf("%s tem maior PIB per capita.\n", c2.estado);
        else
            printf("As duas cidades têm o mesmo PIB per capita.\n");
    }

    else {
        printf("Opção inválida.\n");
    }

    printf("-------------------\n");
}

int main(void) {
    Cidade cidade1, cidade2;
    int opcao;

    lerCidade(&cidade1, 1);
    printf("\n");
    lerCidade(&cidade2, 2);

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per capita\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);

    compararCidades(cidade1, cidade2, opcao);

    return 0;
}
