#include <iostream>
using namespace std;

int main() {

        int n;
        cout << "Enter the size of array : ";
        cin >> n;

        int a[n];

        for(int i=0;i<n;i++) {

                int no;
                cin >> no;

                if(i % 2 != 0) {
                        a[i] = a[i-1];
                        a[i-1] = no;
                }
                else {
                        a[i] = no;
                }
        }

        for(int i=0;i<n;i++) {
                cout << a[i] << " ";
        }

        return 0;
}
