#include "grafo.h"

int main() {
    // Criando um grafo com 5 pessoas (A, B, C, D, E)
    Grafo* grafoAmizades = createGrafo(5);

    // Adicionando amizades entre pessoas
    addAresta(grafoAmizades, 'A', 'B');
    addAresta(grafoAmizades, 'A', 'C');
    addAresta(grafoAmizades, 'B', 'D');
    addAresta(grafoAmizades, 'C', 'D');
    addAresta(grafoAmizades, 'D', 'E');

    // Imprimindo o grafo de amizades
    printGrafo(grafoAmizades);

    // Liberando a memória alocada para o grafo
    freeGrafo(grafoAmizades);

    return 0;
}
