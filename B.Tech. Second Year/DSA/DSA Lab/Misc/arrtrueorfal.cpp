#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    i = 0;
    while (i < (n - 1))
    {
        if (arr[i] == 0)
        {
            cout << "False" << endl;
            exit(0);
        }
        else
        {
           i++;
        }
    }
    cout<<"True"<<endl;
    return 0;
}