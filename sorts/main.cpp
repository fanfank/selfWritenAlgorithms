#include "main.h"
int c[1000] = {
    -1, 2, 9, -2, -1, 12, 0, 13, 10, 1, 2, 1, -1, 2, 8, 11, 15, -13, 7, 5
};
int main()
{
    int a[1000];
    int b[1000];
    int n;
    for(int i = 19; i >= 0; i--)
        a[19 - i] = c[i];

    int s;
    cout<<"Please input # of array elements:";
    int begin, end, lastn = 20;
    while(cin>>n)
    {
        if(n > 0)
        {
            lastn = n;
            for(int i = 0; i < lastn; i++)
                cin>>a[i];
        }

        for(int i = 0; i < lastn; i++)
            b[i] = a[i];

        cout<<"Before sorting:"<<endl;
        for(int i = 0; i < lastn; i++)
            cout<<b[i]<<" ";
        cout<<endl;

        cout<<"Which sorting algorithm do you want(0ss, 1is, 2bs, 3hs, 4ms, 5qs, 6ssV2, 7msV2, 8qsV2):";
        cin>>s;

        cout<<"where to begin:"; cin>>begin;
        cout<<"where is end+1:"; cin>>end;
        if(end > lastn)
            end = lastn;

        switch(s)
        {
            case 0:
                selectionSort(b, begin, end);
                break;
            case 1:
                insertionSort(b, begin, end);
                break;
            case 2:
                bubbleSort(b, begin, end);
                break;
            case 3:
                heapSort(b, begin, end);
                break;
            case 4:
                mergeSort(b, begin, end);
                break;
            case 5:
                quickSort(b, begin, end);
                break;
            case 6:
                _selectionSort(b, begin, end);
                break;
            case 7:
                _mergeSort(b, begin, end);
                break;
            case 8:
                _quickSort(b, begin, end);
                break;
            default:
                break;
        }
        for(int i = 0; i < lastn; i++)
            cout<<b[i]<<" ";
        cout<<endl;

        cout<<"Please input # of array elements:";
    }
}
