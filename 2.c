#include <stdio.h>

void hanoi(int n, char kaynak, char hedef, char yardimci) {
    
   
    if (n == 1) {
        printf("Disk 1 tasindi: %c -> %c\n", kaynak, hedef);
        return;
    }

    hanoi(n - 1, kaynak, yardimci, hedef);

    
    printf("Disk %d tasindi: %c -> %c\n", n, kaynak, hedef);


    hanoi(n - 1, yardimci, hedef, kaynak);
}

int main() {
    int diskSayisi;

    printf("--- Hanoi Kuleleri Cozumu ---\n");
    printf("Disk sayisini giriniz: ");
    scanf("%d", &diskSayisi);
    

    printf("\n%d disk icin cozum adimlari:\n", diskSayisi);
    printf("------------------------------\n");

    hanoi(diskSayisi, 'A', 'C', 'B');

    return 0;
}