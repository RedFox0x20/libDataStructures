/*
 * ByteBuffer.h
 *
 * External header for ByteBuffer
 *
 * ~ RedFox0x20
 */
#ifndef DS_BYTEBUFFER_H
#define DS_BYTEBUFFER_H

#ifndef DS_BYTEBUFFER_INTERNAL_H

typedef void* DS_ByteBuffer_t;

#endif /* DS_BYTEBUFFER_INTERNAL_H */

/*
 * DS_ByteBuffer_Create
 * Create a new byte buffer
 * Returns a new pointer
 */
DS_ByteBuffer_t* DS_ByteBuffer_Create(
        unsigned int Length); /* The length of the buffer */

/*
 * DS_ByteBuffer_Destroy
 * Free a buffer, destroying it.
 * Returns:
 *  == -1: The pointer to the buffer was NULL
 *  == -2: The buffer was NULL
 *  >   0: The buffer was destroyed
 */
int DS_ByteBuffer_Destroy(
        DS_ByteBuffer_t** Buff); /* Pointer to the buffer to destroy */

/*
 * DS_ByteBuffer_Resize
 * Resize a buffer, 0 is equivalent to freeing the data
 * Returns:
 *  <  0: Error
 *  >= 0: New size
 */
int DS_ByteBuffer_Resize(
        DS_ByteBuffer_t* Buff, /* The buffer to modify                     */
        unsigned int Length,   /* The new length of the buffer             */
        unsigned int Clear);   /* Boolean flag to clear the buffer of data */

/*
 * DS_ByteBuffer_GetData
 * Get the underlying data pointer
 * Returns a pointer to the underlying data
 *  !! realloc or free should not be called on this pointer, use
 *  !! DS_ByteBuffer_Destroy
 */
unsigned char* DS_ByteBuffer_GetData(
        DS_ByteBuffer_t* Buff); /* The buffer whose data pointer to get */

/*
 * DS_ByteBuffer_GetLength
 * Get the allocated length of a buffer
 * Returns an unsigned integer containing the length of the data
 */
unsigned int DS_ByteBuffer_GetLength(
        DS_ByteBuffer_t* Buff); /* The buffer whose length to get */

#endif /* DS_BYTEBUFFER_H */
