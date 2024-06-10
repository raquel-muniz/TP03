#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <locale.h>
#include "cidades.h"  

// T é o tamanho TOTAL da estrada
// N é o número de cidades em que a estrada passa

// Função para inicializar a estrada a partir de um arquivo
Estrada *getEstrada(const char *NomeDoc) {
    FILE *doc = fopen(NomeDoc, "r"); // abre o documento

    if (doc == NULL) { // Caso dê erro..
        return NULL;
    }

    Estrada *estrada = (Estrada *)malloc(sizeof(Estrada)); // alocação da memória - ESTRADA
    if (estrada == NULL) {
        fclose(doc);
        return NULL;
    }

    fscanf(doc, "%d", &estrada->T);
    fscanf(doc, "%d", &estrada->N);

    if (estrada->T < 3 || estrada->T > 1000000 || estrada->N < 2 || estrada->N > 10000) {
        fclose(doc);
        free(estrada);
        return NULL;
    }

    estrada->C = (Cidade *)malloc(estrada->N * sizeof(Cidade)); // alocação da memória - CIDADE
    if (estrada->C == NULL) {
        fclose(doc);
        free(estrada);
        return NULL;
    }

    for (int i = 0; i < estrada->N; i++) {
        fscanf(doc, "%d %s", &estrada->C[i].Posicao, estrada->C[i].Nome);
    }

    fclose(doc);
    return estrada;
}

// Função para calcular a menor vizinhança
double calcularMenorVizinhanca(const char *NomeDoc) {
    Estrada *estrada = getEstrada(NomeDoc);
    if (!estrada) return -1; // Indicação de erro

    double menorVizinhanca = estrada->T; // Inicializando com o comprimento total da estrada
    for (int i = 0; i < estrada->N - 1; i++) {
        double distanciaAtual = estrada->C[i].Posicao;
        double distanciaProxima = estrada->C[i + 1].Posicao;
        double vizinhanca = ((distanciaProxima - distanciaAtual) / 2.0) + distanciaAtual;

        // Debugging outputs
        fprintf(stdout, "Distância Atual: %.2f\n", distanciaAtual);
        fprintf(stdout, "Distância próxima: %.2f\n", distanciaProxima);
        fprintf(stdout, "Vizinhança calculada: %.2f\n", vizinhanca);

        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
        }
    }

    free(estrada->C); // Liberando memória alocada
    free(estrada);
    return menorVizinhanca;
}

// Função para determinar a cidade com a menor vizinhança
char *cidadeMenorVizinhanca(const char *NomeDoc) {
    Estrada *estrada = getEstrada(NomeDoc);
    if (!estrada) return NULL; // Indicação de erro

    double menorVizinhanca = estrada->T; // Inicializando com o comprimento total da estrada
    char *cidadeMenor = estrada->C[0].Nome; // Inicializando com o nome da primeira cidade
    for (int i = 0; i < estrada->N - 1; i++) {
        double distanciaAtual = estrada->C[i].Posicao;
        double distanciaProxima = estrada->C[i + 1].Posicao;
        double vizinhanca = ((distanciaProxima - distanciaAtual) / 2.0) + distanciaAtual;
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
            cidadeMenor = estrada->C[i].Nome; // Atualizando o nome da cidade menor
        }
    }

    // Copiar o nome da cidade para uma nova string para evitar retorno de ponteiro local
    char *cidadeMenorCopy = (char *)malloc(strlen(cidadeMenor) + 1);
    strcpy(cidadeMenorCopy, cidadeMenor);

    free(estrada->C); // Liberando memória alocada
    free(estrada);
    return cidadeMenorCopy;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    // Teste das funções
    printf("Calcule a distância das cidades aqui!! PRA SEMPRE WAKANDA!!\n");

    char nomeArquivo[256];
    printf("Por favor, insira o nome do arquivo de entrada (incluindo a extensão .txt): ");
    scanf("%s", nomeArquivo);

    double menorVizinhanca = calcularMenorVizinhanca(nomeArquivo);
    char *cidadeMenor = cidadeMenorVizinhanca(nomeArquivo);

    if (menorVizinhanca < 0 || cidadeMenor == NULL) {
        printf("Erro ao calcular a menor vizinhança ou cidade.\n");
    } else {
        printf("Menor vizinhança: %.2f\n", menorVizinhanca);
        printf("Cidade com menor vizinhança: %s\n", cidadeMenor);
    }

    free(cidadeMenor); // Liberando memória alocada
    return 0;
}

