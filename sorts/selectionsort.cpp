template<typename Comparable>
void selectionSort(Comparable a[], int left, int rightEnd)
{
    if(a == NULL || left < 0 || (left + 1 >= rightEnd))
        return;

    Comparable tmp;
    int tmpPos;
    for(int i = left; i < rightEnd; i++)
    {
       tmpPos = i;
       for(int j = i + 1; j < rightEnd; j++)
           if(a[tmpPos] > a[j])
               tmpPos = j;

       tmp = a[tmpPos];
       a[tmpPos] = a[i];
       a[i] = tmp;
    }
}
