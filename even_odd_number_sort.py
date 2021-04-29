'''
Sort array and also return swap count
'''

def sort(arr):
    index = 0;
    n = len(arr)
    while (index < int(n)):
        if (index == 0):
            index = index + 1
        if (compare(arr[index],arr[index - 1])):
            index = index + 1;
        else:
            temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            index = index - 1
    return arr

def compare(a,b) :
    if (a % 2 == b % 2):
        return a > b;
    else:
        return a % 2 == 1

if (__name__ == "__main__"):
    a = [3, 2, 5, 6, 4, 9, 11,7]
    array = sort(a)
    print(array)
