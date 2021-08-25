void swapValue(int a, int b)
{
    int c = a;
    a = b; b = c;
}

void swapRef(int& a, int& b) //포인터를 사용하지 않음
{
    int c = a;
    a = b; b = c;
}

void swapRef(int* a, int* b) //포인터를 사용하지 않음
{
    int c = *a;
    *a = *b; *b = c;
}
