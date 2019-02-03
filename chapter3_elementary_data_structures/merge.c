#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n) {
    int i, j, t, pos = 0;
    
    for (i = 0; i < n; i++)
    {
        printf("pos is %i\n", pos);
        for (j = pos; j < m+i; j++)
            if (nums1[j] > nums2[i])
            {
                for (t = m+i; t > j; t--) nums1[t] = nums1[t-1];
                break;
            }
        nums1[j] = nums2[i];
        printf("nums1[%i] is %i\n", j, nums2[i]);
        pos = j + 1;
    }
}

int main(void)
{
    int i;
    int nums1[6] = {1, 2, 3, 0, 0, 0};
    int nums2[3] = {2, 5, 6};
    void merge(int*, int, int*, int);

    merge(nums1, 3, nums2, 3);

    for (i = 0; i < 6; i++) printf("%i\n", nums1[i]);

    return 0;
}