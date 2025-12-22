#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} Stack;

void push(Stack *s, char c) {
    if (s->top >= MAX - 1) {
        printf("Stack dolu!\n");
        return;
    }
    s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    if (s->top == -1) return -1;
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    if (s->top == -1) return -1;
    return s->items[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int precedence(char operator) {
    switch (operator) {
        case '^': return 3;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default: return 0;
    }
}


void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    s.top = -1; 
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        
        
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        
    
        else if (ch == '(') {
            push(&s, ch);
        }
        
        
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) != '(') {
                printf("Gecersiz ifade!\n"); 
                return;
            } else {
                pop(&s); 
            }
        }
        
       
        else {
            while (!isEmpty(&s) && precedence(ch) <= precedence(peek(&s))) {
                postfix[k++] = pop(&s);
            }
            push(&s, ch);
        }
    }

   
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0'; 
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("--- Shunting Yard Algoritmasi ---\n");
    printf("Infix ifadeyi giriniz (Ornek: A+B*C): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Donusumu: %s\n", postfix);

    return 0;
}