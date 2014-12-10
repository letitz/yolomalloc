/*:-:-:-:-:-:-:*
 I yoloswag.c I
 *:-:-:-:-:-:-:*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "yolomalloc.h"

int main(int argc, char **argv) {
    printf("sizeof(intptr_t) = %lu\n", sizeof(intptr_t));
    for (int i = 1; i < argc; i++) {
        long n = atol(argv[i]);        
        printf("yolomalloc(%ld) = %p\n", n, yolomalloc(n));
    }
    return 0;
}
