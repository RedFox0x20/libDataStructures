#include <stdio.h>
#include <stdlib.h>

#include <Array.h>

int Test_Array(void)
{
    void* DataPtr;
    char* Data;
    unsigned int Size;
    unsigned int i;

    DS_Array_t* Arr;

    Arr = DS_Array_Create(sizeof(char), 128, 5);
    if (Arr == NULL) { return 1; }


    DataPtr = DS_Array_GetData(Arr);
    if (DataPtr == NULL) { return 2; }

    Size = DS_Array_GetLength(Arr);
    if (Size != 128) { return 3; }

    Data = DataPtr;
    for (i = 0; i < Size; i++)
    {
        printf("%d, ", (int)Data[i]);
    }
    printf("\r\n");
    if (Data[0] != 5) { return 4; }

    DS_Array_Resize(Arr, 256, 1);
    Size = DS_Array_GetLength(Arr);
    if (Size != 256) { return 5; }

    if (Data[200] != 1) { return 6; }

    for (i = 0; i < Size; i++)
    {
        printf("%d, ", (int)Data[i]);
    }

    printf("\r\n");
    DS_Array_Destroy(&Arr);
    return 0;

}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    printf("Test_Array = %d\r\n", Test_Array());

    return 0;
}
