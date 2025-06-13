#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

// Estrutura para representar um grafo
struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int isDirected;
};

// Fun��o para criar um grafo com 'numVertices' v�rtices
struct Graph* createGraph(int numVertices, int isDirected) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->isDirected = isDirected;

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Fun��o para adicionar uma aresta ao grafo
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;

    if (!graph->isDirected) {
        graph->adjMatrix[dest][src] = 1;
    }
}

// Fun��o para remover uma aresta do grafo
void removeEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 0;

    if (!graph->isDirected) {
        graph->adjMatrix[dest][src] = 0;
    }
}

// Fun��o de busca em profundidade (DFS)
void DFS(struct Graph* graph, int startVertex, int targetVertex, bool* visited, int* path, int* pathIndex) {
    visited[startVertex] = true;
    path[(*pathIndex)++] = startVertex;

    if (startVertex == targetVertex) {
        printf("Caminho encontrado: ");
        for (int i = 0; i < *pathIndex; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[startVertex][i] == 1 && !visited[i]) {
            DFS(graph, i, targetVertex, visited, path, pathIndex);
        }
    }

    (*pathIndex)--;
    visited[startVertex] = false;
}

// Fun��o para realizar a busca em profundidade
void performDFS(struct Graph* graph, int startVertex, int targetVertex) {
    if (startVertex < 0 || startVertex >= graph->numVertices || targetVertex < 0 || targetVertex >= graph->numVertices) {
        printf("V�rtices inv�lidos.\n");
        return;
    }

    bool visited[MAX_VERTICES];
    int path[MAX_VERTICES];
    int pathIndex = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    printf("Iniciando busca em profundidade de %d para %d:\n", startVertex, targetVertex);
    DFS(graph, startVertex, targetVertex, visited, path, &pathIndex);
    if (pathIndex == 0) {
        printf("Nenhum caminho encontrado.\n");
    }
}

// Fun��o para imprimir o grafo
void printGraph(struct Graph* graph) {
    printf("Matriz de Adjac�ncia:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices, isDirected;
    printf("Escolha o tipo de grafo:\n");
    printf("1. Grafo n�o dirigido\n");
    printf("2. Grafo dirigido\n");
    printf("Digite a op��o (1 ou 2): ");
    scanf("%d", &isDirected);

    printf("Digite o n�mero de v�rtices do grafo: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices, isDirected);

    int choice, src, dest, startVertex, targetVertex;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar conex�o\n");
        printf("2. Remover conex�o\n");
        printf("3. Realizar busca em profundidade\n");
        printf("4. Imprimir grafo\n");
        printf("5. Sair\n");
        printf("Digite a op��o: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o v�rtice de origem: ");
                scanf("%d", &src);
                printf("Digite o v�rtice de destino: ");
                scanf("%d", &dest);
                addEdge(graph, src, dest);
                printf("Conex�o adicionada.\n");
                break;
            case 2:
                printf("Digite o v�rtice de origem: ");
                scanf("%d", &src);
                printf("Digite o v�rtice de destino: ");
                scanf("%d", &dest);
                removeEdge(graph, src, dest);
                printf("Conex�o removida.\n");
                break;
            case 3:
                printf("Digite o v�rtice de in�cio da busca: ");
                scanf("%d", &startVertex);
                printf("Digite o v�rtice de destino da busca: ");
                scanf("%d", &targetVertex);
                performDFS(graph, startVertex, targetVertex);
                break;
            case 4:
                printGraph(graph);
                break;
            case 5:
                free(graph);
                exit(0);
            default:
                printf("Op��o inv�lida.\n");
        }
    }

    return 0;
}

