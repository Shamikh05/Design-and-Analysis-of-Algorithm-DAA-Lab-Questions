#include <iostream>
using namespace std;

long long int step = 0;

int max_subarr_sum(int arr[], int n) {

        int max = 0;

        for(int i=0;i<n;i++) {

                int sum = 0;

                for(int j=i;j<n;j++) {

                        step++;

                        sum += arr[j];

                        if(sum > max) {
                                max = sum;
                        }

                }
        }

        return max;
}

int main() {

        int n;
        cin >> n;

        int a[n];

        for(int i=0;i<n;i++) {
                a[i] = rand() % 100000;
        }

        cout << "The entered array is : " << endl;

        for(int i=0;i<n;i++) {
                cout << a[i] << " ";
        }
        cout << endl;

        int max = max_subarr_sum(a,n);

        cout << "Maximum sub array sum is : " << max << endl;

        cout << "Total number of steps taken : " << step << endl;

        return 0;
}
