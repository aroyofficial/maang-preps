#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} KeyValuePair;

int comparator(const void *a, const void *b) {
    return ((KeyValuePair *)a)->value - ((KeyValuePair *)b)->value;
}

int *twoSum(int *nums, int n, int target, int *result) {
    if (nums) {
        int left = 0, right = n - 1;
        KeyValuePair *kv = (KeyValuePair *) malloc(n * sizeof(KeyValuePair));
    
        if (kv) {
            for (int i = 0; i < n; i++) {
                kv[i].key = i;
                kv[i].value = nums[i];
            }
        
            qsort(kv, n, sizeof(KeyValuePair), comparator);
        
            for (int i = 0; i < n - 2; i++) {
                int left = i + 1, right = n - 1;
                while (left < right) {
                    int sum = kv[i].value + kv[left].value + kv[right].value;
            
                    if (sum == target) {
                        result = (int *) malloc(3 * sizeof(int));
                        if (result) {
                            result[0] = kv[i].key;
                            result[1] = kv[left].key;
                            result[2] = kv[right].key;
                        }
                        free(kv);
                        return result;
                    }
                    else if (sum > target) {
                        right--;
                    }
                    else {
                        left++;
                    }
                }
            }
    
            free(kv);
        }
    }

    return result;
}

int main() {
    int *nums = NULL, *result = NULL, n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n > 2) {
        nums = (int *) malloc(n * sizeof(int));
        if (nums) {
            printf("Enter the elements: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &nums[i]);
            }
            printf("Enter the target: ");
            scanf("%d", &target);
            result = twoSum(nums, n, target, result);
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
        printf("Give more than two element");
    }
    
    return 0;
}