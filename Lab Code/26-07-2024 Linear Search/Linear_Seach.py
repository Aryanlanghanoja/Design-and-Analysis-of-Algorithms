def Linear_Seach(Array , Key) :
    for i in range(len(Array)) :
        if Array[i] == Key :
            return i
        
    return -1

if __name__ == "__main__" :

    input_str = input("Enter the Space Seperated Array Element :-")
    Key = float(input("Enter The Key To Find In Array:-"))
    Array = [float(num) for num in input_str.split(' ')]
    result = Linear_Seach(Array, Key)
    if result != -1 :
        print("Element is present at index", str(result))
        
    else :
        print("Element is not present in array")
        