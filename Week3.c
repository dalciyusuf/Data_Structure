#include <stdio.h>
#include <stdlib.h>

// BAGLI LISTE DUGUM YAPISI (NODE STRUCT)
struct Node {
    int data;           // Veri
    struct Node* next;  // Bir sonraki dugumu gosteren isaretci (pointer)
};

// 1. TRAVERSAL (DOLASMA) ISLEMI

void printList(struct Node* n) {
    printf("Bagli Liste: ");
    while (n != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("NULL\n");
}

// 2. INSERTION AT BEGINNING (BASA EKLEME)
   

void push(struct Node** head_ref, int new_data) {
    // 1. Dugum icin hafiza ayir
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // 2. Veriyi ata
    new_node->data = new_data;
    
    // 3. Yeni dugumun next'ini eski head yap
    new_node->next = (*head_ref);
    
    // 4. Head pointer'ini yeni dugum yap
    (*head_ref) = new_node;
    
    printf("%d listenin BASINA eklendi.\n", new_data);
}

// 3. INSERTION AT END (SONA EKLEME)

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; // Gecici pointer
    
    new_node->data = new_data;
    new_node->next = NULL; // Son eleman NULL gostermeli

    // Liste bossa direkt head yap
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Son elemani bulana kadar git
    while (last->next != NULL) {
        last = last->next;
    }

    // Son elemanin next'ini yeni dugum yap
    last->next = new_node;
    printf("%d listenin SONUNA eklendi.\n", new_data);
}

// 4. INSERTION AFTER A NODE (ARAYA EKLEME)

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Hata: Onceki dugum NULL olamaz.\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    // Yeni dugumun next'i, onceki dugumun next'i olur
    new_node->next = prev_node->next;

    // Onceki dugum artik yeniyi gosterir
    prev_node->next = new_node;
    
    printf("%d, %d degerinden SONRAYA eklendi.\n", new_data, prev_node->data);
}

/* 5. DELETION (SILME ISLEMI)
   Verilen key (deger) listeden silinir.
   Time Complexity: O(n) - Silinecek elemani bulmak icin gezmek gerekir.
*/
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev;

    // 1. Durum: Silinecek eleman HEAD ise
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Head'i bir yana kaydir
        free(temp); // Hafizayi temizle
        printf("%d silindi (Bas eleman).\n", key);
        return;
    }

    // 2. Durum: Elemani bulana kadar gez, bir yandan 'prev' tut
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Eleman bulunamadiysa
    if (temp == NULL) return;

    // Dugumu listeden cikar
    prev->next = temp->next;
    
    free(temp); // Hafizayi temizle
    printf("%d silindi.\n", key);
}

int main() {
    struct Node* head = NULL; // Bos liste olusturuldu

    // Test Senaryosu
    printf("--- LINKED LIST ISLEMLERI ---\n");

    append(&head, 10); // Sona ekle: 10
    push(&head, 5);    // Basa ekle: 5 -> 10
    push(&head, 2);    // Basa ekle: 2 -> 5 -> 10
    append(&head, 20); // Sona ekle: 2 -> 5 -> 10 -> 20

    
    insertAfter(head->next, 7); 

    printList(head); 

    printf("\n--- SILME ISLEMLERI ---\n");
    deleteNode(&head, 2);  
    deleteNode(&head, 7); 
    
    printList(head); 

    return 0;
}