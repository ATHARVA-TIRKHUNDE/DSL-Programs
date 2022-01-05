'''
Name : Atharva Mohan Tirkhunde
Class : SE B
Roll No : 65

GROUP A-3 : Write a python program that determines the location of a saddle point
of matrix if one exists. An m x n matrix is said to have a
saddle point if some entry a[i][j] is the smallest value in row i
and the largest value in j.

'''

def saddle(m):
    for i in range (0,len(m)) :
        row_min = m[i][0]
        col_index = 0
        for j in range (1,len(m)):
            if row_min > m[i][j] :
                row_min = m[i][j]
                col_index = j
    flag = 0
    for k in range (0,len(m)) :
        if row_min < m[k][col_index] :
            flag = 1
            # break
        if flag == 0 :
            print("\nSaddle point is : ",row_min)
            print("Saddle point is present at location m[{0}][{1}]".format(i+1, col_index+1))
            return
    print("\nNo Saddle Point Found !!! ")
    return

def Input_matrix ():
    row = int(input("Enter the Number of Rows in the Matrix : "))
    col = int(input("Enter the Number of Column in the Matrix : "))
    matrix = []
    print("Enter the Elements Rowwise ")
    for i in range (0,row) :
        a = []
        for j in range (0,col) :
            a.append(int(input("Enter the Element : ")))
        matrix.append(a)
    return matrix,row,col

if __name__ == "__main__":
    print("---------------------------------------")
    matrix,row,col = Input_matrix()
    print("---------------------------------------")
    print("The Matrix is : ")
    print()
    for i in range (0,row):
        for j in range (0,col):
            print('\t',matrix[i][j], end = "  ")
        print()
    print("---------------------------------------")
    saddle(matrix)