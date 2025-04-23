/**
 * miniunit.h
 *
 * Copyright (c) 2017 Hayato Takenaka
 *
 * Licensed under the MIT license:
 * https://opensource.org/licenses/mit-license.php
**/
#ifndef MINIUNIT_H
#define MINIUNIT_H

#include <stdio.h>

// Macros para testes
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                              if (message) return message; } while (0)

extern int tests_run;

// Macros específicas para nossos testes
#define MU_TEST(name) static char* name(void)
#define MU_RUN_SUITE(suite) do { char* result = suite(); \
                                if (result != 0) { \
                                    printf("Teste falhou: %s\n", result); \
                                    return -1; \
                                } } while (0)
#define MU_REPORT() printf("Todos os %d testes passaram!\n", tests_run)

#endif // MINIUNIT_H

