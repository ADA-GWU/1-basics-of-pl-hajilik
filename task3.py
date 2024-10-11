import time

# get the input form user
def get_matrix_input():
    rows = int(input("Enter number of rows: "))
    cols = int(input("Enter number of columns: "))
    
    matrix = []
    for i in range(rows):
        row = list(map(int, input(f"Enter row {i+1} (seperate by single space)").split()))
        matrix.append(row)
    return matrix


A = get_matrix_input() # user, enter the values
B = get_matrix_input()

start = time.time()

if len(A[0]) != len(B):
    raise ValueError("Hey, pay attention to number of columns in A and number of rows in B.")

result = [[0 for _ in range(len(B[0]))] for _ in range(len(A))]

for i in range(len(A)):
    for j in range(len(B[0])):
        for k in range(len(A[0])):
            result[i][j] += A[i][k] * B[k][j]
            
end = time.time()

print("The result is:")
for row in result:
    print(row)
    

execution = end - start
print("Multiplication duration:", execution)
