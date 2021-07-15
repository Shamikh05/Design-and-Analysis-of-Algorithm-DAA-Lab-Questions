#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

        vector<int> v;
        queue<int> q;

        int n;
        cout << "Enter the size of array : ";
        cin >> n;

        cout << "Enter the elements of the array : " << endl;
        for(int i=0;i<n;i++) {
                int num;
                cin >> num;
                v.push_back(num);
        }

        for(int i=0;i<n;i++) {

                if(v[i]%2!=0) {
                        q.push(v[i]);
                        v.erase(v.begin()+i);
                }
        }

        while(!q.empty()) {
                v.push_back(q.front());
                q.pop();
        }

        for(auto it : v) {
                cout << it << " ";
        }

        return 0;
}
