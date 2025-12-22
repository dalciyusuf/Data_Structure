#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

void initGraph(int adj[MAX_VERTICES][MAX_VERTICES], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
}

void addEdge(int adj[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    if (u >= MAX_VERTICES || v >= MAX_VERTICES) return;
    adj[u][v] = 1;
    adj[v][u] = 1; 
}

void DFS(int adj[MAX_VERTICES][MAX_VERTICES], int n, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(adj, n, i, visited);
        }
    }
}

void findClusters(int adj[MAX_VERTICES][MAX_VERTICES], int n) {
    int visited[MAX_VERTICES];
    for (int i = 0; i < n; i++) visited[i] = 0;

    int clusterCount = 0;
    
    printf("\n--- BULUNAN KUMELER (CLUSTERS) ---\n");

    for (int v = 0; v < n; v++) {
        if (visited[v] == 0) {
            clusterCount++;
            printf("Cluster %d: { ", clusterCount);
            DFS(adj, n, v, visited);
            printf("}\n");
        }
    }
    
    printf("----------------------------------\n");
    printf("Toplam Cluster Sayisi: %d\n", clusterCount);
}

void printMatrix(int adj[MAX_VERTICES][MAX_VERTICES], int n) {
    printf("\n--- Komsuluk Matrisi ---\n");
    printf("   ");
    for (int i = 0; i < n; i++) printf("%d ", i);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adj[MAX_VERTICES][MAX_VERTICES];
    int n, edgeCount, u, v;

    printf("--- GRAPH CLUSTER BULMA PROGRAMI ---\n");
    
    do {
        printf("Dugum sayisini giriniz (Max %d): ", MAX_VERTICES);
        scanf("%d", &n);
    } while (n <= 0 || n > MAX_VERTICES);

    initGraph(adj, n);

    printf("Kac adet kenar (baglanti) ekleyeceksiniz? ");
    scanf("%d", &edgeCount);

    printf("Kenarlari giriniz (Ornek: 0 1 seklinde):\n");
    for (int i = 0; i < edgeCount; i++) {
        printf("%d. Kenar: ", i + 1);
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Hatali dugum! Tekrar giriniz.\n");
            i--;
        } else {
            addEdge(adj, u, v);
        }
    }

    printMatrix(adj, n);
    findClusters(adj, n);

    return 0;
}