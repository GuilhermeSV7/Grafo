#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó (pessoa)
typedef struct PessoaNode {
    char pessoa;
    struct PessoaNode* next;
} PessoaNode;

// Estrutura para representar um grafo
typedef struct Grafo {
    PessoaNode** vertices;
    int numVertices;
} Grafo;

// Função para criar um novo nó (pessoa)
PessoaNode* createPessoaNode(char pessoa);

// Função para criar um grafo com um número específico de vértices
Grafo* createGrafo(int numVertices);

// Função para adicionar uma aresta (amizade) entre pessoas
void addAresta(Grafo* grafo, char pessoa1, char pessoa2);

// Função para imprimir o grafo
void printGrafo(Grafo* grafo);

// Função para liberar a memória alocada para o grafo
void freeGrafo(Grafo* grafo);

#endif
