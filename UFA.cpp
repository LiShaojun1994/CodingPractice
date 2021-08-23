// 优化方法：路径压缩
// 找到父节点就直接将所有的节点指向父节点
/*
 * 一共有 n 个数，编号是 1∼n，最开始每个数各自在一个集合中。
现在要进行 m 个操作，操作共有两种：
M a b，将编号为 a 和 b 的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
Q a b，询问编号为 a 和 b 的两个数是否在同一个集合中；
输入格式
第一行输入整数 n 和 m。
接下来 m 行，每行包含一个操作指令，指令为 M a b 或 Q a b 中的一种。
输出格式
对于每个询问指令 Q a b，都要输出一个结果，如果 a 和 b 在同一集合内，则输出 Yes，否则输出 No。
每个结果占一行。
数据范围
1≤n,m≤105
输入样例：
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
输出样例：
Yes
No
Yes
 */
/*
 * 并查集：
 * 1.将两个集合合并；
 * 2.询问两个元素是否在一个集合当中
 * 基本原理：
 * 每个集合用一颗树来表示，树根的编号就是整个集合的编号，每个节点存储它的父节点，p[x]表示x的父节点
 *
 * 问题1：如何判断树根：if(p[x] == x) 这就是树根
 * 问题2：如何求x的集合编号：while(p[x]!=x) x = p[x] if(p[x]!=x) p[x] = find(x);
 * 问题3：如何合并两个集合：p[x]是x的集合编号，p[y]是y的集合编号，p[x] = y
 */
#include <iostream>
#include <vector>
using namespace std;
const int N = 100010;
int n,m;
int p[N];
// 返回x所在集合的编号 + 路径压缩
int find(int x){
    if (p[x]!=x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }

    while(m--){
        char op[2];
        int a, b;
        scanf("%s%d%d",op,&a,&b);
        if (op[0] == 'M') p[find(a)] = find(b);
        else {
            if (find(a) == find(b)) printf("Yes\n");
            else printf("No\n");
        }

    }

    return 0;
}