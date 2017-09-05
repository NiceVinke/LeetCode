// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// Example 1:
//
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
//
//
//
// Example 2:
//
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        int total = size1 + size2;
        return total & 1 ? findKth(nums1, nums2, 0, size1, 0, size2, total / 2+1)  :
            (findKth(nums1, nums2, 0, size1, 0, size2, total / 2 + 1) + findKth(nums1, nums2, 0, size1, 0, size2, total / 2)) / 2.0;
    }
    int findKth(vector<int>& nums1, vector<int>& nums2, int s1, int e1, int s2, int e2, int k) {
        if(e1 - s1 > e2 - s2)  return findKth(nums2, nums1, s2, e2, s1, e1, k);
        if(s1 == e1) return nums2[s2 + k - 1];
        if(k==1)  return min(nums1[s1], nums2[s2]);
        
        int len1 = min(e1-s1, k/2);
        int len2 = k - len1;
        
        int m1 = s1 + len1 - 1;
        int m2 = s2 + len2 - 1;
        
        if (nums1[m1] < nums2[m2]) {
            return findKth(nums1, nums2, s1 + len1, e1, s2, s2 + len2, k - len1);
        } else if(nums1[m1] > nums2[m2]) {
            return findKth(nums1, nums2, s1, s1 + len1, s2 + len2, e2, k - len2);
        } else {
            return nums1[m1];
        }
    }
};
