#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initStack(Stack* stack) {
    stack->top = NULL;
}

void destroyStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        Node *tmp = current;
        current = current->next;
        free(tmp);
    }
    stack->top = NULL; // ИСПРАВЛЕНО: Обнуление указателя top после освобождения всей памяти
}

void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack) {
    if (stack->top == NULL) return; // ИСПРАВЛЕНО: Проверка на пустой стек

    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp); // ИСПРАВЛЕНО: Освобождение памяти удаляемого элемента
}

Node* searchByValue(Stack* stack, int value) {
    Node* current = stack->top;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next; // ИСПРАВЛЕНО: Добавлен переход к следующему элементу
    }
    return NULL;
}

Node* searchByIndex(Stack* stack, int index) {
    Node* current = stack->top;
    int count = 0;
    while (current != NULL) {
        if (count == index) {
            return current;
        }
        count++;
        current = current->next;
    }
    return NULL;
}

Node* getTop(Stack* stack) {
    return stack->top;
}

void traverseStack(Stack* stack) {
    Node* current = stack->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

bool isEmpty(Stack* stack) {
    return stack->top == NULL; // ИСПРАВЛЕНО: Удален ошибочный вызов free()
}
