#include <stdio.h>
#include <stdarg.h>

void print_multiple(int count, ...) {
    va_list args;
    va_start(args, count);
    
    for (int i = 0; i < count; i++) {
        int value = va_arg(args, int);
        printf("%d ", value);
    }
    
    va_end(args);
    printf("\n");
}

int main() {
    print_multiple(3, 10, 20, 30); // Pass three integers to the variadic function
    return 0;
}

