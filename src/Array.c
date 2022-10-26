/*
 * Array.c
 *
 * Main file for Array
 *
 * ~ RedFox0x20
 */
#include "Array.internal.h"
#include "Array.h"
#include <stdlib.h> /* malloc, realloc, free */
#include <string.h> /* memset */

/******************************************************************************/

DS_Array_t* DS_Array_Create(
        unsigned int MemberSize,
        unsigned int MemberCount)
{
    DS_Array_t* Arr;
    unsigned int BytesUsed;
    unsigned int BytesAllocated;

    Arr = malloc(sizeof(DS_Array_t));
    if (Arr == NULL) { return NULL; }
    memset(Arr, 0, sizeof(DS_Array_t));

    BytesUsed = MemberSize * MemberCount;
    BytesAllocated = 
        DS_ARRAY_BLOCK_SIZE_REQUIRED(BytesUsed) * DS_ARRAY_BLOCK_SIZE; 

    Arr->Data = malloc(BytesAllocated);
    if (Arr->Data == NULL)
    {
        free(Arr);
        return NULL;
    }


    Arr->BytesUsed = BytesUsed;
    Arr->BytesAllocated = BytesAllocated;
    Arr->MemberSize = MemberSize;
    Arr->MemberCount = MemberCount;

    return Arr;
}

/******************************************************************************/

unsigned int DS_Array_Destroy(
        DS_Array_t** Arr)
{
    if (Arr  == NULL) { return 1; }
    if (*Arr == NULL) { return 1; }

    free((*Arr)->Data);
    free(*Arr);
    *Arr = NULL;

    return 0;
}

/******************************************************************************/

void* DS_Array_GetData(
        DS_Array_t* Arr)
{
    if (Arr == NULL) { return NULL; }
    return Arr->Data;
}

/******************************************************************************/

unsigned int DS_Array_GetLength(
        DS_Array_t* Arr)
{
    if (Arr == NULL) { return 0; }
    return Arr->MemberCount;
}

/******************************************************************************/

unsigned int DS_Array_Resize(
        DS_Array_t* Arr,
        unsigned int MemberCount)
{
    unsigned int BytesRequired;
    void* Temp;

    if (Arr == NULL) { return 1; }

    /* Error condition, should never happen */
    if (Arr->Data == NULL) { return 1; } 

    BytesRequired = 
        DS_ARRAY_BLOCK_SIZE_REQUIRED(Arr->MemberSize * MemberCount) 
        * DS_ARRAY_BLOCK_SIZE;

    if (BytesRequired > Arr->BytesAllocated)
    {
        Temp = realloc(Arr->Data, BytesRequired);
        if (Temp == NULL) { return 1; }
        Arr->Data = Temp;
    }

    Arr->MemberCount = MemberCount;
    Arr->BytesAllocated = BytesRequired;
    Arr->BytesUsed = MemberCount * Arr->MemberSize;

    return 0;
}
