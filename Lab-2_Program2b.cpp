#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int step = 0;

int calc_gcd(int a, int b) {

        int m = min(a,b);

        for(int i=m;i>1;i--) {

                step++;

                if(a%i==0 && b%i==0) {
                        return i;
                }
        }
}

int main() {

        int n1, n2;
        cin >> n1 >> n2;

        int result = calc_gcd(n1,n2);

        cout << result << endl;

        cout << "Total steps taken : " << step << endl;
}
