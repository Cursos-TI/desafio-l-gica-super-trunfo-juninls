#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char estado[30];
    int codigo;
    char cidade[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Protótipos das funções
void exibirCarta(struct Carta c);
float calcularDensidade(struct Carta c);

int main() {
    struct Carta carta1, carta2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado: ");
    fgets(carta1.estado, sizeof(carta1.estado), stdin);
    carta1.estado[strcspn(carta1.estado, "\n")] = '\0'; // remove \n

    printf("Código: ");
    scanf("%d", &carta1.codigo);
    getchar(); // limpa o buffer

    printf("Cidade: ");
    fgets(carta1.cidade, sizeof(carta1.cidade), stdin);
    carta1.cidade[strcspn(carta1.cidade, "\n")] = '\0';

    printf("População: ");
    scanf("%d", &carta1.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    getchar();

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Estado: ");
    fgets(carta2.estado, sizeof(carta2.estado), stdin);
    carta2.estado[strcspn(carta2.estado, "\n")] = '\0';

    printf("Código: ");
    scanf("%d", &carta2.codigo);
    getchar();

    printf("Cidade: ");
    fgets(carta2.cidade, sizeof(carta2.cidade), stdin);
    carta2.cidade[strcspn(carta2.cidade, "\n")] = '\0';

    printf("População: ");
    scanf("%d", &carta2.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    getchar();

    // Exibe as cartas
    printf("\n===== CARTA 1 =====");
    exibirCarta(carta1);

    printf("\n===== CARTA 2 =====");
    exibirCarta(carta2);

    // Comparação de atributo (exemplo: população)
    printf("\n>>> Comparando atributo: POPULAÇÃO\n");

    if (carta1.populacao > carta2.populacao) {
        printf("Vencedora: %s (População: %d)\n", carta1.cidade, carta1.populacao);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Vencedora: %s (População: %d)\n", carta2.cidade, carta2.populacao);
    } else {
        printf("Empate: ambas as cidades têm a mesma população.\n");
    }

    return 0;
}

// Função para exibir os dados de uma carta
void exibirCarta(struct Carta c) {
    printf("\nCódigo: %d", c.codigo);
    printf("\nCidade: %s", c.cidade);
    printf("\nEstado: %s", c.estado);
    printf("\nPopulação: %d", c.populacao);
    printf("\nÁrea: %.2f km²", c.area);
    printf("\nPIB: %.2f bilhões", c.pib);
    printf("\nPontos Turísticos: %d\n", c.pontosTuristicos);
}

// Função para calcular densidade populacional
float calcularDensidade(struct Carta c) {
    if (c.area == 0) return 0; // evitar divisão por zero
    return c.populacao / c.area;
}
