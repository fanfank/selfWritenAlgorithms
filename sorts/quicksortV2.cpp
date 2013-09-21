#ifndef NULL
#define NULL 0
#endif
template<typename Comparable>
void _selectFrom3(Comparable &l, Comparable &m, Comparable &r)
{
    if(r < l) swap(r, l);
    if(m < l) swap(m, l);
    if(m < r) swap(m, r);
}

template<typename Comparable>
int _partition(Comparable a[], int left, int right)
{
    _selectFrom3(a[left], a[left + (right - left)/2], a[right]);
    int pivot = right;
    int lpos = left, rpos = right;
    while(1) //Compatible with C code, no "true"
    {
        while(a[++lpos] < a[pivot]);
        while(a[--rpos] > a[pivot]);

        if(lpos < rpos)
            swap(a[lpos], a[rpos]);
        else
            break;
    }
    
    swap(a[lpos], a[pivot]);
    return lpos;
}

template<typename Comparable>
void _quickSort2(Comparable a[], int left, int right)
{
    if(right - left < 10)
    {
        _selectionSort(a, left, right + 1);
        return;
    }

    int p = _partition(a, left, right);
    _quickSort2(a, left, p - 1);
    _quickSort2(a, p + 1, right);
}

template<typename Comparable>
int _quickSort(Comparable a[], int left, int rightp1)
{
    if(a == NULL || left < 0 || left >= rightp1)
        return -1;

    _quickSort2(a, left, rightp1 - 1);
    return 0;
}
