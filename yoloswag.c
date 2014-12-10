/*:-:-:-:-:-:-:*
 I yoloswag.c I
 *:-:-:-:-:-:-:*/

#include <stdlib.h>
#include <stdio.h>

#include "yolomalloc.h"

int main(int argc, char **argv) {
    printf("sizeof(long) = %lu\n", sizeof(long));
    for (int i = 1; i < argc; i++) {
        long n = atol(argv[i]);        
        printf("yolomalloc(%ld) = %p\n", n, yolomalloc(n));
    }
    return 0;
}
