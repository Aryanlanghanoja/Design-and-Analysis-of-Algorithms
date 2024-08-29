def Print_Array(array) :
    print(array)

def Bubble_Sort(array) :
    for intended in range(len(array) - 1 , 0 , -1) :
        for i in range(intended) :
            if array[i] > array[i+1] :
                array[i] , array[i+1] = array[i+1] , array[i]        

if __name__ == "__main__" :
    array = [3,2,5,1,4]
    
    print("Initially array is:")
    Print_Array(array)
    
    Bubble_Sort(array)
    
    print("Sorted array is:")
    Print_Array(array)