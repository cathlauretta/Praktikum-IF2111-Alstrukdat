#include "boolean.h"
#include "arraydin.h"
#include <stdio.h>

int main()
{
    ArrayDin SussyBaka = MakeArrayDin();
    InsertFirst(&SussyBaka, 69);
    InsertFirst(&SussyBaka, 72);
    InsertFirst(&SussyBaka, 5);
    InsertFirst(&SussyBaka, 97);
    PrintArrayDin(SussyBaka);
    ArrayDin copyArr = CopyArrayDin(SussyBaka);
    PrintArrayDin(copyArr);
    DeallocateArrayDin(&copyArr);
}