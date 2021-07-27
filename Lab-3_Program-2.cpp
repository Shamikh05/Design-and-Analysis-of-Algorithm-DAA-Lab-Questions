#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool test_list_1(list<int> ll,int n) {

        for(auto i=ll.begin();i!=ll.end();++i) {

                int count = 0;
                for(auto j=ll.begin();j!=ll.end();++j) {

                        if(*i==*j) {
                                count++;
                        }
                }

                if(count > (n/2)) {
                        cout << *i << " appeared " << count << " times" << endl;
                        return 1;
                }
        }
        return 0;
}

bool test_list_2(vector<int> &counter,int n) {

        for(int i=0;i<counter.size();i++) {

                if(counter[i] > (n/2)) {
                        cout << i << " appeared " << counter[i] << " times" << endl;
                        return 1;
                }
        }
        return 0;
}

int main() {

        int n;
        cin >> n;

        list<int> l;

        vector<int> counter(1000000,0);

        for(int i=0;i<n;i++) {
                int num;
                cin >> num;
                l.push_back(num);
                counter[num]++;
        }

        cout << "\nIn n^2 time complexity :\n" << endl;

        if(!test_list_1(l,n)) {
                cout << "There is no any number in list which appeared more than n/2 times." << endl;
        }

        cout << "\nIn n time complexity :\n" << endl;

        if(!test_list_2(counter,n)) {
                cout << "There is no any number in list which appeared more than n/2 times." << endl;
        }

        return 0;
}
