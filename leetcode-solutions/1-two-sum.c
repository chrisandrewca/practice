void _mergeSort(int* array, const size_t low, const size_t high) {

    if (high <= low) {
        return;
    }

    size_t mid = (low + high) / 2;

    _mergeSort(array, low, mid);
    _mergeSort(array, mid + 1, high);

    int* sorted = (int*)calloc(
        (mid - low + 1)     // lower length
        + (high - mid)      // higher length
        , sizeof(int));
    
    if (NULL == sorted) {
        return;
    }

    size_t i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {

        if (array[i] <= array[j]) {
            sorted[k] = array[i];
            i++;
        } else {
            sorted[k] = array[j];
            j++;
        }

        k++;
    }

    while (i <= mid) {
        sorted[k] = array[i];
        i++;
        k++;
    }

    while (j <= high) {
        sorted[k] = array[j];
        j++;
        k++;
    }

    for (i = 0, k = low; k <= high; ++i, ++k) {
        array[k] = sorted[i];
    }

    free(sorted);
};

void mergeSort(int* array, size_t size) {

    _mergeSort(array, 0, size - 1);
};

bool binarySearch(int* nums, size_t numsSize, int value, size_t* valueIndex) {

    size_t min = 0;
    size_t max = numsSize - 1;
    size_t i = 0;
    
    while (min <= max) {
        
        i = (min + max) / 2;

        if (value < nums[i]) {
            
            if (i == 0) {
                return false;
            }

            max = i - 1;
        } else if (value > nums[i]) {

            min = i + 1;
        } else if (value == nums[i]) {
            
            *valueIndex = i;
            return true;
        }
    }
    
    return false;
};

int* findTwoSum(int* nums, int numsSize, int target, int *returnSize, int i) {
    
    if (i >= numsSize) {
        return NULL;
    }
    
    int remainder = target - nums[i];
    size_t remainderIndex = 0;
    bool remainderFound = binarySearch(nums, numsSize, remainder, &remainderIndex);
    
    printf("t: %d, i: %d, nums[i]: %d, rem: %d, rf: %d, ri: %zu\n",
          target, i, nums[i], remainder, remainderFound, remainderIndex);
    for (int n = 0; n < numsSize; n++) {
        printf("n: %d, nums[n]: %d\n", n, nums[n]);
    }
    printf("\n");
    if (remainderFound == true && ((int)remainderIndex) != i) {
        *returnSize = 2;
        int* twoSumArray = (int*)calloc(*returnSize, sizeof(int));
        twoSumArray[0] = i;
        twoSumArray[1] = (int)remainderIndex;
        return twoSumArray;
    }
    
    return findTwoSum(nums, numsSize, target, returnSize, i + 1);
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    mergeSort(nums, numsSize);
    return findTwoSum(nums, numsSize, target, returnSize, 0);
};

// doesnt work because I sorted the input, need key based memoization