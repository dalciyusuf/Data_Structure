#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Graph Yapisini Tanimlayalim (Adjacency Matrix kullanacagiz)
struct Graph {
    int numVertices;
    int adjMatrix[MAX_NODES][MAX_NODES];
    bool visited[MAX_NODES]; // Dugumun ziyaret edilip edilmedigi
};

// Graph Olusturma
void initGraph(struct Graph* g, int vertices) {
    g->numVertices = vertices;
    int i, j;
    for (i = 0; i < vertices; i++) {
        g->visited[i] = false;
        for (j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Kenar Ekleme (Edge)
void addEdge(struct Graph* g, int src, int dest) {
    // Undirected Graph (Yonsuz) oldugu icin iki tarafa da 1 yapiyoruz
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

// DFS Algoritmasi (Derinlemesine Arama)
// Bu fonksiyon bir dugumden baslayip gidebildigi yere kadar gider (Ayni Cluster icini gezer)
void DFS(struct Graph* g, int vertex) {
    g->visited[vertex] = true;
    printf("%d ", vertex); // Cluster elemanini yazdir

    int i;
    for (i = 0; i < g->numVertices; i++) {
        // Eger komsuysa (1) ve daha once gezilmemisse oraya git
        if (g->adjMatrix[vertex][i] == 1 && !g->visited[i]) {
            DFS(g, i);
        }
    }
}

// Kumeleme (Clustering) Islemi
// Ziyaret edilmemis her dugum, yeni bir cluster'in baslangicidir.
void findClusters(struct Graph* g) {
    int clusterCount = 1;
    int i;

    printf("\n--- GRAPH CLUSTERS (KUMELER) ---\n");

    for (i = 0; i < g->numVertices; i++) {
        if (!g->visited[i]) {
            // Eger bu dugume daha once gelinmediyse, yeni bir ada (cluster) bulundu demektir.
            printf("Cluster %d: { ", clusterCount);
            DFS(g, i); // Bu kumenin tum elemanlarini bul ve yazdir
            printf("}\n");
            clusterCount++;
        }
    }
}

int main() {
    struct Graph g;
    // 9 Dugumlu bir grafik olusturalim (0'dan 8'e)
    initGraph(&g, 9);

    /* Senaryo: 3 tane ayri kume olusturalim.
       Kume 1: 0-1-2 (Ucgen seklinde)
       Kume 2: 3-4-5-6 (Kare seklinde)
       Kume 3: 7-8 (Cizgi seklinde)
    */

    // CLUSTER 1 BAGLANTILARI
    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 0);

    // CLUSTER 2 BAGLANTILARI (Cluster 1 ile baglantisi yok!)
    addEdge(&g, 3, 4);
    addEdge(&g, 4, 5);
    addEdge(&g, 5, 6);
    addEdge(&g, 6, 3);

    // CLUSTER 3 BAGLANTILARI
    addEdge(&g, 7, 8);

    // Kumeleme islemini baslat
    findClusters(&g);

    return 0;
}

// GRAPH CLUSTERİNG MANTİGİ

/* 1. Mantık: Kümeler Nasıl Ayrılır? (How Separate?)
Bir grafiği kümelere ayırmak için genellikle "Zayıf Halkayı Koparma" yöntemi kullanılır.

Yoğunluk (Density): Bir küme içindeki elemanlar birbirine sıkı sıkıya bağlıdır.

Ayrım (Separation): İki farklı küme arasında genellikle tek bir köprü (bridge) veya çok az bağlantı vardır.

Algoritma (Girvan-Newman Mantığı):

Grafikteki tüm yolları analiz et.

En çok kullanılan "köprü" kenarı (edge) bul (buna Edge Betweenness denir).

Bu kenarı sil.

Grafik iki parçaya ayrıldı mı? Evet ise, elinde 2 cluster var demektir. */ 