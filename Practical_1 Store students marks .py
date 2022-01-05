'''
Name : Atharva Mohan Tirkhunde
Class : SE B
Roll no : 65

Write a Python program to store marks scored in subject “Fundamental of Data
Structure” by N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
Display mark with highest frequency

'''
def average_marks(average):
    sum = 0
    count = 0
    for i in range (len(M)):
        if M[i] != -1 :
            sum = sum + M[i]
            count = count + 1
    average = sum/count
    return(average)

def highest(max):
    max = M[0]
    for i in range (len(M)):
        if M[i]>max:
            max = M[i]
    return(max)

def lowest(min):
    min = M[0]
    for i in range (len(M)):
        if M[i] != -1 :
            if M[i]<min:
                min = M[i]

    return(min)

def count_absent(absent):
    absent = 0
    for i in range (len(M)):
        if M[i] == -1 :
            absent += 1
    return(absent)

def high_frequency(l):
    i = 0
    max = 0
    mark = 0
    print("\n\t  Marks         |    frequency count ")
    print("\t----------------------------------------")
    for ele in l:
        if l.index(ele) == i:
            print("\t\t",ele, "\t\t|\t\t", l.count(ele))
            if l.count(ele) > max:
                max = l.count(ele)
                mark = ele
        print("\t----------------------------------------")
        i += 1
    return (mark,max)

if __name__ == "__main__" :
    M=[]
    print("\n\t(Enter -1 for absent student)")
    N = int(input("\tEnter the Strength of the class : "))
    num=1
    for i in range (0,N):
        marks = int(input("\tMarks of Roll No. " + str(num+200) + " : "))
        M.append(marks)
        num+=1

    print("\n\t1. The average score of the class : ")
    print("\t2. Height Score : ")
    print("\t3. Lowest Score : ")
    print("\t4. Absent Count of the student : ")
    print("\t5. Highest frequency of marks {0} is {1} ")
    print("\n\tTo Exit Press 0 ")

    while (True):
        ch = int(input("\n\tEnter your Choice : "))
        if (ch == 1 ):
            print("\t1. The average score of the class : ",("%4f"%average_marks(M)))
        if (ch == 2 ):
            print("\t2. Height Score : ",highest(M))
        if (ch == 3 ):
            print("\t3. Lowest Score : ",lowest(M))
        if (ch == 4 ):
            print("\t4. Absent Count of the student : ",count_absent(M))
        if (ch == 5 ):
            mark, max = high_frequency(M)
            print("\n\t5. Highest frequency of marks {0} is {1} ".format( mark , max))
        if (ch == 0) :
            break