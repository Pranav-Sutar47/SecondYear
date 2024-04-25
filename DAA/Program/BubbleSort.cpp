#include<iostream>
using namespace std;

class BubbleSort{

    int a[10];
    int size;

    public:
        void bubbleSort(){
            for(int i=0;i<size-1;i++){
                for(int j=i+1;j<size;j++){
                    if(a[i]>a[j]){
                        int temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
                    }
                }
            }
        }

        void set(){
            cout<<"\nEnter size of array:";
            cin>>size;
            for(int i=0;i<size;i++){
                cout<<"\nEnter "<<i+1<<" element:";
                cin>>a[i];
            }
        }

        void get(){
            cout<<"\nArray is:"<<endl;
            for(int i=0;i<size;i++)
                cout<<a[i]<<"\t";
        }

};

int main(){
    BubbleSort b;
    b.set();
    b.get();
    b.bubbleSort();
    b.get();
}