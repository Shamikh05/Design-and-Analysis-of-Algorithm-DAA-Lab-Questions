#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int &x, int &y) {
        int temp;
        temp = x;
        x = y;
        y = temp;
}

int main() {

        int a, b, c;

        cout << "Enter the values of a, b and c : " << endl;
        cin >> a >> b >> c;

        swap(a,b);
        swap(b,c);
        swap(c,a);

        cout << "After all the three swapping : "<< endl;
        cout << "Value of a : " << a << endl;
        cout << "Value of b : " << b << endl;
        cout << "Value of c : " << c << endl;

        return 0;
}
