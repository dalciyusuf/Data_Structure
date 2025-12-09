#include <stdio.h>

/*
    DATA STRUCTURES - WEEK 2 HOMEWORK
    Time Complexity Analysis (Big O Notation) based on Lecture Slides
*/

// ALGO 1: Linear Loop
// Slayt Gorseli: for (i = 1 to n)
// Time Complexity: O(n)
void algo1(int n) {
    printf("\n--- Algo 1 (O(n)) ---\n");
    int i;
    for (i = 1; i <= n; i++) {
        printf("Hello World\n");
    }
}

// ALGO 2: Nested Loop (Ic Ice Dongu)
// Slayt Gorseli: for (i=1 to n) { for (j=1 to n) }
// Time Complexity: O(n^2)
void algo2(int n) {
    printf("\n--- Algo 2 (O(n^2)) ---\n");
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
        
        }
    }
    printf("Islem tamamlandi.\n");
}

// ALGO 3: Logarithmic Loop (Base 2)
// Slayt Gorseli: i = i * 2
// Time Complexity: O(log2 n) -> O(log n)
void algo3(int n) {
    printf("\n--- Algo 3 (O(log n)) ---\n");
    int i;
    for (i = 1; i < n; i = i * 2) {
        printf("Hello World (i: %d)\n", i);
    }
}

// ALGO 4: Logarithmic Loop (Base 5)
// Slayt Gorseli: i = i / 5 (Yazim Hatasi) -> Cevap O(log5 n) oldugu icin *5 yaptim.
// Time Complexity: O(log5 n) -> O(log n)
void algo4(int n) {
    printf("\n--- Algo 4 (O(log5 n)) ---\n");
    int i;
    // NOT: Slaytta i = i / 5 yaziyor ancak i=1 baslangiciyla bolme yapilirsa dongu calismaz.
    // Cevabin Logaritma cikmasi icin carpma islemi uyguladim.
    for (i = 1; i < n; i = i * 5) {
        printf("Hello World (i: %d)\n", i);
    }
}

// ALGO 5: Logarithmic Loop with n^3 Limit
// Time Complexity: O(log5 n^3) -> 3 * O(log n) -> O(log n)
void algo5(int n) {
    printf("\n--- Algo 5 (O(log n^3)) ---\n");
    int i;
    // C dilinde n^3 icin n*n*n kullanilir.
    long long limit = (long long)n * n * n; 
    
    for (i = 1; i < limit; i = i * 5) {
        printf("Hello World\n");
    }
}

// ALGO 6: Square Root Loop
// Slayt Gorseli: i^2 <= n
// Time Complexity: O(sqrt(n))
void algo6(int n) {
    printf("\n--- Algo 6 (O(sqrt(n))) ---\n");
    int i;
    for (i = 1; i * i <= n; i++) {
        printf("Hello World (i: %d)\n", i);
    }
}

// ALGO 7: Cumulative Arithmetic Loop
// Time Complexity: O(sqrt(n))
void algo7(int n) {
    printf("\n--- Algo 7 (O(sqrt(n))) ---\n");
    int i = 1, k = 1;
    while (k <= n) {
        i++;
        k = k + i;
        printf("Hello World (k: %d)\n", k);
    }
}

int main() {
    int n = 100; // Test degeri
    
    algo1(n);
    algo2(n);
    algo3(n);
    algo4(n);
    algo5(10);
    algo6(n);
    algo7(n);

    return 0;
}