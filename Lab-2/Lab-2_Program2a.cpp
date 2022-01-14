#include <iostream>
using namespace std;

int step = 0;

int calc_gcd(int a, int b) {

        step++;

        if(b==0) {
                step++;
                return a;
        }
        return calc_gcd(b,a % b);
}

int main() {

        int n1, n2;
        cin >> n1 >> n2;

        int result = calc_gcd(n1,n2);

        cout << result << endl;

        cout << "Total steps taken : " << step << endl;

        return 0;
}
