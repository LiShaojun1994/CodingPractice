#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int,int>> &seg){
    vector<pair<int,int>> result;
    int st = -2e9;
    int ed = -2e9;
    for(auto x:seg){
        if (ed < x.first){
            if (st!=-2e9) result.push_back(make_pair(st,ed));
            st = x.first;
            ed = x.second;
        }
        else{
            ed = max(ed,x.second);
        }
    }
    if (st!=-2e9) result.push_back(make_pair(st,ed));
    seg = result;
}
int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> lists;
    while (n--){
        int st,ed;
        cin>>st>>ed;
        lists.push_back(make_pair(st,ed));
    }
    sort(lists.begin(),lists.end(),[](pair<int,int> &x,pair<int,int> &y){return x.first <= y.first;});
    merge(lists);
    cout << lists.size();

    return 0;
}
