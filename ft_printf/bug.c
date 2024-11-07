extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 9

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	handle_signals();
	cout << FG_LYELLOW << "category: p" << RESET_ALL;

	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print(" %p ", -1));
	TEST(2, print(" %p ", 1));
	TEST(3, print(" %p ", 15));
	TEST(4, print(" %p ", 16));
	TEST(5, print(" %p ", 17));
	TEST(6, print(" %p %p ", LONG_MIN, LONG_MAX));
	TEST(7, print(" %p %p ", INT_MIN, INT_MAX));
	TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));
	TEST(9, print(" %p %p ", 0, 0));
	cout << ENDL;
	return (0);
}

For p format:
Error in test 1: ft_printf("%p", ""): returned: 9, but expected: 11
Error in test 1: ft_printf("%p", ""): different memory
expected:
0000: 3078 3130 3939 3238 6561 3000           ->  0x109928ea0.
yours:
0000: 3130 3939 3238 6561 3000 1111           ->  109928ea0...

Error in test 2: ft_printf("%p", NULL): returned: 1, but expected: 3
Error in test 2: ft_printf("%p", NULL): different memory
expected:
0000: 3078 3000                               ->  0x0.
yours:
0000: 3000 1111                               ->  0...

Error in test 3: ft_printf("%p", (void *)-14523): returned: 16, but expected: 18
Error in test 3: ft_printf("%p", (void *)-14523): different memory
expected:
0000: 3078 6666 6666 6666 6666 6666 6666 6337 ->  0xffffffffffffc7
0010: 3435 00                                 ->  45.
yours:
0000: 6666 6666 6666 6666 6666 6666 6337 3435 ->  ffffffffffffc745
0010: 0011 11                                 ->  ...

Error in test 4: ft_printf("0x%p-", (void *)ULONG_MAX): returned: 19, but expected: 21
Error in test 4: ft_printf("0x%p-", (void *)ULONG_MAX): different memory
expected:
0000: 3078 3078 6666 6666 6666 6666 6666 6666 ->  0x0xffffffffffff
0010: 6666 6666 2d00                          ->  ffff-.
yours:
0000: 3078 6666 6666 6666 6666 6666 6666 6666 ->  0xffffffffffffff
0010: 6666 2d00 1111                          ->  ff-...

Error in test 5: ft_printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX): returned: 26, but expected: 32
Error in test 5: ft_printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX): different memory
expected:
0000: 3078 3830 3030 3030 3030 3030 3036 3737 ->  0x80000000000677
0010: 6166 7030 7830 3078 3766 6666 6666 6666 ->  afp0x00x7fffffff
0020: 00                                      ->  .
yours:
0000: 3830 3030 3030 3030 3030 3036 3737 6166 ->  80000000000677af
0010: 7030 3766 6666 6666 6666 0011 1111 1111 ->  p07fffffff......
