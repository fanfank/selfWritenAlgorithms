#ifndef MERGESORTV3_CPP
#define MERGESORTV3_CPP
template<typename T>
void __mergeSort(T a[], T helper[], int left, int rightp1)
{
    if((left + 1) >= rightp1 || left < 0)
        return;
    int middle = left + (rightp1 - left)/2;
    __mergeSort(a, helper, left, middle);
    __mergeSort(a, helper, middle, rightp1);
    int lp = left, rp = middle, tp = 0;
    while(lp < middle && rp < rightp1)
    {
        if(a[lp] < a[rp])
            helper[tp++] = a[lp++];
        else
            helper[tp++] = a[rp++];
    }
    while(lp < middle)
        helper[tp++] = a[lp++];
    while(rp > left)
        a[--rp] = helper[--tp];
}
template<typename T>
int __mergeSort(T a[], int left, int rightp1)
{
    if(a == 0 || left < 0 || left >= rightp1)
        return -1;
    T *helper = new T[rightp1 - left];
    __mergeSort(a, helper, left, rightp1);
    delete []helper;
    return 0;
}

#endif
