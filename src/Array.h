/*
 * Array.h
 *
 * External header for Array
 *
 * ~ RedFox0x20
 */
#ifndef DS_ARRAY_H
#define DS_ARRAY_H

#ifndef DS_ARRAY_INTERNAL_H

/*
 * DS_Array_t
 * Declared void for public use, must be created as a pointer using
 * DS_Array_Create.
 */
typedef struct DS_Array DS_Array_t;

#endif /* DS_ARRAY_INTERNAL_H */

/*
 * DS_ARRAY
 * Cast some pointer to a DS_Array_t, used for inheritance
 */
#define DS_ARRAY(obj) ((DS_Array_t*)obj)

/*
 * DS_Array_Create
 * Perform the initial allocation and initialisation of an array
 */
DS_Array_t* DS_Array_Create(
        unsigned int MemberSize,    /* How many bytes each member requires */
        unsigned int MemberCount);  /* How many members to allocate for    */

/*
 * DS_Array_Destroy
 * Deallocate an array
 */
unsigned int DS_Array_Destroy(
        DS_Array_t** Arr);  /* The array to deallocate */

/*
 * DS_Array_GetData
 * Get the data pointer from an array
 */
void* DS_Array_GetData(
        DS_Array_t* Arr);   /* The array whose data pointer to retrieve */

/*
 * DS_Array_GetLength
 * Get the number of members that the array has requested
 */
unsigned int DS_Array_GetLength(
        DS_Array_t* Arr);   /* The array whose length to retrieve */

/*
 * DS_Array_Resize
 * Resize an array to hold n members, this will not shrink the memory allocation
 * but may extend the memory allocation when required. Does not initialise
 * memory.
 */
unsigned int DS_Array_Resize(
        DS_Array_t* Arr,
        unsigned int MemberCount);

#endif /* DS_ARRAY_H */
