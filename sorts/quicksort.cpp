template<typename Comparable>
void selectFrom3(Comparable &l, Comparable &m, Comparable &r)
{
    if(m < l)
        swap(l, m);
    if(r < l)
        swap(l, r);
    if(m < r)
        swap(m, r);
}

template<typename Comparable>
void quickSort2(Comparable a[], int left, int right)
{
    if(right - left <= 10)
    {
        selectionSort(a, left, right + 1);
        return;
    }

    int mid = left + (right - left) / 2;
    selectFrom3(a[left], a[mid], a[right]);

    int lp = left, rp = right;
    while(lp < rp)
    {
        while(a[++lp] < a[right]);
        while(a[--rp] > a[right]);
        if(lp < rp)
            swap(a[lp], a[rp]);
    }
    swap(a[lp], a[right]);
    quickSort2(a, left, lp - 1);
    quickSort2(a, lp + 1, right);
}

template<typename Comparable>
void quickSort(Comparable a[], int left, int rightEnd)
{
    if(a == NULL || left < 0 || (left + 1 >= rightEnd))
        return;
    quickSort2(a, left, rightEnd - 1);
}
