#include <stdio.h>
#include "test.h"
#include "miniunit-master/miniunit.h"

MU_TEST(test_check) {
	mu_check(5 == 7);
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_check);
}

int main() {
	printf("Iniciando os testes...\n\n");
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}