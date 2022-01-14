#include <iostream>
using namespace std;

long long int step = 0;

int calc_square_root(int n) {

        if(n==0 || n==1) {
                step++;
                return n;
        }

        int result = 0;

        for(int i=2;i*i<=n;i++) {
                step++;
                result = i;
        }

        return result;
}

int main() {

        int n;
        cin >> n;

        int result = calc_square_root(n);

        cout << "Sqare root of " << n << " is : " << result << endl;

        cout << "Total number of steps taken : " << step << endl;

        return 0;
}
