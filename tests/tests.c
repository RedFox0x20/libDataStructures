#include <stdio.h>
#include <stdlib.h>
#include <ByteBuffer.h>
#include <FloatBuffer.h>

int Test_ByteBuffer(void)
{
    DS_ByteBuffer_t* Buff = DS_ByteBuffer_Create(100);
    if (Buff == NULL) { return 1; }
    if (DS_ByteBuffer_GetLength(Buff) != 100) { return 2; }
    if (DS_ByteBuffer_GetData(Buff) == NULL)  { return 3; }

    DS_ByteBuffer_Resize(Buff, 200, 0);
    if (DS_ByteBuffer_GetLength(Buff) != 200) { return 4; }
    if (DS_ByteBuffer_GetData(Buff) == NULL)  { return 5; }

    DS_ByteBuffer_Destroy(&Buff);
    if (Buff != NULL) { return 1; }

    return 0;
}

int Test_FloatBuffer(void)
{
    DS_FloatBuffer_t* Buff = DS_FloatBuffer_Create(100);
    if (Buff == NULL) { return 1; }
    if (DS_FloatBuffer_GetLength(Buff) != 100) { return 2; }
    if (DS_FloatBuffer_GetData(Buff) == NULL)  { return 3; }

    DS_FloatBuffer_Resize(Buff, 200, 0);
    if (DS_FloatBuffer_GetLength(Buff) != 200) { return 4; }
    if (DS_FloatBuffer_GetData(Buff) == NULL)  { return 5; }

    DS_FloatBuffer_Destroy(&Buff);
    if (Buff != NULL) { return 1; }

    return 0;
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    int ByteBufferTestResult = Test_ByteBuffer();
    int FloatBufferTestResult = Test_FloatBuffer();

    printf("Struct sizes:\r\n"
            "ByteBuffer: %i\r\n"
            "FloatBuffer: %i\r\n",
            DS_ByteBuffer_sizeof(),
            DS_FloatBuffer_sizeof());

    printf("\r\nTest results:\r\n"
            "ByteBuffer: %i\r\n"
            "FloatBuffer: %i\r\n",
            ByteBufferTestResult,
            FloatBufferTestResult);

    return 0;
}
