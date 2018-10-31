#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <set>
#include <map>
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>

using namespace std;
#define ll long long

const int me = 100025;

long long N;

int main() {

    for(N=(1000); N<=(10000); N++){
        // cin >> N;
        int ok = 0;
        for(int i = 1; 1LL * i * i <= N; i ++){
            long long other = N - 1LL * i * i;
            long long root = (long long)sqrt(1. * other);
            if(root * root == other){
                ok = 1;
                break;
            }
        }
        // if(ok)
            // cout << "Yes" << endl;
        // else cout << "No" << endl;

        ll n=N;
        // cin >> n;
        ll rootn = (ll)sqrt(1.*n);
        ll n1=-1, n2=-1;
        bool found = false;
        for(int i=0; i<=rootn; i++)
        {
            ll l=i, r=rootn, mid;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(i*i+mid*mid<n)
                    l = mid+1;
                else if(i*i+mid*mid>n)
                    r = mid-1;
                else
                {
                    n1 = i;
                    n2 = mid;
                    found=true;
                    break;
                }
                // trace(l, r, mid, rootn);
            }
            if(found)
                break;

            // trace(i, mid, rootn);
        }
        // trace(n1, n2);
        // if(n1!=-1)
        // {
            // cout << n1 <<" "<< n2 << '\n';
            // cout<<"Yes\n";
        // }
        // else
            // cout<<"No\n";
        if(ok!=found)
        {
            cout << N <<'\n';
            // return 0;
        }
    }
    
    return 0;
}