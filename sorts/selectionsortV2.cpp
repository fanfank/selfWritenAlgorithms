#ifndef NULL
#define NULL 0
#endif
template<typename Comparable>
int _selectionSort(Comparable a[], int left, int rightp1)
{
    if(a == NULL || left < 0 || left >= rightp1)
        return -1;

    int min_index;
    for(int i = left; i < rightp1; i++)
    {
        min_index = i;
        for(int j = i + 1; j < rightp1; j++)
            if(a[j] < a[min_index])
                min_index = j;
        if(min_index != i)
            swap(a[i], a[min_index]);
    }
    return 0;
}
