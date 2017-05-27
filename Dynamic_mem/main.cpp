#include <iostream>

using namespace std;


void fun(int ** arr)
{
    arr[0][0] = 1;
    arr[0][1] = 2;
    cout<<arr[0][0]<<endl;

}

int main()
{
    int ** arr;
    int m,n;
    cin>>m>>n;
    arr = new int * [m];
    for(int i=0;i<m;++i)arr[i] = new int[n];

    fun(arr2);

    return 0;
}
