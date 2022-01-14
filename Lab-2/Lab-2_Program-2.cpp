#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int step = 0;

#define MAX 10000000

bool a[MAX] = {0};

vector<int> primes;

void calculate_primes() {

        a[0] = 1;
        a[1] = 1;

        for(long long int i=2;i<MAX;i++) {

                if(a[i]==0) {
                        primes.push_back(i);

                        for(long long int j=i*i;j<MAX;j+=i) {
                                a[j] = 1;
                        }
                }
        }

}

int calculate_gcd(int a, int b) {

        int m = min(a,b);

        int answer = 0;

        for(int i=0;i<primes.size() && primes[i]<=m;i++) {

                step++;

                if(a%primes[i]==0 && b%primes[i]==0) {
                        answer = primes[i];
                }
        }

        for(int i=answer;i<=m;i++) {

                step++;

                if(a%i==0 && b%i==0) {
                        answer = i;
                }
        }

        return answer;
}

int main() {

        calculate_primes();

        int n1, n2;
        cin >> n1 >> n2;

        int result = calculate_gcd(n1,n2);

        cout << result << endl;

        cout << "Total steps taken : " << step << endl;

        return 0;
}
