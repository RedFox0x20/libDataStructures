/*
 * FloatBuffer.c
 *
 * Main file for FloatBuffer
 *
 * ~ RedFox0x20
 */
#include "FloatBuffer.internal.h"
#include "FloatBuffer.h"

#include <stdlib.h>
#include <string.h>

DS_FloatBuffer_t* DS_FloatBuffer_Create(unsigned int Length)
{
    DS_FloatBuffer_t* Buff;

    Buff = malloc(sizeof(struct DS_FloatBuffer));
    if (Buff == NULL)
    {
        return NULL;
    }

    Buff->Data = calloc(Length, sizeof(float));
    if (Buff->Data == NULL)
    {
        free(Buff);
        return NULL;
    }

    Buff->Length = Length;

    return Buff;
}

int DS_FloatBuffer_Destroy(DS_FloatBuffer_t** Buff)
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

int DS_FloatBuffer_Resize(
        DS_FloatBuffer_t* Buff,
        unsigned int Length,
        unsigned int Clear)
{
    float* Temp;

    if (Buff == NULL)
    {
        return -1;
    }

    Temp = reallocarray(Buff->Data, Length, sizeof(float));
    if (Temp == NULL)
    {
        return -1;
    }

    if (Clear != 0)
    {
        memset(Buff->Data, 0, Length * sizeof(float));
    }

    Buff->Data = Temp;
    Buff->Length = Length;

    return Length;
}

float* DS_FloatBuffer_GetData(DS_FloatBuffer_t* Buff)
{
    return Buff->Data;
}

unsigned int DS_FloatBuffer_GetLength(DS_FloatBuffer_t* Buff)
{
    return Buff->Length;
}

unsigned int DS_FloatBuffer_sizeof(void)
{
    return sizeof(DS_FloatBuffer_t);
}
