/*======================*
%$ /!\ yolomalloc.c /!\ $%
%$ DANGER Swag overflow $%
 *======================*/

/* Feature test macros */
#define _DEFAULT_SOURCE /* for sbrk */

/* Includes */

#include <unistd.h>
#include <stdio.h>

#include "yolomalloc.h"

/* Defines */

#define YOLO_WORD  (sizeof(long))
#define YOLO_DWORD (2 * sizeof(long))
#define YOLO_CHUNK 8192

/* Globals */

void *yolo_start = NULL;
void *yolo_end   = NULL;

int yolo_init() {
    yolo_start = sbrk(0);    
    if (yolo_start == (void*) -1) {
        yolo_start = NULL;
        yolo_end = NULL;
        return -1;
    }
    yolo_end = yolo_start;
    return 0;
}

/* Ya know, allocating stuff and all */
void *yolomalloc(size_t size) {
    if (size == 0) {
        return NULL;
    }
    if (yolo_start == NULL || yolo_end == NULL) {
        if (yolo_init() != 0) {
            return NULL;
        }
    }
    int size_w = (size + (YOLO_WORD-1)) / YOLO_WORD; // size in words
    int align_dw = ((size_w + 1) / 2) * 2; // round size_w to dword
    void *ptr = sbrk(align_dw);
    if (ptr == (void*) -1) {
        return NULL;
    }
    return ptr;
}

void yolofree(void *ptr) {
    /*----------------------------------*
     * THE YOLO IS STRONG WITH THIS ONE *
     *----------------------------------*/
}
