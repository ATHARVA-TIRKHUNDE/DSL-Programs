
'''

GROUP B-7
Write a python program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in
ascending order using
a) Selection Sort
Bubble sort and display top five scores

'''

def print_per(arr):
    for i in range(0, len(arr)):
        print(" \t {0:.2f}".format(arr[i]), end=" ")
    print()

def bubble_sort(arr):
    flg = 0
    for i in range(len(arr)):
        for j in range(0, (len(arr) - i - 1)):
            if (arr[j] >= arr[j + 1]):
                flg = 1
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
        if (flg == 0):
            break
    print(" \n Elements after bubble sort- \n ")
    print_per(arr)
    top_five(arr)

def swap(arr ,i , min) :
    t = arr[min]
    arr[min] = arr[i]
    arr[i] = t

def selection_sort(arr ,n ):
    for i in range (0,n-1):
        min = i
        for j in range (i+1,n):
            if( arr[min] > arr[j] ):
                min = j
        if( min!=i ):
            swap(arr,i,min)
    print(" \n Elements after selection sort- \n ")
    print_per(arr)
    top_five(arr)

def top_five(arr):
    j = 0
    print(" \n The top five scores are- ")
    for i in arr[::- 1]:
        print(" \t {0:.2f}".format(i), end=" ")
        j = j + 1
        if (j == 5):
            break
    print()

if __name__ == '__main__':
    arr = []
    while (True):
        print(" \n______________________________")
        print("Enter 1 Enter percentage")
        print("Enter 2 Display percentage")
        print("Enter 3 Bubble sort")
        print("Enter 4 Selection sort")
        print("Enter 5 Exit")

        c = int(input("Enter your choice: "))
        if (c == 1):
            n = int(input("Enter number of students: "))
            for i in range(n):
                arr.append(float(input("Enter first year percentage of roll no {}:".format(i + 1))))

        elif (c == 2 ):
            print_per(arr)

        elif (c == 3 ):
            bubble_sort(arr)

        elif (c == 4 ):
            selection_sort(arr,n)

        elif (c == 5 ):
            print("You Ended The Program")
            break
        else:
            print("Wrong Choice")