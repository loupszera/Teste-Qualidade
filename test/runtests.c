#include <stdio.h>
#include "test.h"

int tests_run = 0;

int main() {
    printf("Iniciando os testes...\n\n");
    char *result = test_suite();
    if (result != 0) {
        printf("FALHA: %s\n", result);
    } else {
        printf("TODOS OS TESTES PASSARAM\n");
    }
    printf("Testes executados: %d\n", tests_run);
    return result != 0;
} 