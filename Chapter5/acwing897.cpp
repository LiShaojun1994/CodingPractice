
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1010;

int n,m;
string a;
string b;
int f[N][N];

int main(){
    cin >> n >> m;
    cin >> a;
    cin >> b;
    a = " " + a;
    b = " " + b;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            f[i][j] = max(f[i-1][j],f[i][j-1]);
            if (a[i] == b[j]) f[i][j] = max(f[i][j],f[i-1][j-1]+1);
        }
    }
    printf("%d\n",f[n][m]);
    return 0;
}