/*
 * FloatBuffer.h
 *
 * External header for FloatBuffer
 *
 * ~ RedFox0x20
 */
#ifndef DS_FLOATBUFFER_H
#define DS_FLOATBUFFER_H

#ifndef DS_FLOATBUFFER_INTERNAL_H

typedef void DS_FloatBuffer_t;

#endif /* DS_FLOATBUFFER_INTERNAL_H */

/*
 * DS_FloatBuffer_Create
 * Create a new float buffer
 * Returns a new pointer
 */
DS_FloatBuffer_t* DS_FloatBuffer_Create(
        unsigned int Length); /* The length of the buffer */

/*
 * DS_FloatBuffer_Destroy
 * Free a buffer, destroying it.
 * Returns:
 *  == -1: The pointer to the buffer was NULL
 *  == -2: The buffer was NULL
 *  >   0: The buffer was destroyed
 */
int DS_FloatBuffer_Destroy(
        DS_FloatBuffer_t** Buff); /* Pointer to the buffer to destroy */

/*
 * DS_FloatBuffer_Resize
 * Resize a buffer, 0 is equivalent to freeing the data
 * Returns:
 *  <  0: Error
 *  >= 0: New size
 */
int DS_FloatBuffer_Resize(
        DS_FloatBuffer_t* Buff, /* The buffer to modify                     */
        unsigned int Length,   /* The new length of the buffer             */
        unsigned int Clear);   /* Boolean flag to clear the buffer of data */

/*
 * DS_FloatBuffer_GetData
 * Get the underlying data pointer
 * Returns a pointer to the underlying data
 *  !! realloc or free should not be called on this pointer, use
 *  !! DS_FloatBuffer_Destroy
 */
float* DS_FloatBuffer_GetData(
        DS_FloatBuffer_t* Buff); /* The buffer whose data pointer to get */

/*
 * DS_FloatBuffer_GetLength
 * Get the allocated length of a buffer
 * Returns an unsigned integer containing the length of the data
 */
unsigned int DS_FloatBuffer_GetLength(
        DS_FloatBuffer_t* Buff); /* The buffer whose length to get */

/*
 * DS_FloatBuffer_sizeof
 * Returns the number of bytes that make up the structure
 *  !! This should be used in place of sizeof(DS_FloatBuffer_t)
 */
unsigned int DS_FloatBuffer_sizeof(void);

#endif /* DS_FLOATBUFFER_H */
