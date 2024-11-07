For p format:
Error in test 1: ft_printf("%p", ""): returned: 9, but expected: 11
Error in test 1: ft_printf("%p", ""): different memory
expected:
0000: 3078 3130 3865 3063 6561 3000           ->  0x108e0cea0.
yours:
0000: 3130 3865 3063 6561 3000 1111           ->  108e0cea0...

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
