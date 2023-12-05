#include "grafo.h"

PessoaNode* createPessoaNode(char pessoa) {
    PessoaNode* newNode = (PessoaNode*)malloc(sizeof(PessoaNode));
    newNode->pessoa = pessoa;
    newNode->next = NULL;
    return newNode;
}

Grafo* createGrafo(int numVertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;
    grafo->vertices = (PessoaNode**)malloc(numVertices * sizeof(PessoaNode*));
    
    for (int i = 0; i < numVertices; ++i) {
        grafo->vertices[i] = NULL;
    }

    return grafo;
}

void addAresta(Grafo* grafo, char pessoa1, char pessoa2) {
    int index1 = pessoa1 - 'A';
    int index2 = pessoa2 - 'A';

    PessoaNode* newNode1 = createPessoaNode(pessoa2);
    newNode1->next = grafo->vertices[index1];
    grafo->vertices[index1] = newNode1;

    PessoaNode* newNode2 = createPessoaNode(pessoa1);
    newNode2->next = grafo->vertices[index2];
    grafo->vertices[index2] = newNode2;
}

void printGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; ++i) {
        printf("Amigos de %c: ", 'A' + i);

        PessoaNode* current = grafo->vertices[i];
        while (current != NULL) {
            printf("%c ", current->pessoa);
            current = current->next;
        }

        printf("\n");
    }
}

void freeGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; ++i) {
        PessoaNode* current = grafo->vertices[i];
        while (current != NULL) {
            PessoaNode* next = current->next;
            free(current);
            current = next;
        }
    }

    free(grafo->vertices);
    free(grafo);
}
