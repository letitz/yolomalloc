/*-------------------------*
<| .::. yolomalloc.h .::.  |>
<| Dude, do you even swag? |>
 *-------------------------*/

#ifndef YOLOMALLOC_H
#define YOLOMALLOC_H

#include <stddef.h>

/* Allocating dat memory like a boss */
void *yolomalloc(size_t size);

#ifndef YOLO
/* Error 404: swag not found */
void yolofree(void *ptr);
#endif

#endif
