/* Shunting Yard Algoritmasi:
Edsger Dijkstra tarafından icat edilen ve matematiksel ifadeleri (Infix: 3 + 4) 
bilgisayarın daha rahat anlayacağı forma (Postfix: 3 4 +) dönüştüren yöntemdir.

Bilgisayarlar parantezleri sevmez, bu yüzden işlem önceliğini sıraya dizen bu algoritma kullanılır. 
Mantığı bir tren istasyonundaki manevra sahasına (Shunting Yard) benzer; vagonlar (operatörler) geçici bir hatta 
(Stack) bekletilirken, yolcular (sayılar) direkt hedefe gider. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack Yapisi
char stack[MAX];
int top = -1;

// Stack Islemleri
void push(char item) {
    if (top >= MAX - 1) return;
    stack[++top] = item;
}

char pop() {
    if (top < 0) return -1;
    return stack[top--];
}

// Stack'in tepesindeki elemana bakma (silmeden)
char peek() {
    if (top < 0) return -1;
    return stack[top];
}

// Operator Oncelik Kontrolu
// Yuksek sayi = Yuksek oncelik
int precedence(char symbol) {
    if (symbol == '^') return 3;
    if (symbol == '*' || symbol == '/') return 2;
    if (symbol == '+' || symbol == '-') return 1;
    return 0;
}

// Karakterin operator olup olmadigini kontrol et
int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

// --- SHUNTING YARD ALGORITMASI ---
void infixToPostfix(char* infix) {
    int i = 0;
    char token;
    
    printf("Infix: %s\n", infix);
    printf("Postfix: ");

    while (infix[i] != '\0') {
        token = infix[i];

        // 1. Eger harf veya rakam ise direkt yazdir
        if (isalnum(token)) {
            printf("%c", token);
        }
        // 2. Sol parantez ise stack'e at
        else if (token == '(') {
            push(token);
        }
        // 3. Sag parantez ise sol parantezi bulana kadar pop yap
        else if (token == ')') {
            while (top != -1 && peek() != '(') {
                printf("%c", pop());
            }
            pop(); // Sol parantezi '(' stackten at
        }
        // 4. Operator ise oncelik kontrolu yap
        else if (isOperator(token)) {
            while (top != -1 && precedence(peek()) >= precedence(token)) {
                printf("%c", pop());
            }
            push(token);
        }
        
        i++;
    }

    // 5. Stackte kalanlari bosalt
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    char infix[] = "A+B*(C-D)";
    infixToPostfix(infix);
    
    char infix2[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(infix2);

    return 0;
}

/*ALGORİTMANIN MANTİGİ

Bu işlem için bir Stack (Yığın) ve bir Output (Çıktı) alanı kullanılır.

Sayı/Değişken Gelirse: Direkt Output'a ekle.

Sol Parantez ( Gelirse: Direkt Stack'e at.

Sağ Parantez ) Gelirse:

Sol parantez ( görene kadar Stack'teki her şeyi pop yap ve Output'a ekle.

Sol parantezi Stack'ten at (Output'a ekleme).

*Operatör (+, -, , /) Gelirse:

Stack'in tepesindeki operatörün önceliği, gelen operatörden büyük veya eşitse: Stack'tekini pop yap, Output'a at. (Bunu Stack boşalana veya düşük öncelikli gelene kadar tekrarla).

Gelen operatörü Stack'e push et.

İfade Bittiğinde: Stack'te kalan her şeyi sırasıyla pop yap ve Output'a ekle.*/