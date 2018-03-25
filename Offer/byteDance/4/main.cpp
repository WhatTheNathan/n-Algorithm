#include <iostream>
#include <set>
#include <cmath>

using namespace::std;

/*
 * 两个集合，定义magic操作，
 * 从一个集合拿出一个数据，放到另一个集合中，之后两个集合的平均数都增大
 * 这样的操作最多几次
 */

inline long double avege(int sum, int num) {
    return (long double)sum / num;
}

const long double eps = 1e-14;
inline int cmp(long double a, long double b)
{
    if(fabs(a-b) <= eps) return 0;
    return a > b ? 1 : -1;
}

// 必须是
// 1. 平均值大的集合中的元素
// 2. 该元素小于自己的平均值
// 3. 且大于对面平均值
// 4. 且对面没有这个元素
int main() {
    int n = 0; // a中元素
    int m = 0; // b中元素
    set<int> a,b;
    long long sum_a,sum_b;
    long double ave_a,ave_b;

    int value;

    scanf("%d%d",&n,&m);

    for(int i = 0 ; i < n; i++) {
        scanf("%d",&value);
        a.insert(value);
        sum_a += value;
    }
    for(int i = 0; i < m; i++) {
        scanf("%d",&value);
        b.insert(value);
        sum_b += value;
    }

    ave_a = avege(sum_a, n);
    ave_b = avege(sum_b, m);

    // 指针操作更换
    if(cmp(ave_a,ave_b) == -1) {
        swap(sum_a,sum_b);
        swap(n,m);
        a.swap(b);
    }

    int answer = 0;
    for(auto num: a) {
        ave_a = avege(sum_a, n);
        ave_b = avege(sum_b, m);

        if(cmp(num, ave_a) >= 0)
            break;
        if( !b.count(num) && cmp(num, ave_b) > 0) {
            answer++;
            sum_a -= num;
            sum_b += num;
            b.insert(num);
            n--;
            m++;
        }
    }
    printf("%d\n",answer);
}