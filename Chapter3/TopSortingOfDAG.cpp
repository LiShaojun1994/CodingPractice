/*
 * 有向图才有拓扑序列
 * 每条边起点都在终点前面
 * 有向无环图一定存在拓扑序列
 * 有向无环图也称为拓扑图
 * 有向图:
 * 1->2 2->3 1->3
 * 入度：
 * 边指向自己的数量
 * 出度：
 * 从自己出发的边
 * 入度为0的点可以作为起点
 *
 * 解题：
 * 1.入度为0入队
 * 2.BFS:
 *      queue <-- 入度为0入队
 *      while queue不空
 *      {
 *          t <-- 队头
 *          枚举 t 的所有出边 t-->j
 *          删除t --> j d[j] --
 *          if d[j] == 0{
 *              queue <-- j
 *          }
 *      }
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;


int n,m;
int h[N],e[N],ne[N],idx;
int q[N],d[N];
void add(int a,int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool topsort(){
    int hh = 0,tt=-1;
    for (int i = 1; i <= n; ++i) {
        if (!d[i]){
            q[++tt] = i;
        }
    }
    while (hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; i != -1 ; i = ne[i]) {
            int j = e[i];
            d[j]--;
            if (d[j] == 0){
                q[++tt] = j;
            }
        }
    }
    return tt == n-1;
}
int main(){
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        add(a,b);
        d[b]++;
    }
    if (topsort()){
        for (int i = 0; i < n; ++i) {
            cout << q[i] << " ";
        }
    } else{
        cout << "-1" <<endl;
    }
    return 0;
}

