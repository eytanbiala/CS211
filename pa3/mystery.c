#include <stdio.h>
#include "mystery.h"

int mystery(int n) {
    int a = 1, b = 1;
    int i;
    for (i = 3; i <= n; i++) {
    	int c = a + b;
    	a = b;
    	b = c;
    }
    return b;
}