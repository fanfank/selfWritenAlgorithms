#include "main.h"
int c[1000] = {
    -1, 2, 9, -2, -1, 12, 0, 13, 10, 1, 2, 1, -1, 2, 8, 11, 15, -13, 7, 5
};

template<typename Comparable>
void printArr(Comparable a[], int left, int rightp1)
{
    if(a == NULL || left < 0 || (left + 1) >= rightp1)
        return;
    for(int i = left; i < rightp1; i++)
        cout<<" "<<a[i];
    cout<<endl;
}

void testSortSpeed(int algor = 0)
{
    
}

template<typename T, typename R>
void testTemplate(R (*func)(T*, int, int))
{
    int aa[3] = {0,3,1};
    func(aa, 0, 3);
    printArr(aa, 0, 3);
}

template<typename T, typename R, R (*func)(T*, int, int) >
void autoTest(int len)
{
    cout<<"Every dot \".\" means 50 test cases"<<endl;
    time_t bg_time,ed_time;
    bg_time = time(NULL);
    int cnt = 10000;
    int *arr1 = new int[len];
    int *arr2 = new int[len];
    while(cnt--)
    {
        if(cnt % 50 == 0)
        {
            cout<<".";
            fflush(stdout);
        }
        for(int i = 0; i < len; i++)
            arr1[i] = arr2[i] = ((int)rand()) % MAX;
        func(arr1, 0, len);
        sort(arr2, arr2 + len);
        for(int i = 0; i < len; i++)
            if(arr1[i] != arr2[i])
            {
                cout<<"Wrong number, cnt is: "<<cnt<<endl;
                cout<<"arr1:"; printArr(arr1, 0, len);
                cout<<"arr2:"; printArr(arr2, 0, len);
                delete []arr1;
                cout<<endl;
                delete []arr2;
                return;
            }

    }
    ed_time = time(NULL) ;
    cout<<endl;
    cout<<"Cost "<<ed_time - bg_time<<" seconds"<<endl;
    delete []arr1;
    delete []arr2;
}
int main()
{
    srand(time(0));
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
        //testTemplate<int, void>(selectionSort);
        if(n <= 0)
        {
            //n = lastn;
        }
        else
            lastn = n;

        cout<<"Which sorting algorithm do you want(0ss, 1is, 2bs, 3hs, 4ms, 5qs, 6ssV2, 7msV2, 8qsV2, 9msV3, 10qsV3):";
        cin>>s;

        char amc;
        bool am = false;
        cout<<"Automatic testing 10000 random data?(y/n):";
        cin>>amc;
        if(amc == 'y')
            am = true;

        if(!am)
        {
            if(n > 0)
            for(int i = 0; i < lastn; i++)
                cin>>a[i];
            else
                n = lastn;

            for(int i = 0; i < lastn; i++)
                b[i] = a[i];

            cout<<"Before sorting:"<<endl;
            for(int i = 0; i < lastn; i++)
                cout<<b[i]<<" ";
            cout<<endl;

            cout<<"where to begin:"; cin>>begin;
            cout<<"where is end+1:"; cin>>end;
            if(end > lastn)
                end = lastn;
        }

        switch(s)
        {
            case 0:
                if(am)
                    autoTest<int, void, selectionSort >(n);
                else
                selectionSort(b, begin, end);
                break;
            case 1:
                if(am)
                    autoTest<int, void, insertionSort >(n);
                else
                insertionSort(b, begin, end);
                break;
            case 2:
                if(am)
                    autoTest<int, void, bubbleSort >(n);
                else
                bubbleSort(b, begin, end);
                break;
            case 3:
                if(am)
                    autoTest<int, void, heapSort >(n);
                else
                heapSort(b, begin, end);
                break;
            case 4:
                if(am)
                    autoTest<int, void, mergeSort >(n);
                else
                mergeSort(b, begin, end);
                break;
            case 5:
                if(am)
                    autoTest<int, void, quickSort >(n);
                else
                quickSort(b, begin, end);
                break;
            case 6:
                if(am)
                    autoTest<int, int, _selectionSort >(n);
                else
                _selectionSort(b, begin, end);
                break;
            case 7:
                if(am)
                    autoTest<int, int, _mergeSort >(n);
                else
                _mergeSort(b, begin, end);
                break;
            case 8:
                if(am)
                    autoTest<int, int, _quickSort >(n);
                else
                    _quickSort(b, begin, end);
                break;
            case 9:
                if(am)
                    autoTest<int, int, __mergeSort >(n);
                else
                    __mergeSort(b, begin, end);
                break;
            case 10:
                if(am)
                    autoTest<int, int, __quickSort >(n);
                else
                    __quickSort(b, begin, end);
                break;
            default:
                break;
        }
        if(!am)
        {
            for(int i = 0; i < lastn; i++)
                cout<<b[i]<<" ";
            cout<<endl;
        }

        cout<<"Please input # of array elements:";
    }
}
