/*
 * f[i][j] = max(f[i-1][j],f[i][j-k*v[i]] + k * w[i]) k = 1,2,3,...,s[i]
 */

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 25000,M = 2000;
int n, m;
int v[N],w[N];
int f[N];
#ifdef NORMAL
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i] >> s[i];
    }
    for (int i = 1; i <= n ; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <=s[i] && k*v[i] <= j; ++k) {
                f[i][j] = max(f[i-1][j],f[i][j-k*v[i]] + k * w[i]);
            }
        }
    }
    cout << f[n][m] <<endl;
    return 0;
}
#endif
int main(){
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <=n ; ++i) {
        int a ,b,s;
        cin >> a >> b >> s;
        int k = 1;
        while (k <= s){
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s-=k;
            k *= 2;
        }
        if (s>0){
            cnt++;
            v[cnt] = s*a;
            w[cnt] = s*b;
        }
    }
    n = cnt;
    for (int i = 1; i <=n ; ++i) {
        for (int j = m; j >= v[i] ; --j) {
            f[j] = max(f[j],f[j-v[i]] + w[i]);
        }
    }
    cout << f[m] <<endl;
    return 0;
}