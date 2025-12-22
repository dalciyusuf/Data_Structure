#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    int item = queue[front];
    front++;
    return item;
}

int isQueueEmpty() {
    if (front == -1 || front > rear)
        return 1;
    return 0;
}

void resetVisited() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

void BFS(int startVertex) {
    int i;
    
    resetVisited();
    
    enqueue(startVertex);
    visited[startVertex] = 1;

    printf("BFS Dolasimi: ");

    while (!isQueueEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (i = 0; i < n; i++) {
            if (adj[currentVertex][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFS_Recursive(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && visited[i] == 0) {
            DFS_Recursive(i);
        }
    }
}

void DFS(int startVertex) {
    resetVisited();
    printf("DFS Dolasimi: ");
    DFS_Recursive(startVertex);
    printf("\n");
}

int main() {
    int edges, u, v, startNode;

    printf("Dugum sayisini giriniz: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Kenar sayisini giriniz: ");
    scanf("%d", &edges);

    printf("Kenarlari giriniz (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        if (u < n && v < n) {
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    }

    printf("Baslangic dugumu: ");
    scanf("%d", &startNode);

    BFS(startNode);
    DFS(startNode);

    return 0;
}