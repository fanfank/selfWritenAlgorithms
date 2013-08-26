template<typename Comparable>
void insertionSort(Comparable a[], int begin, int end)
{
    if(a == NULL || begin < 0 || (begin + 1) >= end)
        return;

    for(int i = begin; i < end; i++)
    {
        int j = begin;
        while(j < i && a[j] < a[i])
            j++;
        int tmp = a[i];
        for(int k = i; k > j; k--)
            a[k] = a[k - 1];
        a[j] = tmp;
    }
}
