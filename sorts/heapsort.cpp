#include<algorithm>
template<typename Comparable>
void topDown(Comparable a[], Comparable next, int gap, int ed)
{
    int left, right;
    while(true)
    {
        left = next * 2;
        right = left + 1;
        if(left < ed && a[next + gap] < a[left + gap])
            next = left;
        if(right < ed && a[next + gap] < a[right + gap])
            next = right;

        if(next == left / 2)
            break;
        
        swap(a[next + gap], a[left / 2 + gap]);
    }
}

template<typename Comparable>
void heapify_max(Comparable a[], int left, int rightp1)
{
    int gap = left - 1;
    int bg = left - gap;
    int ed = rightp1 - gap;
    for(int i = ed / 2; i >= bg; i--)
    {
        topDown(a, i, gap, ed);
    }

}

template<typename Comparable>
void heapSort2(Comparable a[], int left, int rightp1)
{
    int gap = left - 1;
    int bg = left - gap;
    int ed = rightp1 - gap;
    for(; ed > bg; )
    {
        swap(a[bg + gap], a[(--ed) + gap]);
        topDown(a, bg, gap, ed);
    }
}

template<typename Comparable>
void heapSort(Comparable a[], int left, int rightp1)
{
    if(a == NULL || left < 0 || (left + 1) >= rightp1)
        return;
    heapify_max(a, left, rightp1) ;
    heapSort2(a, left, rightp1);
}
