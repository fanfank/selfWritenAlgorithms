#ifndef HEAPSORTV2_CPP
#define HEAPSORTV2_CPP
#include<iostream>
#include<algorithm>
using namespace std;
template<typename T>
void _topDown(T a[], int i, int gap, int sz)
{
    int maxi, lch, rch;
    while(i <= sz)
    {
        maxi = i, lch = i * 2, rch = i * 2 + 1;
        if(lch <= sz && a[lch + gap] > a[maxi + gap])
            maxi = lch;
        if(rch <= sz && a[rch + gap] > a[maxi + gap])
            maxi = rch;
        if(maxi == i)
            break;
        swap(a[i+gap], a[maxi+gap]);
        i = maxi;
    }
}

template<typename T>
void _makeHeap(T a[], int left, int rightp1)
{
    int gap = left - 1;
    int sz = rightp1 - left;
    for(int i = sz/2; i > 0; i--)
    {
        _topDown(a, i, gap, sz);
    }
}

template<typename T>
void _sortHeap(T a[], int left, int rightp1)
{
    int gap = left - 1;
    int sz = rightp1 - left;
    while(sz > 1)
    {
        swap(a[1+gap], a[sz+gap]);
        --sz;
        _topDown(a, 1, gap, sz);
    }
}

template<typename T>
int _heapSort(T a[], int left, int rightp1)
{
    if(a == NULL || left < 0 || left >= rightp1)
        return -1;
    _makeHeap(a, left, rightp1);
    _sortHeap(a, left, rightp1);
    return 0;
}
#endif
