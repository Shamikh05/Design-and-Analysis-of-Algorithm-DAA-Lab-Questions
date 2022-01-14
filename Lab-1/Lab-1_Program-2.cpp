#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 100000

int main() {

        vector<int> v;
        int counter[N] = {0};

        int n;
        cout << "Enter the size of array : ";
        cin >> n;

        cout << "Enter the elements of the array : " << endl;
        for(int i=0;i<n;i++) {
                int num;
                cin >> num;
                v.push_back(num);
                counter[num]++;
        }

        int ans1 = 0;
        int ans2 = 0;
        int max = 0;

        for(int i=0;i<N;i++) {

                if(counter[i]>=2) {
                        ans1 += counter[i];
                }

                if(counter[i] > max) {
                        ans2 = i;
                        max = counter[i];
                }
        }

        cout << "\nTotal number of duplicate elements in the array is : " << ans1 << endl;
        cout << "\nMost repeating element in the array is : " << ans2 << endl;

        return 0;
}
