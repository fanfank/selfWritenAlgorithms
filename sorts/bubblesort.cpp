template<typename Comparable>
void bubbleSort(Comparable a[], int begin, int end)
{
    if(a == NULL || begin < 0 || (begin + 1) >= end)
        return;
    while(end-- > begin)
    {
        for(int i = begin; i < end; i++)
            if(a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
    }
}
