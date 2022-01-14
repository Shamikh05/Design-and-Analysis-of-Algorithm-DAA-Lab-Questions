#include <iostream>
using namespace std;

int main() {

        int n;
        cout << "Enter the number n : ";
        cin >> n;

        int res = 0;

        for(int i=1;i*i<=n;i++) {
                res = i;
        }

        cout << res << endl;

        return 0;
}
