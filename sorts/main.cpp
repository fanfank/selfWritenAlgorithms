#include "main.h"
int main()
{
    int a[1000];
    int b[1000];
    int n;
    for(int i = 19; i >= 0; i--)
        a[19 - i] = i;

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


        cout<<"sorting algorithm do you want(0ss, 1is, 2bs, 3hs, 4ms, 5qs):";
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
            case 4:
                mergeSort(b, begin, end);
                break;
            case 5:
                quickSort(b, begin, end);
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
