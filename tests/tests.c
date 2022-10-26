#include <stdio.h>
#include <stdlib.h>

#include <Array.h>

int Test_Array(void)
{
    void* DataPtr;
    int* Data;
    int Size;

    DS_Array_t* Arr;

    Arr = DS_Array_Create(sizeof(int), 128);
    if (Arr == NULL) { return 1; }

    DataPtr = DS_Array_GetData(Arr);
    if (DataPtr == NULL) { return 2; }

    Size = DS_Array_GetLength(Arr);
    if (Size != 128) { return 3; }

    Data = DataPtr;
    Data[0] = 127;

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
