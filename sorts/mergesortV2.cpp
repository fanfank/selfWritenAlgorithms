#ifndef NULL
#define NULL 0
#endif
template<typename Comparable>
void _mergeSort(Comparable a[], Comparable tmp[], int left, int rightp1)
{
    if(left + 1 >= rightp1)
        return;

    int middle = left + (rightp1 - left)/2;
    _mergeSort(a, tmp, left, middle);
    _mergeSort(a, tmp, middle, rightp1);

    int lpos = left;
    int rpos = middle;
    int tpos = left;

    while(lpos < middle && rpos < rightp1)
        if(a[lpos] < a[rpos])
            tmp[tpos++] = a[lpos++];
        else
            tmp[tpos++] = a[rpos++];

    while(lpos < middle)
        tmp[tpos++] = a[lpos++];

    while(tpos-- > left)
        a[tpos] = tmp[tpos];
}

template<typename Comparable>
int _mergeSort(Comparable a[], int left, int rightp1)
{
    if(a == NULL || left < 0 || (left + 1) > rightp1)
        return -1;

    Comparable *tmp = new Comparable[rightp1 - left];
    _mergeSort(a, tmp, left, rightp1);
    delete []tmp;
    return 0;
}
