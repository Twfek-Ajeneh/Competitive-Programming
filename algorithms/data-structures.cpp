#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

//for ordered set
typedef tree<
            int,
            null_type,
            less<int>,
            rb_tree_tag,
            tree_order_statistics_node_update
        > ordered_set;

//for ordered multiset
typedef tree<
            int,
            null_type,
            less_equal<int>,
            rb_tree_tag,
            tree_order_statistics_node_update
        > ordered_set;

//Priority-queue with increasing order:
priority_queue<int , vector<int> , greater<int>> q;
