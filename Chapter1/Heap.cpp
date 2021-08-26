#include <iostream>
#include <algorithm>
/*
 * 操作：
 * 1.插入一个数           heap[++Size] = x;up(Size);
 * 2.求集合当中的最小值     heap[1];
 * 3.删除最小值           heap[1] = heap[Size];Size--;down(1);
 * 4.删除任意一个元素      heap[k] = heap[Size];Size--;down(k);up(k);
 * 5.修改任意一个元素      heap[k] = x;down(k);up(k);
 * 性质：
 * 堆是一个完全二叉树，除了最后一层，每一层都是满的，最后一层是从左到右排列
 * 小根堆:父节点比左右子节点都小
 *
 * 存储方式：
 * down(x)---->往下调整
 *
 * up(x)------>往上调整
 *
 *
输入一个长度为 n 的整数数列，从小到大输出前 m 小的数。
输入格式
第一行包含整数 n 和 m。
第二行包含 n 个整数，表示整数数列。
输出格式
共一行，包含 m 个整数，表示整数数列中前 m 小的数。
数据范围
1≤m≤n≤105，
1≤数列中元素≤109
输入样例：
5 3
4 5 1 3 2
输出样例：
1 2 3
 */
using namespace std;
const int N = 100010;
int Heap[N], Size;
int num;
int pH[N];
int Hp[N];

//void down(int u) {
//    int t = u;
//    if (u * 2 <= Size && Heap[u * 2] < Heap[t]) {
//        t = u * 2;
//    }
//    if (u * 2 + 1 <= Size && Heap[u * 2 + 1] < Heap[t]) {
//        t = u * 2 + 1;
//    }
//    if (t != u) {
//        swap(Heap[t], Heap[u]);
//        down(t);
//    }
//}
void Heap_swap(int a, int b)
{
    swap(pH[Hp[a]],pH[Hp[b]]);
    swap(Hp[a], Hp[b]);
    swap(Heap[a], Heap[b]);
}
void down(int u) {
    int t = u;
    if (u * 2 <= Size && Heap[u * 2] < Heap[t]) {
        t = u * 2;
    }
    if (u * 2 + 1 <= Size && Heap[u * 2 + 1] < Heap[t]) {
        t = u * 2 + 1;
    }
    if (t != u) {
        Heap_swap(u,t);
        down(t);
    }
}

void up(int u) {
    while (u / 2 && Heap[u / 2] > Heap[u]) {
        swap(Heap[u / 2], Heap[u]);
        u = u / 2;
    }
}

void Delete(int u) {
    Heap[u] = Heap[Size];
    Size--;
    down(u);
    up(u);
}

void Modify(int u, int x) {
    Heap[u] = x;
    down(u);
    up(u);
}

void insert(int x) {
    Heap[++Size] = x;
    up(Size);
}

// 输入一个数列，生成堆，输出前m个最小值
//int main(){
//    int n,m;
//    scanf("%d%d",&n,&m);
//    Size = n;
//    for (int i = 1; i <= n; ++i) {
//        scanf("%d",&Heap[i]);
//    }
//    for (int i = n/2; i; i--) {
//        down(i);
//    }
//    while (m--){
//        printf("%d ",Heap[1]);
//        Heap[1] = Heap[Size];
//        Size--;
//        down(1);
//    }
//    return 0;
//}
// 维护一个集合，初始时集合为空，支持如下几种操作：
//
//I x，插入一个数 x；
//PM，输出当前集合中的最小值；
//DM，删除当前集合中的最小值（数据保证此时的最小值唯一）；
//D k，删除第 k 个插入的数；
//C k x，修改第 k 个插入的数，将其变为 x；
//现在要进行 N 次操作，对于所有第 2 个操作，输出当前集合的最小值。
//
//输入格式
//第一行包含整数 N。
//
//接下来 N 行，每行包含一个操作指令，操作指令为 I x，PM，DM，D k 或 C k x 中的一种。
//
//输出格式
//对于每个输出指令 PM，输出一个结果，表示当前集合中的最小值。
//
//每个结果占一行。
#include <string.h>
int main()
{
    int n, m = 0;
    scanf("%d", &n);
    while (n -- )
    {
        char op[5];
        int k, x;
        scanf("%s", op);
        if (!strcmp(op, "I"))
        {
            scanf("%d", &x);
            Size ++ ;
            m ++ ;
            pH[m] = Size, Hp[Size] = m;
            Heap[Size] = x;
            up(Size);
        }
        else if (!strcmp(op, "PM")) printf("%d\n", Heap[1]);
        else if (!strcmp(op, "DM"))
        {
            Heap_swap(1, Size);
            Size -- ;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            scanf("%d", &k);
            k = pH[k];
            Heap_swap(k, Size);
            Size -- ;
            up(k);
            down(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = pH[k];
            Heap[k] = x;
            up(k);
            down(k);
        }
    }

    return 0;
}
