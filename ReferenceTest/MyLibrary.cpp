void swapValue(int a, int b)
{
    int c = a;
    a = b; b = c;
}

void swapRef(int& a, int& b) //�����͸� ������� ����
{
    int c = a;
    a = b; b = c;
}

void swapRef(int* a, int* b) //�����͸� ������� ����
{
    int c = *a;
    *a = *b; *b = c;
}
