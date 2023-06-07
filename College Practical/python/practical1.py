
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
        return -1

def binary_search(arr, target):
    low = 0
    high = len(arr)-1

    while low <= high:
        mid = (low + high) //2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid+1
        else:
            high = mid-1

    return -1

array = [4,5,6,7,8]
target =7

index = linear_search(array, target)

if index != -1:
    print("element found")

else:
    print("element not found")













