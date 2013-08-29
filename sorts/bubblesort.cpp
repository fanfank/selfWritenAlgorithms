#ifndef NULL
#define NULL 0
#endif
template<typename Comparable>
void bubbleSort(Comparable a[], int left, int rightp1)
{
    if(a == NULL || left < 0 || (left + 1) >= rightp1)
        return;
    while(rightp1-- > left)
    {
        for(int i = left; i < rightp1; i++)
            if(a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
    }
}
