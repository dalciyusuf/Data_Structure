#include <stdio.h>

#define CAPACITY 100 

// 1.
void printArray(int arr[], int n) {
    int i; 
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 2.INSERTION
void insertElement(int arr[], int *n, int element, int position) {
    if (*n >= CAPACITY) {
        printf("Hata: Dizi dolu!\n");
        return;
    }
    if (position < 0 || position > *n) {
        printf("Hata: Gecersiz konum!\n");
        return;
    }

    // Sondan baslayarak saga kaydirma
    int i;
    for (i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*n)++; 
    printf("%d degeri %d. indekse eklendi.\n", element, position);
}

// 3.DELETION
void deleteElement(int arr[], int *n, int position) {
    if (*n <= 0) {
        printf("Hata: Dizi bos!\n");
        return;
    }
    if (position < 0 || position >= *n) {
        printf("Hata: Gecersiz konum!\n");
        return;
    }

    int deletedVal = arr[position];

    // Silinen yerden itibaren sola kaydirma
    int i;
    for (i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--; 
    printf("%d degeri silindi.\n", deletedVal);
}

// 4.REVERSE
void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    int temp;

    while (start < end) {
    
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
    printf("Dizi tersine cevrildi.\n");
}

int main() {
   
    int arr[CAPACITY] = {10, 20, 30, 40, 50}; 
    int n = 5; 

    printf("Baslangic Dizisi: ");
    printArray(arr, n);
    printf("-----------------------\n");

   
    insertElement(arr, &n, 99, 2);
    printArray(arr, n);

    deleteElement(arr, &n, 0);
    printArray(arr, n);

    // Tersine Çevirme Testi
    reverseArray(arr, n);
    printArray(arr, n);

    return 0;
}