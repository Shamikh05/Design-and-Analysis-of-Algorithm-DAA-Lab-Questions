#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

        vector<int> v;

        int n;
        cout << "Enter the size of array : ";
        cin >> n;

        cout << "Enter the elements of the array : " << endl;
        for(int i=0;i<n;i++) {
                int num;
                cin >> num;
                v.push_back(num);
        }

        int min = v[0];
        int max = v[0];

        for(int i=0;i<n;i++) {
                if(v[i] > max) {
                        max = v[i];
                }
                if(v[i] < min) {
                        min = v[i];
                }
        }

        cout << "Maximum number : " << max << endl;
        cout << "Minimum number : " << min << endl;

        return 0;
}
