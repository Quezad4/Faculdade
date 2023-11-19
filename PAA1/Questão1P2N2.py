def quicksort(arr, low, high):
    if low < high:  
        pi = partition(arr, low, high)  
        quicksort(arr, low, pi - 1)  
        quicksort(arr, pi + 1, high)  

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1  

    for j in range(low, high):  
        if arr[j] <= pivot:  
            i += 1  
            arr[i], arr[j] = arr[j], arr[i]  

    arr[i + 1], arr[high] = arr[high], arr[i + 1]  
    return i + 1  


def main():
    vetorTest = [10,2,100,200,111,4,5,6,9,12,66,31,78,65,38,91]
    quicksort(vetorTest, 0, len(vetorTest)-1)
    print(vetorTest)



if __name__ == "__main__":
    main()
