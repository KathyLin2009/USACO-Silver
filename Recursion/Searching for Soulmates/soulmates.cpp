#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)

using namespace std;
using ll = long long;

const int N = 11;
int n;
pair<ll,ll> p[N];

int make_to(ll a, ll b) {
    if (a == 0) { //base cases of 0 so __builtin_clzll isnt returning undefined (https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html)
        if (b == 0) return 0;
        return __builtin_popcountll(b)+63-__builtin_clzll(b); //if a is 0 but b isn't, then just take the amount of 1bits in b +63 and subtract the leading zeroes in b
    }
    if (b < a) return 1e9; //
    int mv = __builtin_clzll(a)-__builtin_clzll(b); //leading zeros in a - b, this is using the knowledge that a is greater than b. 
    ll ret = 1e9;
    for (int k = 0; k <= mv; k++) {  //iterate through leading 0s for potential multiplication or div operations?
        if ((b>>k) >= a) {
            ret = min(ret,
                (b>>k)-a+k+__builtin_popcountll(b)-__builtin_popcountll((b>>k)<<k) //b removed with k bits at end - new a + k which is the iterator of bits + amount of 1 bits in b - b removed with k bits and k 0bits added to the end
            );
        }
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> p[i].first >> p[i].second; //read in test cases? not sure why its done like this instead of case by case with cin but ok
    for (int i=1; i<=n; i++) {
        int answer = 1e9; //starting off at maxint
        for (int carry = 0; p[i].first >= 1; carry++, p[i].first >>= 1) { //iterate through bits of var A (right to left)
            answer = min(answer,make_to(p[i].first,p[i].second)+carry); //calls make_to to get the minimum answer
            if (p[i].first == 1) break; //after 1 no operations regarding bits need to be done
            if (p[i].first&1) p[i].first++, carry++; //if the new A isn't even then add by 1 and increase carry by 1 too?
        }
        cout << answer << endl;
    }
}