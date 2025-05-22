#include <stdio.h>
#include <stdlib.h>

int getMaxSubarraySum(int *nums, int n) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < n; i++)
    {
        // if the sum is greater than the current element then continue
        if (currentSum + nums[i] > nums[i]) {
            currentSum = currentSum + nums[i];
        }
        // otherwise take the current element
        else {
            currentSum = nums[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    return maxSum;
}

int main() {
    int *nums = NULL, *result = NULL, n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n > 0) {
        nums = (int *) malloc(n * sizeof(int));
        if (nums) {
            printf("Enter the elements: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &nums[i]);
            }
            result = getMaxSubarraySum(nums, n);
            if (result) {
                printf("Solution: [%d,%d,%d]", result[0], result[1], result[2]);
                free(result);
            }
            else {
                printf("No solution found");
            }
        }
        else {
            printf("Memory allocation failed");
        }
    }
    else {
        printf("Give atleast one element");
    }
    
    return 0;
}