def Counting_Sort(string) :
    Count_Array = [0 for i in range(256)]

    for i in string :
        Count_Array[ord(i)] = Count_Array[ord(i)] + 1
        
    sorted_string = ""
    
    for i in range(0 , len(Count_Array)) :
        sorted_string = sorted_string + Count_Array[i] * chr(i)
    
    return sorted_string

if __name__ == '__main__' :
    string = "abcednfkjfAKODPEFIWEJDLdokwidfjeiojfwclkpowekfWOIREOWPSLDKJFOE"
    result = Counting_Sort(string)
    print(result)