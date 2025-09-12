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
int compararAtributo(struct Carta c1, struct Carta c2, int atributo);
const char* nomeAtributo(int atributo);
void modoMestre(struct Carta c1, struct Carta c2);

int main() {
    struct Carta carta1, carta2;
    int modo, escolha;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado: ");
    fgets(carta1.estado, sizeof(carta1.estado), stdin);
    carta1.estado[strcspn(carta1.estado, "\n")] = '\0';

    printf("Código: ");
    scanf("%d", &carta1.codigo);
    getchar();

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

    // Seleção do modo
    printf("\nSelecione o modo de comparação:\n");
    printf("1 - Comparação Simples (1 atributo)\n");
    printf("2 - Modo Mestre (2 atributos)\n");
    printf("Digite a opção: ");
    scanf("%d", &modo);

    if (modo == 1) {
        // Menu de atributos
        printf("\nEscolha o atributo para comparação:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Populacional (MENOR vence)\n");
        printf("Digite a opção: ");
        scanf("%d", &escolha);

        // Comparações com switch
        switch (escolha) {
            case 1:
                printf("\n>>> Comparando População...\n");
                if (carta1.populacao > carta2.populacao)
                    printf("Vencedora: %s (População: %d)\n", carta1.cidade, carta1.populacao);
                else if (carta2.populacao > carta1.populacao)
                    printf("Vencedora: %s (População: %d)\n", carta2.cidade, carta2.populacao);
                else
                    printf("Empate na população!\n");
                break;

            case 2:
                printf("\n>>> Comparando Área...\n");
                if (carta1.area > carta2.area)
                    printf("Vencedora: %s (Área: %.2f km²)\n", carta1.cidade, carta1.area);
                else if (carta2.area > carta1.area)
                    printf("Vencedora: %s (Área: %.2f km²)\n", carta2.cidade, carta2.area);
                else
                    printf("Empate na área!\n");
                break;

            case 3:
                printf("\n>>> Comparando PIB...\n");
                if (carta1.pib > carta2.pib)
                    printf("Vencedora: %s (PIB: %.2f bilhões)\n", carta1.cidade, carta1.pib);
                else if (carta2.pib > carta1.pib)
                    printf("Vencedora: %s (PIB: %.2f bilhões)\n", carta2.cidade, carta2.pib);
                else
                    printf("Empate no PIB!\n");
                break;

            case 4:
                printf("\n>>> Comparando Pontos Turísticos...\n");
                if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                    printf("Vencedora: %s (%d pontos turísticos)\n", carta1.cidade, carta1.pontosTuristicos);
                else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
                    printf("Vencedora: %s (%d pontos turísticos)\n", carta2.cidade, carta2.pontosTuristicos);
                else
                    printf("Empate em pontos turísticos!\n");
                break;

            case 5: {
                printf("\n>>> Comparando Densidade Populacional...\n");
                float dens1 = calcularDensidade(carta1);
                float dens2 = calcularDensidade(carta2);
                printf("%s: %.2f hab/km²\n", carta1.cidade, dens1);
                printf("%s: %.2f hab/km²\n", carta2.cidade, dens2);

                if (dens1 < dens2)
                    printf("Vencedora: %s (menor densidade)\n", carta1.cidade);
                else if (dens2 < dens1)
                    printf("Vencedora: %s (menor densidade)\n", carta2.cidade);
                else
                    printf("Empate na densidade populacional!\n");
                break;
            }

            default:
                printf("Opção inválida.\n");
        }

    } else if (modo == 2) {
        modoMestre(carta1, carta2);
    } else {
        printf("Modo inválido.\n");
    }

    return 0;
}

// =================== FUNÇÕES AUXILIARES ===================

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
    if (c.area == 0) return 0;
    return c.populacao / c.area;
}

// Função para retornar o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        default: return "Desconhecido";
    }
}

// Função para comparar um atributo específico entre duas cartas
int compararAtributo(struct Carta c1, struct Carta c2, int atributo) {
    switch (atributo) {
        case 1: return (c1.populacao > c2.populacao) ? 1 : (c2.populacao > c1.populacao) ? 2 : 0;
        case 2: return (c1.area > c2.area) ? 1 : (c2.area > c1.area) ? 2 : 0;
        case 3: return (c1.pib > c2.pib) ? 1 : (c2.pib > c1.pib) ? 2 : 0;
        case 4: return (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 : (c2.pontosTuristicos > c1.pontosTuristicos) ? 2 : 0;
        case 5: {
            float d1 = calcularDensidade(c1);
            float d2 = calcularDensidade(c2);
            return (d1 < d2) ? 1 : (d2 < d1) ? 2 : 0; // menor vence
        }
        default: return -1;
    }
}

// Função para o modo mestre: comparação com dois atributos
void modoMestre(struct Carta c1, struct Carta c2) {
    int a1, a2;
    printf("\n=== MODO MESTRE ===\n");
    printf("Escolha o PRIMEIRO atributo:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n");
    scanf("%d", &a1);

    printf("Escolha o SEGUNDO atributo:\n");
    scanf("%d", &a2);

    if (a1 < 1 || a1 > 5 || a2 < 1 || a2 > 5 || a1 == a2) {
        printf("Atributos inválidos ou repetidos.\n");
        return;
    }

    int r1 = compararAtributo(c1, c2, a1);
    int r2 = compararAtributo(c1, c2, a2);

    printf("\n>>> Comparando dois atributos:\n");
    printf("%s: %s\n", nomeAtributo(a1), (r1 == 1) ? c1.cidade : (r1 == 2) ? c2.cidade : "Empate");
    printf("%s: %s\n", nomeAtributo(a2), (r2 == 1) ? c1.cidade : (r2 == 2) ? c2.cidade : "Empate");

    if (r1 == 1 && r2 == 1)
        printf("\n>>> Vencedora: %s (venceu nos dois atributos)\n", c1.cidade);
    else if (r1 == 2 && r2 == 2)
        printf("\n>>> Vencedora: %s (venceu nos dois atributos)\n", c2.cidade);
    else if ((r1 == 1 && r2 == 2) || (r1 == 2 && r2 == 1))
        printf("\n>>> Empate! Cada cidade venceu um atributo.\n");
    else if (r1 == 0 && r2 == 0)
        printf("\n>>> Empate total nos dois atributos!\n");
    else
        printf("\n>>> Sem vencedor claro (um atributo empatado, outro com vitória).\n");
}
