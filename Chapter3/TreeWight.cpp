#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010 ,M = N * 2;
int h[N],e[M],ne[M],idx;
bool st[N];
int ans = N;
int n ;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
// 返回以U为根的子树中的点的数量
int dfs(int u){
    st[u] = true; // 标记，已经搜索过
    // 当前以U为根的子树总数初始化为1
    // 连通块最大值为res = 0
    int sum = 1, res = 0;
    // 遍历去找所有子树的节点数，每个子树都是一个连通块，所有要max()计算最大连通块的大小
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            // 递归思想，算出u的以j为根的子树的数量，为1个连通块
            int s = dfs(j);
            // 计算向下的子连通块的最大值
            res = max(res,s);
            // 计算以u为根的数量的节点数
            sum += s;
        }
    }
    // 计算向上的那一部分是否为最多连通块
    res = max(res,n-sum);
    // 计算完成后，计算最大连通块数量的最小值
    ans = min(ans,res);
    return sum;
}




int main(){
    cin >> n;
    memset(h,-1,sizeof h);
    for (int i = 0; i < n-1; ++i) {
        int a,b;
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    dfs(1);
    cout << ans <<endl;
}