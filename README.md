Estrada de Wakanda

  Para melhorar a integração com os países vizinhos, o Rei T'Challa de Wakanda decidiu que uma nova estrada
será construída cruzando o país, da fronteira oeste à fronteira leste. O formato da estrada é uma única reta,
que passará pelo centro de algumas cidades.
  O Rei T'Challa também decidiu que a construção será paga pelo Tesouro Real, mas cada cidade pela qual a
estrada passar será responsável pela manutenção do trecho da estrada que constitui a vizinhança da
estrada para aquela cidade.

Atenção:

  A vizinhança da estrada de uma cidade A é definida como todos os pontos da estrada que são mais próximos
do centro da cidade A do que do centro de qualquer outra cidade.
  Dados o comprimento total da estrada, de fronteira a fronteira, e as distâncias da fronteira oeste até os
centros de cada cidade ao longo da nova estrada, escreva um conjunto de funções para determinar qual a
menor vizinhança de estrada entre as cidades pelas quais a estrada vai passar, qual a cidade que tem a menor
vizinhança e para inserir dados lidos em uma lista encadeada.

Entrada

A primeira linha da entrada (nome do arquivo texto passado como parâmetro) contém um inteiro T, o
comprimento total da estrada. A segunda linha contém um inteiro N, o número de cidades pelas quais a
estrada vai passar. Cada uma das N linhas seguintes contém um inteiro Xi e uma string Si, indicando a
distância da fronteira oeste até o centro da cidade i e o nome da cidade i. Não há cidades nas fronteiras e
cada centro de cidade tem uma localização distinta.

Saída

A parte do programa que você deve implementar consiste de arquivo cidades.c contendo a implementação
das funções cujos protótipos estão definidos em cidades.h, quais sejam:

Estrada *getEstrada(const char *nomeArquivo); // Inicializa cidades no TAD Cidade.
double calcularMenorVizinhanca(const char *nomeArquivo); // Retorna a menor vizinhança.
char *cidadeMenorVizinhanca(const char *nomeArquivo); // Retorna a cidade que tem menor vizinhança.

***Restrições******************
 3 ≤ T ≤ 106 e 2 ≤ N ≤ 104
 0 < Xi < T, para 1 ≤ i ≤ N
 Xi ≠ Xj, para todo par 1 ≤ i, j ≤ N.

Atenção:

  As restrições devem ser verificadas no códifo-fonte e devem implicar no retorno de ponteiro nulo para a
função getEstrada.

Exemplo

  A seguir é apresentado um exemplo de arquivo de entrada, cujos dados permitem inferir que 3.50 é a menor
vizinhança dentre as cidades indicadas e está associada à cidade Birnin Zana.

Entrada (arquivo teste01.txt)
10
2
8 Birnin Zana
5 Birnin S'Yan

  É recomendável que sejam elaborados outros exemplos para, efetivamente, confirmar a correção das
funções implementadas.

Arquivo cidades.h

  Necessariamente, o arquivo cidades.h deve ter o seguinte conteúdo e não pode ser modificado.
  
#ifndef CIDADES_H
#define CIDADES_H

typedef struct {
char Nome[256]; // Nome do cidade
int Posicao; // Posição da cidade
} Cidade;

typedef struct {
int N; // Número de cidades
int T; // Comprimento da estrada
Cidade *C; // Vetor de cidades
} Estrada;

Estrada *getEstrada(const char *nomeArquivo); // Inicializa cidades no TAD indicado acima.
double calcularMenorVizinhanca(const char *nomeArquivo); // Retorna a menor vizinhança.
char *cidadeMenorVizinhanca(const char *nomeArquivo); // Retorna a cidade que tem menor vizinhança.
#endif

