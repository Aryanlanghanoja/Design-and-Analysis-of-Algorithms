def Selection_Sort(Array) :
    
    for i in range(len(Array)) :
        min_index = i 
        
        for j in range(i+1 , len(Array)) :
            if Array[j] < Array[min_index] :
                min_index = j
                
        Array[min_index] , Array[i] = Array[i] , Array[min_index]
        
    return Array

if __name__ == '__main__' :
    Array = [5, 2, 8, 1, 9, 3, 7, 4, 6]
    print("Original Array: ", Array)
    Sorted_Array = Selection_Sort(Array)
    print("Sorted Array: ", Sorted_Array)