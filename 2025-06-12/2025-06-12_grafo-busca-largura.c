#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura para representar o grafo com matriz de adjac�ncias
struct Graph {
    int numVertices;
    bool** adjMatrix;
};

// Fun��o para criar um grafo com 'numVertices' v�rtices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjMatrix = (bool**)malloc(numVertices * sizeof(bool*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (bool*)malloc(numVertices * sizeof(bool));
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = false;
        }
    }

    return graph;
}

// Fun��o para adicionar uma aresta ao grafo
void addEdge(struct Graph* graph, int src, int dest) {
    // Adiciona uma aresta do src ao dest
    graph->adjMatrix[src][dest] = true;
}

// Fun��o para realizar a busca em largura
void BFS(struct Graph* graph, int startVertex) {
    // Cria uma fila para a busca em largura
    int queue[graph->numVertices];
    int front = 0, rear = 0;
    queue[rear++] = startVertex;

    // Marca o v�rtice de in�cio como visitado
    bool visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }
    visited[startVertex] = true;

    printf("Resultado da Busca em Largura (BFS):\n");

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }

    printf("\n");
}

// Fun��o para imprimir o grafo
void printGraph(struct Graph* graph) {
    printf("Matriz de Adjac�ncias:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices;

    printf("Digite o n�mero de v�rtices do grafo: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    int choice, src, dest;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar aresta\n");
        printf("2. Realizar Busca em Largura (BFS)\n");
        printf("3. Imprimir grafo\n");
        printf("4. Sair\n");
        printf("Digite a op��o: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o v�rtice de origem: ");
                scanf("%d", &src);
                printf("Digite o v�rtice de destino: ");
                scanf("%d", &dest);
                addEdge(graph, src, dest);
                break;
            case 2:
                printf("Digite o v�rtice de in�cio da Busca em Largura (BFS): ");
                scanf("%d", &src);
                printf("Resultado da Busca em Largura (BFS) a partir do v�rtice %d:\n", src);
                BFS(graph, src);
                break;
            case 3:
                printGraph(graph);
                break;
            case 4:
                exit(0);
            default:
                printf("Op��o inv�lida.\n");
        }
    }

    return 0;
}

