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
void heapify_max(Comparable a[], int begin, int end)
{
    int gap = begin - 1;
    int bg = begin - gap;
    int ed = end - gap;
    int next, left, right;
    for(int i = ed / 2; i >= bg; i--)
    {
        topDown(a, i, gap, ed);
    }

}

template<typename Comparable>
void heapSort2(Comparable a[], int begin, int end)
{
    int gap = begin - 1;
    int bg = begin - gap;
    int ed = end - gap;
    int next, left, right;
    for(; ed > bg; )
    {
        swap(a[bg + gap], a[(--ed) + gap]);
        topDown(a, bg, gap, ed);
    }
}

template<typename Comparable>
void heapSort(Comparable a[], int begin, int end)
{
    if(a == NULL || begin < 0 || (begin + 1) >= end)
        return;
    heapify_max(a, begin, end) ;
    heapSort2(a, begin, end);
}
