#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int N = 510;
    int num;
    std::cin >> num;
    std::vector<std::vector<int>> a(N,std::vector<int>(N,0));
    std::vector<std::vector<int>> f(N,std::vector<int>(N,0));
    for (int i = 1; i <= num; ++i) {
        for (int j = 1; j <= i; ++j) {
            // 输入
            std::cin >> a[i][j];
        }
    }
    // 初始化dp
    for (int i = 0; i <= num; ++i) {
        for (int j = 0; j <= i + 1; ++j) {
            f[i][j] = -1e9;
        }
    }
    f[1][1] = a[1][1];
    for (int i = 2; i <= num; ++i) {
        for (int j = 1; j <= i; ++j) {
            f[i][j] = std::max(f[i-1][j-1] + a[i][j],f[i-1][j]+a[i][j]);
        }
    }
    int res = -1e9;
    for (int i = 1; i <=num ; ++i) {
        res = std::max(f[num][i],res);
    }
    std::cout << res << std::endl;
    return 0;
}