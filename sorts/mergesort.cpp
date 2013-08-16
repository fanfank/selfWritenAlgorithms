template<typename Comparable>
void mergeSort(Comparable a[], Comparable tmpArr[],
        int left, int right)
{
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(a, tmpArr, left, mid);
    mergeSort(a, tmpArr, mid + 1, right);

    int lp = left, rp = mid + 1, tmpp = 0;
    while(lp <= mid && rp <= right)
        if(a[lp] <= a[rp])
            tmpArr[tmpp++] = a[lp++];
        else
            tmpArr[tmpp++] = a[rp++];

    while(lp <= mid)
        tmpArr[tmpp++] = a[lp++];

    while(rp <= right)
        tmpArr[tmpp++] = a[rp++];

    for(int i = 0; i < tmpp; i++)
        a[left + i] = tmpArr[i];
}

template<typename Comparable>
void mergeSort(Comparable a[], int left, int rightEnd)
{
    if(a == 0 || left < 0 || (rightEnd <= left + 1))
        return;

    Comparable *tmpArr = new Comparable[rightEnd - left];

    mergeSort(a, tmpArr, left, rightEnd - 1);
    delete []tmpArr;
}

