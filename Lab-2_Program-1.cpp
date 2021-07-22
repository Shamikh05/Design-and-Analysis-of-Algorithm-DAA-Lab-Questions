#include <iostream>
using namespace std;

void prime_algo1(int n) {

        int step = 0;
        bool check = 0;
        for(int i=2;i<n;i++) {
                step++;
                if(n%i==0) {
                        check = 1;
                        break;
                }
        }
        if(check) {
                cout << "It is not a prime number!!" << endl;
        }
        else {
                cout << "It is a prime number!!" << endl;
        }

        cout << "Total steps taken : " << step << endl;
}

void prime_algo2(int n) {

        int step = 0;
        bool check = 0;
        for(int i=2;i<=n/2;i++) {
                step++;
                if(n%i==0) {
                        check = 1;
                        break;
                }
        }
        if(check) {
                cout << "It is not a prime number!!" << endl;
        }
        else {
                cout << "It is a prime number!!" << endl;
        }

        cout << "Total steps taken : " << step << endl;
}

void prime_algo3(int n) {

        int step = 0;
        bool check = 0;
        for(int i=2;i*i<=n;i++) {
                step++;
                if(n%i==0) {
                        check = 1;
                        break;
                }
        }
        if(check) {
                cout << "It is not a prime number!!" << endl;
        }
        else {
                cout << "It is a prime number!!" << endl;
        }

        cout << "Total steps taken : " << step << endl;
}

int main() {

        int count = 0;

        int n;
        cout << "Enter the number : ";
        cin >> n;

        cout << "By 1st Algorithm [O(n)] : " << endl;
        prime_algo1(n);

        cout << "By 1st Algorithm [O(n/2)] : " << endl;
        prime_algo2(n);

        cout << "By 1st Algorithm [O(sqrt(n))] : " << endl;
        prime_algo3(n);


        cout << count << endl;
        return 0;
}
