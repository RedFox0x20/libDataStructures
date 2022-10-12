/*
 * ByteBuffer.c
 *
 * Main file for ByteBuffer
 *
 * ~ RedFox0x20
 */
#include "ByteBuffer.internal.h"
#include "ByteBuffer.h"

#include <stdlib.h>
#include <string.h>

DS_ByteBuffer_t* DS_ByteBuffer_Create(unsigned int Length)
{
    DS_ByteBuffer_t* Buff;

    Buff = malloc(sizeof(struct DS_ByteBuffer));
    if (Buff == NULL)
    {
        return NULL;
    }

    Buff->Data = calloc(Length, sizeof(unsigned char));
    if (Buff->Data == NULL)
    {
        free(Buff);
        return NULL;
    }

    Buff->Length = Length;

    return Buff;
}

int DS_ByteBuffer_Destroy(DS_ByteBuffer_t** Buff)
{
    if (Buff == NULL)
    {
        return -1;
    }

    if (*Buff == NULL)
    {
        return -2;
    }

    free((*Buff)->Data);
    (*Buff)->Data = NULL;
    (*Buff)->Length = 0;

    free(*Buff);
    *Buff = NULL;

    return 0;
}

int DS_ByteBuffer_Resize(
        DS_ByteBuffer_t* Buff,
        unsigned int Length,
        unsigned int Clear)
{
    unsigned char* Temp;

    if (Buff == NULL)
    {
        return -1;
    }

    Temp = reallocarray(Buff->Data, Length, sizeof(unsigned char));
    if (Temp == NULL)
    {
        return -1;
    }

    if (Clear != 0)
    {
        memset(Buff->Data, 0, Length * sizeof(unsigned char));
    }

    Buff->Data = Temp;
    Buff->Length = Length;

    return Length;
}

unsigned char* DS_ByteBuffer_GetData(DS_ByteBuffer_t* Buff)
{
    return Buff->Data;
}
