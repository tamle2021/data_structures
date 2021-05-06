'''
Sliding window implementation
K-consecutive elements with maximum sum

pseudocode:
function maxSum(arr,k):
    maxSum = NEGATIVE_INFINITY
    n = arr.length
    Loop as i in range 0 < n - k + 1:
        currentSum = 0
        Loop as j in range 0 < k:
            currentSum += arr[i + j]

        maxSum = max(currentSum,maxSum)

    return maxSum

function maxSum(arr,n,k):
    windowSum = sum([arr[i] for i in range(k)])
    maxSum = windowSum

    LOOP over 0 < n - k with index i:
        windowSum = windowSum - arr[i] + arr[i + k]
        maxSum = max(maxSum,windowSum)

    return maxSum
'''

def maxSum(arr,windowSize):
    arraySize = len(arr)
    # n must be greater than k
    if (arraySize <= windowSize):
        print("invalid operation...")
        return -1

    # compute sum of first window of size k
    windowSum = sum([arr[i] for i in range(windowSize)])
    max_sum = windowSum
    # compute sums of remaining windows by removing first element of previous window and adding last element of
    # current window
    for i in range(arraySize - windowSize):
        windowSum = windowSum - arr[i] + arr[i + windowSize]
        max_sum = max(windowSum,max_sum)

    return max_sum


arr = [44,1,2,100,-1,5,4,0,25,-99,133,2001]
answer = maxSum(arr,3)
print("sliding window: {z}".format(z=answer))

