
'''
 Write a python program to store names and mobile numbers of your friends in sorted order
 on names. Search
 your friend from list using binary search (recursive and non- recursive).
  Insert friend if not present in phonebook

'''

def setNamesInSortOrder():
    global friendNames
    friendNames = list(friends.keys())
    friendNames.sort()
    print(friendNames)

def checkResult(result, search):
    global friendNames
    if result != -1:
        print(" Mobile Number of {} is {}".format(friendNames[result], friends[friendNames[result]]))
    else:
        print('Friend {} not Found. Adding him in FriendList.'.format(search))
        number = input("Enter Number : ")
        friends[search] = number
        print(' Friend List: \n', friends)
        setNamesInSortOrder()
       # print(friendNames)
    options()


def binarySearchRec(friendNames, lowerIndex, higherIndex, search):
    if higherIndex >= lowerIndex:
        midIndex = (higherIndex + lowerIndex) // 2
        #  1) / : Divides the number on its left by the number on its right and returns a floating point value.
        #  2) // : Divides the number on its left by the number on its right, rounds down the answer, and returns a whole number.
        if friendNames[midIndex] == search:
            return midIndex
        elif friendNames[midIndex] > search:
            return binarySearchRec(friendNames, lowerIndex, midIndex - 1, search)
        else:
            return binarySearchRec(friendNames, midIndex + 1, higherIndex, search)
    else:
        return -1


def binarySearchNonRec(friendNames, search):
    low = 0
    high = len(friendNames) - 1
    mid = 0

    while low <= high:
        mid = (high + low) // 2
        if friendNames[mid] < search:
            low = mid + 1
        elif friendNames[mid] > search:
            high = mid - 1
        else:
            return mid
    return -1

def options():
    print('--------------------------------------------')
    print('Options: ')
    print('1. Binary Search - Recursive')
    print('2. Binary Search - Non-Recursive')
    print('3. Exit')

    ch = int(input("Enter Your Option: "))
    if ch == 1:
        search = input("Enter friend Name to Search: ")
        result = binarySearchRec(friendNames, 0, len(friendNames) - 1, search)
        checkResult(result, search)
    elif ch == 2:
        search = input("Enter friend Name to Search: ")
        result = binarySearchNonRec(friendNames, search)
        checkResult(result, search)
    elif ch == 3:
        exit
    else:
        print('Incorrect option, choose again')
        options()

if __name__ == '__main__':

    print("\nAuthor : Atharva Mohan Tirkhunde ")
    print("Phone Number : 8625015833 ")
    print("\n_____________________PHONEBOOK_______________________\n")
    choice = '1'
    friends = {}
    while choice == '1':
        name = input("Enter Name: ")
        number = input("Enter Number: ")
        friends[name] = number
        print(friends)
        choice = input("To add more friends Press 1 : ")

    friendNames = []
    print('Friend List: \n', friends)
    setNamesInSortOrder()
    options()
