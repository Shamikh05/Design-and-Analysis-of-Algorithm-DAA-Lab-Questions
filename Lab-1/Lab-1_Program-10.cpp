#include <iostream>
using namespace std;

int div(int &x) {
        return x/2;
}

void max(int &a, int &b) {

        int calc = ( a + b + abs(a-b) );
        int result = div(calc);
        cout << "Maximum : " << result << endl;
}

int main() {

        int n1, n2;

        cout << "Enter the first number : ";
        cin >> n1;

        cout << "Enter the second number : ";
        cin >> n2;

        max(n1, n2);

        return 0;
}
