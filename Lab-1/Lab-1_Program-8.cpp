#include <iostream>
using namespace std;

int main() {

        int n;
        cout << "Enter the size of array : ";
        cin >> n;

        int a[n];

        cout << "Enter the elements of the array : " << endl;

        int prod = 1;

        for(int i=0;i<n;i++) {
                cin >> a[i];
                prod *= a[i];
        }

        for(int i=0;i<n;i++) {
                cout << prod/a[i] << " ";
        }

        return 0;

}
