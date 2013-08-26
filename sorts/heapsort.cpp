#include<algorithm>
template<typename Comparable>
void heapify_max(Comparable a[], int begin, int end)
{
    int gap = begin - 1;
    int bg = begin - gap;
    int ed = end - 1 - gap;
    int father, leftchild, biggest;
    for(int i = ed / 2; i >= bg; i--)
    {
        biggest = father = i + gap;
        leftchild = i * 2 + gap;
        if(a[father] < a[leftchild])
            biggest = leftchild;
        if((leftchild + 1) < end && a[father] < a[leftchild + 1])
            biggest = leftchild + 1;

        if(biggest != father)
            swap(a[father], a[biggest]);
    }
}

template<typename Comparable>
void heapSort2(Comparable a[], int begin, int end)
{
    int gap = begin - 1;
    int bg = begin - gap;
    int ed = end - 1 - gap;
    int next, left, right;
    for(; ed >= bg; )
    {
        swap(a[1 + gap], a[(ed--) + gap]);
        next = bg;
        while(true)
        {
            left = next * 2;
            right = left + 1;
            if(left <= ed && a[next + gap] < a[left + gap])
                next = left;
            if(right <= ed && a[next + gap] < a[right + gap])
                next = right;

            if(next == left / 2)
                break;

            swap(a[next + gap], a[left / 2 + gap]);
        }
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
