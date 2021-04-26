#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;
/*
struct SegNode {
    int lo, hi, add;
    SegNode* lchild, *rchild;
    SegNode(int left, int right): lo(left), hi(right), add(0), lchild(nullptr), rchild(nullptr) {}
};

class Solution {
public:
    SegNode* build(int left, int right) {
        SegNode* node = new SegNode(left, right);
        if (left == right) {
            return node;
        }
        int mid = (left + right) / 2;
        node->lchild = build(left, mid);
        node->rchild = build(mid + 1, right);
        return node;
    }

    void insert(SegNode* root, int val) {
        root->add++;
        if (root->lo == root->hi) {
            return;
        }
        int mid = (root->lo + root->hi) / 2;
        if (val <= mid) {
            insert(root->lchild, val);
        }
        else {
            insert(root->rchild, val);
        }
    }

    int count(SegNode* root, int left, int right) const {
        if (left > root->hi || right < root->lo) {
            return 0;
        }
        if (left <= root->lo && root->hi <= right) {
            return root->add;
        }
        return count(root->lchild, left, right) + count(root->rchild, left, right);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum = 0;
        vector<long long> preSum = {0};
        for (int v: nums) {
            sum += v;
            preSum.push_back(sum);
        }

        set<long long> allNumbers;
        for (long long x: preSum) {
            allNumbers.insert(x);
            allNumbers.insert(x - lower);
            allNumbers.insert(x - upper);
        }
        // 利用哈希表进行离散化
        unordered_map<long long, int> values;
        int idx = 0;
        for (long long x: allNumbers) {
            values[x] = idx;
            idx++;
        }

        SegNode* root = build(0, values.size() - 1);
        int ret = 0;
        for (long long x: preSum) {
            int left = values[x - upper], right = values[x - lower];
            ret += count(root, left, right);
            insert(root, values[x]);
        }
        return ret;
    }
};
 */

int myCount(vector<long long>& preSum, int lower, int upper, int left, int right) {
    if (left == right)
        return 0;
    else {
        int mid = (left + right) / 2;
        int n1 = myCount(preSum, lower, upper, left, mid);
        int n2 = myCount(preSum, lower, upper, mid + 1, right);
        int ret = n1 + n2;

        int i = left;
        int l = mid + 1, r = mid + 1;

//        枚举每一个i的值计算相应的[l, r)
//        while (i <= mid) {
//            l = lower_bound(preSum.begin() + mid + 1, preSum.begin() + right, preSum[i] + lower) -
//                (preSum.begin() + mid + 1);
//            r = upper_bound(preSum.begin() + mid + 1, preSum.begin() + right, preSum[i] + upper) -
//                (preSum.begin() + mid + 1);
//            ret += (r - l);
//            i++;
//        }
        while (i <= mid) {
            while (l <= right && preSum[l] - preSum[i] < lower) l++;
            while (r <= right && preSum[r] - preSum[i] <= upper) r++;
            ret += (r - l);
            i++;
        }


//        归并排序
        vector<long long> tmp(right - left + 1);
        l = left;
        r = mid + 1;
        int k = 0;
        while (l <= mid || r <= right) {
            if (l > mid)
                tmp[k++] = preSum[r++];
            else if (r > right)
                tmp[k++] = preSum[l++];
            else {
                if (preSum[l] > preSum[r])
                    tmp[k++] = preSum[r++];
                else
                    tmp[k++] = preSum[l++];
            }
        }

        for (int j = 0; j < tmp.size(); j++)
            preSum[left + j] = tmp[j];


        return ret;
    }

}

int countRangeSumRecursive(vector<long>& sum, int lower, int upper, int left, int right) {
    if (left == right) {
        return 0;
    } else {
        int mid = (left + right) / 2;
        int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
        int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
        int ret = n1 + n2;

        // 首先统计下标对的数量
        int i = left;
        int l = mid + 1;
        int r = mid + 1;
        while (i <= mid) {
            while (l <= right && sum[l] - sum[i] < lower) l++;
            while (r <= right && sum[r] - sum[i] <= upper) r++;
            ret += (r - l);
            i++;
        }

        // 随后合并两个排序数组
        vector<int> sorted(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;
        while (p1 <= mid || p2 <= right) {
            if (p1 > mid) {
                sorted[p++] = sum[p2++];
            } else if (p2 > right) {
                sorted[p++] = sum[p1++];
            } else {
                if (sum[p1] < sum[p2]) {
                    sorted[p++] = sum[p1++];
                } else {
                    sorted[p++] = sum[p2++];
                }
            }
        }
        for (int i = 0; i < sorted.size(); i++) {
            sum[left + i] = sorted[i];
        }
        return ret;
    }
}




int countRangeSum(vector<int>& nums, int lower, int upper) {
    vector<long long int> preSum{0};
    long v = 0;
    for (auto& num: nums)
    {
        v += num;
        preSum.push_back(v);
    }

//    return countRangeSumRecursive(preSum, lower, upper, 0,preSum.size()-1);
    return myCount(preSum, lower, upper, 0, preSum.size()-1);
}


int main() {
    vector<int> v={2147483647,-2147483648,-1,0};
    cout << countRangeSum(v, -1, 0);


    return 0;
}
