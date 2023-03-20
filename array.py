array = [int(x) for x in input('array=').split(',')]
i=0
while i<len(array):
    if array[i]%2==0:
        array.insert(i+1,array[i]+1)
        i+=1
    i+=1    
print(array)