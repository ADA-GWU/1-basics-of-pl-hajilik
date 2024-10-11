import time

def get_matrix_input():
 
    raw_input = input("Enter the matrix rows separated by semicolons (e.g. '1 2; 3 4'): ")
    matrix = [list(map(int, row.split())) for row in raw_input.split(';')]
    return matrix

def matrix_multiplication(A, B):

    rows_A, cols_A = len(A), len(A[0])
    rows_B, cols_B = len(B), len(B[0])

    if cols_A != rows_B:
        raise ValueError("Number of columns in A must match number of rows in B.")

    result = [[sum(A[i][k] * B[k][j] for k in range(cols_A)) for j in range(cols_B)] for i in range(rows_A)]
    return result

def main():
   
    print("Input for Matrix A:")
    A = get_matrix_input()
    print("Input for Matrix B:")
    B = get_matrix_input()

    start_time = time.time()
    result = matrix_multiplication(A, B)
    end_time = time.time()
    
    print("The result of matrix multiplication is:")
    for row in result:
        print(row)
        
        
    execution_time = end_time - start_time
    print(f"Time spent on Execution: {execution_time:.6f} seconds")

if __name__ == "__main__":
    main()
