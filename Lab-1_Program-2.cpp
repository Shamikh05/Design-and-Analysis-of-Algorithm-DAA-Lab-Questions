#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

        vector<int> v;
        map<int, int> m;

        int n;
        cout << "Enter the size of array : ";
        cin >> n;

        cout << "Enter the elements of the array : " << endl;
        for(int i=0;i<n;i++) {
                int num;
                cin >> num;
                v.push_back(num);
                m.insert(pair<int,int>(v[i], 1));
        }

        for(int i=0;i<n;i++) {
                if(m.find(v[i]) != m.end()) {
                        m[v[i]]++;
                }
        }

        for (auto it = m.begin(); it != m.end(); ++it) {
                if(it->second>1) {
                        cout << it->first<< " appeared "<< it->second << " times" << endl;
                }
        }


        return 0;
}
