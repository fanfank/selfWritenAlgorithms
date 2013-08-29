#ifndef NULL
#define NULL 0
#endif
template<typename Comparable>
void selectionSort(Comparable a[], int left, int rightp1)
{
    if(a == NULL || left < 0 || (left + 1 >= rightp1))
        return;

    Comparable tmp;
    int tmpPos;
    for(int i = left; i < rightp1; i++)
    {
       tmpPos = i;
       for(int j = i + 1; j < rightp1; j++)
           if(a[tmpPos] > a[j])
               tmpPos = j;

       tmp = a[tmpPos];
       a[tmpPos] = a[i];
       a[i] = tmp;
    }
}
