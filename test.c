#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

void test_createNode() {
    Node* node = createNode(42);
    assert(node != NULL);
    assert(node->data == 42);
    assert(node->next == NULL);
    free(node);
    printf("test_createNode passed\n");
}

void test_initStack() {
    Stack stack;
    initStack(&stack);
    assert(stack.top == NULL);
    printf("test_initStack passed\n");
}

void test_push_pop() {
    Stack stack;
    initStack(&stack);

    // Test push
    push(&stack, 10);
    assert(stack.top != NULL);
    assert(stack.top->data == 10);

    push(&stack, 20);
    assert(stack.top->data == 20);
    assert(stack.top->next->data == 10);

    // Test pop
    pop(&stack);
    assert(stack.top->data == 10);

    pop(&stack);
    assert(stack.top == NULL);

    // Test pop on empty stack
    pop(&stack); // Should not crash

    printf("test_push_pop passed\n");
}

void test_searchByValue() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* found = searchByValue(&stack, 20);
    assert(found != NULL);
    assert(found->data == 20);

    found = searchByValue(&stack, 40);
    assert(found == NULL);

    destroyStack(&stack);
    printf("test_searchByValue passed\n");
}

void test_searchByIndex() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* found = searchByIndex(&stack, 0);
    assert(found != NULL);
    assert(found->data == 30);

    found = searchByIndex(&stack, 1);
    assert(found != NULL);
    assert(found->data == 20);

    found = searchByIndex(&stack, 2);
    assert(found != NULL);
    assert(found->data == 10);

    found = searchByIndex(&stack, 3);
    assert(found == NULL);

    destroyStack(&stack);
    printf("test_searchByIndex passed\n");
}

void test_getTop() {
    Stack stack;
    initStack(&stack);

    assert(getTop(&stack) == NULL);

    push(&stack, 10);
    assert(getTop(&stack)->data == 10);

    push(&stack, 20);
    assert(getTop(&stack)->data == 20);

    destroyStack(&stack);
    printf("test_getTop passed\n");
}

void test_isEmpty() {
    Stack stack;
    initStack(&stack);

    assert(isEmpty(&stack) == true);

    push(&stack, 10);
    assert(isEmpty(&stack) == false);

    pop(&stack);
    assert(isEmpty(&stack) == true);

    printf("test_isEmpty passed\n");
}

void test_destroyStack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    destroyStack(&stack);
    assert(stack.top == NULL);

    printf("test_destroyStack passed\n");
}

void test_traverseStack() {
    Stack stack;
    initStack(&stack);

    // Test with empty stack
    printf("Testing traverseStack (should be empty):\n");
    traverseStack(&stack);

    // Test with elements
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Testing traverseStack (should show 30 20 10):\n");
    traverseStack(&stack);

    destroyStack(&stack);
    printf("test_traverseStack passed\n");
}

int main() {
    printf("Running stack tests...\n\n");

    test_createNode();
    test_initStack();
    test_push_pop();
    test_searchByValue();
    test_searchByIndex();
    test_getTop();
    test_isEmpty();
    test_destroyStack();
    test_traverseStack();

    printf("\nAll tests passed!\n");
    return 0;
}
