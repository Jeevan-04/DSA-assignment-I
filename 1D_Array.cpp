#include<iostream>
using namespace std;
const int MAX=5;

class Array
{
    private:
        int arr[MAX];
    public:
        void insert (int pos, int num);
        void del (int pos);
        void reverse ();
        void display ();
        void search (int num);
};

//inserts an element num at given position pos
void Array::insert (int pos, int num)
{
    int i;
    //shift elements to right
    for (i=MAX-1;i>=pos;i--)
        arr[i]=arr[i-1];
    arr[i]=num;
}

//delete an element fro the given position pos
void Array::del (int pos)
{
    int i;
    //skip to the desired position
    for (i=pos;i<MAX;i++)
        arr[i-1]=arr[i];
    arr[i-1]=0;
}

//reverses the entire array
void Array::reverse ()
{
    for (int i=0;i<MAX/2;i++)
    {
        int PTR=arr[i];
        arr[i]=arr[MAX-1-i];
        arr[MAX-1-i]=PTR;
    }
}

//searches array for a given element num
void Array::search (int num)
{
    int i;
    for (i=0;i<MAX;i++)
    {
        if (arr[i]==num)
        {
            cout<<endl<<"Element "<<num<<" is at "<<(i+1)<<"th position";
            return;
        }
    }
    if (i==MAX)
    {
        cout<<endl<<"Element "<<num<<" is absent";
    }
}

//displays the contents of an array
void Array::display ()
{
    cout<<endl;
    for(int i=0;i<MAX;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    Array a;
    int n;
    cout<<"Enter the no.of elements : ";
    cin>>n;    
    for(int i=0;i<n;i++)
    {
        int j;
        cout<<"Enter the "<<j<<" element: ";
        a.insert(i+1,j);
    }
    return 0;
}