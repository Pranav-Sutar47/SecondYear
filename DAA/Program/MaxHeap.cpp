#include <iostream>
using namespace std;

class Heap
{
    int a[10];

    int end;

public:
    int size;
    void insert()
    {
        for(int i=0;i<10;i++)
            a[i]=0;
        cout << "\nEnter size of array:";
        cin >> size;
        // cout<<size;
        for (int i = 1; i < size; i++)
        {
            cout << "\nEnter " << i << " element:";
            cin >> a[i];
            heap(i, a[i]);
        }
    }

    void heap(int index, int value)
    {
        int parent = index / 2;
        cout<<parent;
        while (parent >= 1)
        {
            // cout<<"hello";
            if (a[index] > a[parent])
            {
                int temp = a[parent];
                a[parent] = a[index];
                a[index] = temp;
                index = parent;
            }
            else
            {
                break;
            }
            parent = index / 2;
            // cout<<index;
        }
        show();
        end = size;
    }

    void show()
    {
        cout << "\nThe array is:\n";
        for (int i = 1; i < size; i++)
            cout << a[i] << "\t";
        cout << "\n";
    }

    void deleteElement()
    {
        end--;

        int parent = 1;
        int temp = a[parent];
        a[parent] = a[end];
        a[end] = temp;

        while (parent <= end)
        {
            int lchild = parent * 2;
            int rchild = (parent * 2) + 1;
            if (lchild < end && rchild < end)
            {
                int l;
                if (a[lchild] > a[rchild])
                    l = lchild;
                else
                    l = rchild;
                if (a[parent] < a[l])
                {
                    int t = a[parent];
                    a[parent] = a[l];
                    a[l] = t;
                    parent = l;
                }
            }
            else{
                if(lchild<end){
                    if(a[lchild] > a[parent]){
                        int t = a[parent];
                        a[parent] = a[lchild];
                        a[lchild] = t;
                        parent = lchild;
                        break;
                    }
                }
                else
                    break;
            }
        }
        for(int i=1;i<end;i++)
            cout << a[i] << "\t";
        cout<<"\n";
    }

};

int main()
{
    // Heap h;
    // h.insert();
    // h.show();
    // h.deleteElement();
    //h.deleteElement();
    int ch;
    do{
        cout<<"\n1. For Creating Heap";
        cout<<"\n2. For Deleting Element in Heap";
        cout<<"\n3. For Heap Sort";
        cout<<"\n4. Heap";
        cout<<"\n5. Exit";
        cout<<"\nChoose any one operation:";
        cin>>ch;
        Heap h;
        switch(ch){
            case 1: h.insert();
                    break;
            case 2: h.deleteElement();
                    break;
            case 3: for(int i=1;i<h.size-1;i++)
                        h.deleteElement();
                    h.show();
                    break;
            case 4: h.show();
                    break;
            case 5: break;
            default: cout<<"\nInvalid Choice";
        }
    }while(ch!=5);
   
   
}