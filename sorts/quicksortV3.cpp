#ifndef QUICKSORTV3_CPP
#define QUICKSORTV3_CPP
#include<algorithm>

template<typename T>
T& __selFrom3(T &l, T &m, T &r)
{
    if(m < l) swap(l, m);
    if(r < l) swap(l, r);
    if(m < r) swap(m, r);
    return r;
}

template<typename T>
int __partition(T a[], int left, int right)
{
    if(right-left == 1) {
        if(a[left] > a[right])
            swap(a[left], a[right]);
        return left;
    }
    int middle = left + (right - left)/2;
    T &pivot = __selFrom3(a[left], a[middle], a[right]);
    int lp = left, rp = right;
    while(true) {
        while(a[++lp] < pivot);
        while(a[--rp] > pivot);
        if(lp >= rp)
            break;
        swap(a[lp], a[rp]);
    }
    swap(a[lp], pivot);
    return lp;
}

template<typename T>
void __quickSort2(T a[], int left, int right)
{
    if(left >= right || a == NULL || left < 0) //important
        return;
    int q = __partition(a, left, right);
    __quickSort2(a, left, q - 1);
    __quickSort2(a, q + 1, right);
}

template<typename T>
int __quickSort(T a[], int left, int rightp1)
{
    if(a == NULL || left < 0 || left >= rightp1)
        return -1;
    __quickSort2(a, left, rightp1 - 1);
    return 0;
}

#endif
