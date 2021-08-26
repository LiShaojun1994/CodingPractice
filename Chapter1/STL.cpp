/* 系统未某一程序分配空间时，所需时间和空间大小无关，和申请次数有关
 * vector 变长数组
 *      size() 返回元素个数
 *      empty() 返回是否为空
 *      clear() 清空
 *      push_back()/pop_back()
 *      begin()/end()
 *      []
 *      支持比较运算 字典序
 * queue
 *      size()
 *      empty()
 *      front()
 *      back()
 *      push()
 *      front()
 * string
 *      size()
 *      empty()
 *      clear()
 *      substr(pos_start,length())
 * priority_queque 优先队列
 *      push()
 *      top()
 *      pop()
 *      定义小根堆的方式： priority_queue<int,vector<int>,greater<int>> s_heap
 * stack
 *      size()
 *      top()
 *      push()
 *      pop()
 * deque
 *      size()
 *      empty()
 *      clear()
 *      front()/back()
 *      push_back()/pop_back()
 *      push_front()/pop_front()
 *      begin()/end()
 *      []
 * set map multiset multimap
 *      size()
 *      empty()
 *      clear()
 *      begin()/end() O(logn)
 *
 * set/multiset
 *      insert()
 *      find()
 *      count()
 *      erase()
 *          (1) 输入一个数x，删除所有x O(k+logn);
 *          (2) 输入一个迭代器，删除一个迭代器
 *      lower_bound(x)/upper_bound(x)
 *          1 返回大于等于x的最小的数的迭代器
 *          2 返回大于x的最小的数的迭代器
 *  map/multimap
 *      insert() 插入的数是一个pair
 *      erase() 输入的是pair或者迭代器
 *      find()
 *      [] O(logn)
 *  unordered_set unordered_map unordered_multiset unordered_multimap
 *      和上面类似，增删改查的时间复杂度是O(1)
 *      不支持lower_bound()/upper_bound()
 *  bitset 压位
 *      bitset<100000> s;
 *      ~s & | ^
 *      == !=
 *      []
 *      count() 返回多少个1
 *      any() 判断是否至少有一个1
 *      none() 判断是否全为空
 *      set() 把所有位置设置1
 *      set(k,v)把第k位变成v
 *      reset() 把所有位都变成0
 *      flip() 取反
 *      flip(k) 把第k位取反
 *
 */
#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue<int> heap;//默认大根堆
    priority_queue<int,vector<int>,greater<int>> s_heap;//小根堆

}