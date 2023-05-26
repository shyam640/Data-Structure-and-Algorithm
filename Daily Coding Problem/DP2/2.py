def skippedProduct(arr, n):
    # Method 1
    ans = [1]*n
    for i in range(0, n):
        prod = 1
        for j in range(i-1, -1, -1):
            prod *= arr[j]
        for j in range(i+1, n):
            prod *= arr[j]
        ans[i] = prod

    return ans

    # Method 2
    ans = [1]*n
    prod = 1
    for i in range(0, n):
        prod *= arr[i]
    for j in range(0, n):
        ans[j] = prod//arr[j]
    return ans

    # Method 3
    leftPrefProd = [1]*n
    rightPrefProd = [1]*n
    ans = [1]*n
    for i in range(1, n):
        leftPrefProd[i] = leftPrefProd[i-1]*arr[i-1]
    for i in range(n-2, -1, -1):
        rightPrefProd[i] = rightPrefProd[i+1]*arr[i+1]
    for i in range(0, n):
        ans[i] = leftPrefProd[i]*rightPrefProd[i]
    return ans


n = int(input())    # size of array
arr = list(map(int, input().split()))
ans = skippedProduct(arr, n)
print(ans)