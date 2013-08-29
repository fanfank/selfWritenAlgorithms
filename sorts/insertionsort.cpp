#ifndef NULL
#define NULL 0
#endif
template<typename Comparable>
void insertionSort(Comparable a[], int left, int rightp1)
{
    if(a == NULL || left < 0 || (left + 1) >= rightp1)
        return;

    for(int i = left; i < rightp1; i++)
    {
        int j = left;
        while(j < i && a[j] < a[i])
            j++;
        int tmp = a[i];
        for(int k = i; k > j; k--)
            a[k] = a[k - 1];
        a[j] = tmp;
    }
}
