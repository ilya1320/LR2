// benchmark.c
#include "stack.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void benchmark_push(int num_operations) {
    Stack stack;
    initStack(&stack);
    
    clock_t start = clock();
    
    for (int i = 0; i < num_operations; i++) {
        push(&stack, i);
    }
    
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("push(%d операций): %.6f сек, %.0f оп/сек\n", 
           num_operations, time_spent, num_operations / time_spent);
    
    destroyStack(&stack);
}

void benchmark_pop(int num_operations) {
    Stack stack;
    initStack(&stack);
    
    // Сначала заполним стек
    for (int i = 0; i < num_operations; i++) {
        push(&stack, i);
    }
    
    clock_t start = clock();
    
    for (int i = 0; i < num_operations; i++) {
        pop(&stack);
    }
    
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("pop(%d операций):  %.6f сек, %.0f оп/сек\n", 
           num_operations, time_spent, num_operations / time_spent);
    
    destroyStack(&stack);
}

void benchmark_push_pop(int num_operations) {
    Stack stack;
    initStack(&stack);
    
    clock_t start = clock();
    
    for (int i = 0; i < num_operations; i++) {
        push(&stack, i);
        pop(&stack);
    }
    
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("push+pop(%d операций): %.6f сек, %.0f оп/сек\n", 
           num_operations, time_spent, num_operations / time_spent);
    
    destroyStack(&stack);
}

int main() {
    printf("=== БЕНЧМАРК СТЕКА ===\n\n");
    
    int sizes[] = {1000, 10000, 100000, 1000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    for (int i = 0; i < num_sizes; i++) {
        printf("\nРазмер: %d\n", sizes[i]);
        benchmark_push(sizes[i]);
        benchmark_pop(sizes[i]);
        benchmark_push_pop(sizes[i]);
    }
    
    return 0;
}
