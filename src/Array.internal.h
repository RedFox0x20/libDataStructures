/*
 * Array.internal.h
 *
 * Internal header for Array
 *
 * ~ RedFox0x20
 */
#ifndef DS_ARRAY_INTERNAL_H
#define DS_ARRAY_INTERNAL_H

/*
 * DS_ARRAY_BLOCK_SIZE
 * A constant to define the number of bytes that are allocated to an array per
 * malloc/realloc call. This reduces the amount of malloc calls necessary if the
 * user decides they want to grow an array.
 */
#define DS_ARRAY_BLOCK_SIZE 4096u

/*
 * DS_ARRAY_BLOCK_SIZE_REQUIRED
 * Calculate the number of blocks required to store x bytes of data
 */
#define DS_ARRAY_BLOCK_SIZE_REQUIRED(x) \
    ((unsigned int)((x) / DS_ARRAY_BLOCK_SIZE) + 1)

/*
 * DS_Array
 * A wrapper for arrays that will handle any memory allocations and
 * deallocations to help with code safety.
 * The underlying type of data does not matter here, the user can cast the Data
 * pointer when required.
 */
typedef struct DS_Array
{
    void* Data;                  /* Allocated memory to store values          */
    unsigned int BytesUsed;      /* How many of the allocated bytes are used  */
    unsigned int BytesAllocated; /* How many bytes have been allocated?       */
    unsigned int MemberSize;     /* How many bytes does each member use       */
    unsigned int MemberCount;    /* How many members has the user requested   */
} DS_Array_t;

#endif /* DS_ARRAY_INTERNAL_H */
