/*
ID: f2011501
PROG: transform
LANG: C++
*/

#include<iostream>
#include<fstream>
using namespace std;

void print(char ** arr, int N)
{
    for(int i=0; i<N; ++i)
    {
        cout<<endl;
        for(int j=0; j<N; ++j)
        {
            cout<< arr[i][j]<<" ";
        }
    }cout<<endl;
}

bool match(char ** arr1, char ** arr2, int N)
{
    for(int i=0; i<N; ++i)
    {
        //cout<<endl;
        for(int j=0; j<N; ++j)
        {
            //cout<<arr1[i][j]<<" * "<<arr2[i][j]<<"    ";
            if(arr1[i][j] == arr2[i][j]);
            else return false;
        }
    }

        return true;
}

bool tf1(char ** arr1, char ** arr2, int N)
{
    char ** arr = new char*[N];
    for(int i=0; i<N; ++i)arr[i] = new char[N];

    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
        {
            arr[j][N-1-i] = arr1[i][j];
        }

    return match(arr2,arr,N);
}

bool tf2(char ** arr1, char ** arr2, int N)
{
    char ** arr = new char*[N];
    for(int i=0; i<N; ++i)arr[i] = new char[N];

    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
        {
            arr[N-1-i][N-1-j] = arr1[i][j];
        }
    return match(arr2,arr,N);
}

bool tf3(char ** arr1, char ** arr2, int N)
{
    char ** arr = new char*[N];
    for(int i=0; i<N; ++i)arr[i] = new char[N];

    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
        {
            arr[N-1-j][i] = arr1[i][j];
        }
    return match(arr2,arr,N);
}
bool tf4(char ** arr1, char ** arr2, int N)
{
    char ** arr = new char*[N];
    for(int i=0; i<N; ++i)arr[i] = new char[N];

    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
        {
            arr[i][N-1-j] = arr1[i][j];
        }//print(arr1,N);print(arr2,N);print(arr,N);
    return match(arr2,arr,N);
}

bool tf5(char ** arr1, char ** arr2, int N)
{
    char ** arr = new char*[N];
    for(int i=0; i<N; ++i)arr[i] = new char[N];

    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
        {
            arr[i][N-1-j] = arr1[i][j];
        }
        //another
    char ** arr_t1 = new char*[N];
    char ** arr_t2 = new char*[N];
    char ** arr_t3 = new char*[N];
    for(int i=0; i<N; ++i)
    {
        arr_t1[i] = new char[N];
        arr_t2[i] = new char[N];
        arr_t3[i] = new char[N];
    }

    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
        {
            arr_t1[j][N-1-i] = arr[i][j];
            arr_t2[N-1-i][N-1-j] = arr[i][j];
            arr_t3[N-1-j][i] = arr[i][j];
        }

    return (match(arr2,arr_t1,N) || match(arr2,arr_t2,N) || match(arr2,arr_t3,N));
}

bool tf6(char ** arr1, char ** arr2, int N)
{
    return match(arr1,arr2,N);
}


int main()
{
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    int N;
    fin>>N;
    char ** arr1 = new char*[N];
    char ** arr2 = new char*[N];
    for(int i=0; i<N; ++i)
    {
        arr1[i] = new char[N];
        arr2[i] = new char[N];
    }
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            fin>>arr1[i][j];

    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            fin>>arr2[i][j];


    if(tf1(arr1,arr2,N))fout<<1<<endl;
    else if(tf2(arr1,arr2,N))fout<<2<<endl;
    else if(tf3(arr1,arr2,N))fout<<3<<endl;
    else if(tf4(arr1,arr2,N))fout<<4<<endl;
    else if(tf5(arr1,arr2,N))fout<<5<<endl;
    else if(tf6(arr1,arr2,N))fout<<6<<endl;
    else fout<<7<<endl;

    fin.close();
    fout.close();
    return 0;
}
