#include <iostream>
using namespace std;

float calc_square_root(int n) {

        if(n==0 || n==1) {
                return n;
        }

        int result = 0;

        for(int i=2;i*i<=n;i++) {
                result = i;
        }

        return result;
}

int main() {

        int n;
        cin >> n;

        int result = calc_square_root(n);

        cout << "Sqare root of " << n << " is : " << result << endl;

        return 0;
}
