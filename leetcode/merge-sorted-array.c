/* https://leetcode-cn.com/problems/merge-sorted-array/
 * 合并两个有序数组
 * 输入:
 *     nums1 = [1,2,3,0,0,0], m = 3
 *     nums2 = [2,5,6],       n = 3
 * 输出: [1,2,2,3,5,6]
*/
void merge(int* nums1, int m, int* nums2, int n) {
    int i, j, t, pos = 0;
    
    for (i = 0; i < n; i++)
    {
        for (j = pos; j < m+i; j++)
            if (nums1[j] > nums2[i])
            {
                for (t = m+i; t > j; t--) nums1[t] = nums1[t-1];
                break;
            }
        nums1[j] = nums2[i];
        pos = j + 1;
    }
}
