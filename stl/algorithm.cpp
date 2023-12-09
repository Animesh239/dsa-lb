// algorithms using stls

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>   // for accumulate
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    // find
    auto it = find(v.begin(), v.end(), 5);
    if(it != v.end())
        cout << "found at " << *it << endl;
    else
        cout << "not found" << endl;

    // binary search
    if(binary_search(v.begin(), v.end(), 5))
        cout << "found" << endl;
    else
        cout << "not found" << endl;

    // lower bound
    auto it1 = lower_bound(v.begin(), v.end(), 5);
    cout << "lower bound of 5 is " << *it1 << endl;

    // upper bound
    auto it2 = upper_bound(v.begin(), v.end(), 5);
    cout << "upper bound of 5 is " << *it2 << endl;

    // sort
    sort(v.begin(), v.end());
    for(auto i : v)
        cout << i << " ";
    cout << endl;

    // reverse
    reverse(v.begin(), v.end());
    for(auto i : v)
        cout << i << " ";
    cout << endl;

    // rotate
    rotate(v.begin(), v.begin() + 3, v.end()); // rotate from 0 to 3
    for(auto i : v)
        cout << i << " ";
    cout << endl;

    // min
    cout << "min of 1 and 2 is " << min(1,2) << endl;

    // max
    cout << "max of 1 and 2 is " << max(1,2) << endl;

    // swap
    int a = 1, b = 2;
    swap(a,b);
    cout << "a = " << a << " b = " << b << endl;

    // accumulate
    int sum = accumulate(v.begin(), v.end(), 0);  // 0 is initial value
    cout << "sum of vector is " << sum << endl;

    // count
    int cnt = count(v.begin(), v.end(), 5);
    cout << "count of 5 is " << cnt << endl;

    // count_if
    int cnt1 = count_if(v.begin(), v.end(), [](int x){return x%2 == 0;});
    cout << "count of even numbers is " << cnt1 << endl;

    // for_each
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});

    // lambda
    auto f = [](int x){return x*x;};
    cout << f(5) << endl;

    // min_element
    auto it3 = min_element(v.begin(), v.end());
    cout << "min element is " << *it3 << endl;

    // max_element
    auto it4 = max_element(v.begin(), v.end());
    cout << "max element is " << *it4 << endl;

    // minmax_element
    auto p = minmax_element(v.begin(), v.end());
    cout << "min element is " << *p.first << endl;

    // accumulate
    int sum1 = accumulate(v.begin(), v.end(), 0);
    cout << "sum of vector is " << sum1 << endl;

    // inner_product
    int inner = inner_product(v.begin(), v.end(), v.begin(), 0);
    cout << "inner product of vector is " << inner << endl;

    // adjacent_difference
    vector<int> v1(10);
    adjacent_difference(v.begin(), v.end(), v1.begin()); // 0 is initial value of v1
    cout << "adjacent difference of vector is ";
    for(auto i : v1)
        cout << i << " ";
    cout << endl;

    // partial_sum : sum of all elements till that point
    vector<int> v2(10);
    partial_sum(v.begin(), v.end(), v2.begin());  // 0 is initial value of v2
    cout << "partial sum of vector is ";
    for(auto i : v2)
        cout << i << " ";
    cout << endl;

    return 0;
}