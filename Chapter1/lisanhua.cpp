//
// Created by 12298 on 2021/8/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> add;
vector<pair<int,int>> query;
vector<int> alls;

// 离散化
// r+1 返回 1，2，3，4，5
int find(int x){
    int l = 0,r = alls.size()-1;
    while (l < r){
        int mid = l + r >> 1;
        if(alls[mid]>=x) {
            r = mid;
        } else{
            l = mid + 1;
        }
    }
    return r+1;
}

int a[300010],S[300010];
int main(){
    int n , m;
    cin >> n >> m;
    // 坐标延申到了x,所以需要将x放入未序列化前的数组
    for (int i = 0; i < n; ++i) {
        int x,a;
        cin >> x >> a;
        add.push_back({x,a});
        alls.push_back(x);
    }
    // 同理 坐标延申到了l和r，放入未序列化前的数组
    for (int i = 0; i < m; ++i) {
        int l,r;
        cin >> l >> r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    // 去重，确定涉及到的坐标值只有哪些，比如 1,2,5,8,10
    // 则映射他们到 1, 2, 3, 4, 5
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    // 将坐标映射到下标，对应元素+a
    for(auto item : add){
        int x = find(item.first);
        a[x] += item.second;
    }
    // 预处理前缀和，其他未涉及到的坐标都为0，因此只需要将涉及到的坐标映射后的处理为前缀和
    for (int i = 1; i <= alls.size(); ++i) {
        S[i] = S[i-1] + a[i];
    }
    // 离散化l和r,之间的未涉及的元素为0，具有的则通过前缀和处理l - r 之间的和
    for (auto item : query) {
        int l = find(item.first);
        int r = find(item.second);
        cout << S[r] - S[l-1] << endl;
    }
    return 0;
}