def Print_Array(array) :
    print(array)

def Insertion_Sort(array) :
    for i in range(1, len(array)) :
        key = array[i]
        j = i-1
        while key < array[j] and j >= 0 :
            array[j+1] = array[j]
            j = j - 1
        array[j+1] = key

if __name__ == "__main__" :
    array = [3,2,5,1,4]
    
    print("Initially array is:")
    Print_Array(array)
    Insertion_Sort(array)
    print("Sorted array is:")
    Print_Array(array)