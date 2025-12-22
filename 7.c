#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

void printArray(int arr[], int size) {
    if (size == 0) {
        printf("Dizi su an bos.\n");
        return;
    }
    printf("Dizi Elemanlari: [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void insertElement(int arr[], int *size, int pos, int val) {
    if (*size >= CAPACITY) {
        printf("Hata: Dizi kapasitesi dolu!\n");
        return;
    }
    if (pos < 0 || pos > *size) {
        printf("Hata: Gecersiz pozisyon! (0 - %d arasi olmali)\n", *size);
        return;
    }

    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = val;
    (*size)++;
    printf("%d degeri %d. indekse eklendi.\n", val, pos);
}

void deleteElement(int arr[], int *size, int pos) {
    if (*size <= 0) {
        printf("Hata: Dizi zaten bos!\n");
        return;
    }
    if (pos < 0 || pos >= *size) {
        printf("Hata: Gecersiz pozisyon! (0 - %d arasi olmali)\n", *size - 1);
        return;
    }

    int deletedVal = arr[pos];

    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("%d degeri %d. indeksden silindi.\n", deletedVal, pos);
}

int searchElement(int arr[], int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[CAPACITY];
    int size = 0;
    int choice, val, pos, index;

    while (1) {
        printf("\n--- ARRAY ISLEMLERI ---\n");
        printf("1. Ekleme Yap (Insertion)\n");
        printf("2. Silme Yap (Deletion)\n");
        printf("3. Arama Yap (Search)\n");
        printf("4. Listele\n");
        printf("5. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Eklenecek deger: ");
                scanf("%d", &val);
                printf("Hangi indekse eklensin (0-%d): ", size);
                scanf("%d", &pos);
                insertElement(arr, &size, pos, val);
                break;
            case 2:
                printArray(arr, size);
                printf("Silinecek indeks: ");
                scanf("%d", &pos);
                deleteElement(arr, &size, pos);
                break;
            case 3:
                printf("Aranacak deger: ");
                scanf("%d", &val);
                index = searchElement(arr, size, val);
                if (index != -1)
                    printf("Deger bulundu! Indeks: %d\n", index);
                else
                    printf("Deger bulunamadi.\n");
                break;
            case 4:
                printArray(arr, size);
                break;
            case 5:
                printf("Programdan cikiliyor.\n");
                return 0;
            default:
                printf("Gecersiz secim!\n");
        }
    }
    return 0;
}