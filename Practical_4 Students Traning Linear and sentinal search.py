
def linearsearch(stud,num):
    flag = 0
    key = int(input("Enter the Roll number to Search : "))
    for i in range (num) :
        if stud[i] == key :
            flag = 1
            break

    if flag == 0 :
        print("Student of Roll No.",key,"was not present in Training Program ")
    else :
        print("Student of Roll No.",key, "was present in Training Program ")

def sentinelsearch(stud,num) :

    key = int(input("Enter the Roll number to Search : "))
    last = stud[num-1]
    stud[num-1] = key
    i = 0
    while stud[i] != key :
        i+=1
    stud[num-1] = last

    if ( (i < (num-1)) or (stud[num-1]==key) ) :
        print("Student of Roll No.", key, "was present in Training Program ")
    else :
        print("Student of Roll No.", key, "was not present in Training Program ")

if __name__ == "__main__" :
    stud = []
    num = int(input("\nEnter the Total Number of Students who attended training Program  : "))
    for i in range (num) :
        s = int(input("Enter Roll No. : "))
        stud.append(s)
    print()
    print("1. Use Linear Search ")
    print("2. Use Sentinel Search ")
    print ("\nTo Exit Press 0 ")
    while (True) :
        ch = int(input("\nEnter your Choice To search : "))
        if ch == 1 :
            print("Linear Search")
            linearsearch(stud,num)
        if ch == 2:
            print("Sentinel search")
            sentinelsearch(stud, num)
        if ch == 0 :
            break