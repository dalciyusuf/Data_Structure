//SORULARIN TEORIK CEVAPLARI ASAGI DA KODLAR VAR

/*/ A. Doubly Linked List'te Sona Ekleme (Append) Tek yonluden farki sudur: Yeni eklediğin düğümün prev (önceki) pointer'ını, listenin o anki son elemanına bağlaman gerekir.

Mantik: Yeni->prev = EskiSon; ve EskiSon->next = Yeni;

B. Araya Ekleme (Insertion After) Burada 4 baglanti kurulmali (Normalde 2 idi).

Yeninin next'i -> Oncekinin next'i.

Oncekinin next'i -> Yeni.

Yeninin prev'i -> Onceki.

(Eger varsa) Sonrakinin prev'i -> Yeni.

C. Recursive (ozyinelemeli) Silme Listeyi silerken head'den baslarsan ve hemen silersen next'i kaybedersin. Bu yuzden Recursive mantığı harikadır: "Önce benden sonrakini sil, en son beni sil" (Post-order traversal) mantığıyla çalışır.

D. Circular vs Normal Linked List (Siralama Farki) Siralama algoritmalarinda (ornegin Bubble Sort) en buyuk fark Dongü Bitiş Koşuludur.

Normal: while(node != NULL) deriz, cunku sonu NULL'dur.

Circular: while(node->next != head) deriz, cunku sonu tekrar basa doner. Eger NULL kontrolu yaparsan kod sonsuz döngüye girer ve patlar.*/

#include <stdio.h>
#include <stdlib.h>

// DOUBLY LINKED LIST DUGUM YAPISI
struct Node {
    int data;
    struct Node* next; 
    struct Node* prev; 
};

// 1. SONA EKLEME (APPEND) - DOUBLY LINKED LIST
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL; 

  
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

   
    while (last->next != NULL) {
        last = last->next;
    }

    
    last->next = new_node; 
    new_node->prev = last; 
    
    printf("Sona Eklendi: %d\n", new_data);
}

// 2. ARAYA EKLEME - DOUBLY LINKED LIST
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Hata: Onceki dugum NULL olamaz.\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    // 1. Yeninin next'i, oncekinin next'i olsun
    new_node->next = prev_node->next;

    // 2. Oncekinin next'i yeni olsun
    prev_node->next = new_node;

    // 3. Yeninin prev'i onceki olsun
    new_node->prev = prev_node;

    // 4. Eger yeniden sonra bir dugum varsa, onun prev'i yeni olsun
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
    
    printf("Araya Eklendi: %d (Referans: %d)\n", new_data, prev_node->data);
}

// 3. RECURSIVE (OZYINELEMELI) SILME
// "Sondan basa dogru silme" mantigi (Post-order)
void deleteListRecursive(struct Node* current) {
    if (current == NULL) return; // Base case: Liste bitti

    // Once sonrakini silmesi icin kendini cagir
    deleteListRecursive(current->next);

    // Donuste su anki dugumu sil
    printf("Siliniyor: %d\n", current->data);
    free(current);
}

// Listeyi Yazdirma
void printList(struct Node* node) {
    struct Node* last;
    printf("\nListe (Ileri): ");
    while (node != NULL) {
        printf("%d <-> ", node->data);
        last = node;
        node = node->next;
    }
    printf("NULL\n");
}

// 4. OBSERVATION (GOZLEM): CIRCULAR VS NORMAL LIST SORTING
// Bu fonksiyon sadece farki anlatmak icin yazilmistir.
void comparisonObservation() {
    printf("\n--- SIRALAMA ALGORITMASI FARKI ---\n");
    printf("Normal Linked List'te dongu soyledir:\n");
    printf("   while (temp != NULL) { ... }\n\n");
    
    printf("Circular Linked List'te dongu soyledir:\n");
    printf("   do { ... } while (temp != head);\n");
    
    printf("FARK: Circular listelerde 'NULL' yoktur. Eger siralamada 'NULL' ararsaniz\n");
    printf("program sonsuz donguye girer (Infinite Loop). Bitis kosulu 'Head' olmalidir.\n");
}

int main() {
    struct Node* head = NULL;

    // Sona Ekleme Testleri
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    printList(head);

    // Araya Ekleme Testi (10 ile 20 arasina 15 ekleyelim)
    // head, 10 degerini tutuyor. head'den sonrasina ekle.
    insertAfter(head, 15);

    printList(head);

    // Karsilastirma Gozlemi
    comparisonObservation();

    // Recursive Silme Testi
    printf("\n--- Recursive Silme Basliyor ---\n");
    deleteListRecursive(head);
    head = NULL; // Dangling pointer olmamasi icin head'i NULL yapiyoruz
    printf("Tum liste temizlendi.\n");

    return 0;
}