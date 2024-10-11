import numpy as np
import matplotlib.pyplot as plt

# Initialize the matrix with different values
def create_matrix(rows, cols):
    return np.random.randint(1, 100, size=(rows, cols))

# Function to slice the matrix
def slice_matrix(matrix, row_start, row_end, col_start, col_end):
    return matrix[row_start:row_end, col_start:col_end]

# Function to visualize the matrices
def visualize_matrices(original, sliced, title1="Original Matrix", title2="Sliced Matrix"):
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 6))

    # Displaying original matrix
    cax1 = ax1.matshow(original, cmap='coolwarm')
    ax1.set_title(title1)
    for (i, j), value in np.ndenumerate(original):
        ax1.text(j, i, f'{value}', ha='center', va='center')

    # Displaying sliced matrix
    cax2 = ax2.matshow(sliced, cmap='coolwarm')
    ax2.set_title(title2)
    for (i, j), value in np.ndenumerate(sliced):
        ax2.text(j, i, f'{value}', ha='center', va='center')

    fig.colorbar(cax1, ax=[ax1, ax2])
    plt.show()

# Get input for the matrix size and slicing range
rows = int(input("Enter the number of rows for the matrix: "))
cols = int(input("Enter the number of columns for the matrix: "))

matrix = create_matrix(rows, cols)
print("Original Matrix:")
print(matrix)

row_start = int(input("Enter starting row index for slicing: "))
row_end = int(input("Enter ending row index for slicing: "))
col_start = int(input("Enter starting column index for slicing: "))
col_end = int(input("Enter ending column index for slicing: "))

# Slice the matrix
sliced_matrix = slice_matrix(matrix, row_start, row_end, col_start, col_end)
print("Sliced Matrix:")
print(sliced_matrix)

# Visualize both matrices
visualize_matrices(matrix, sliced_matrix)


# I entered 10, 10, 2, 5, 2, 5 and the code printed below results. GPT appoached the 

'''Original Matrix:
[[ 1 80 99  3 49 59 38  8 80 74]
 [78 85 94 87 78 15 52 57 37 25]
 [60 62  9 80 12 79 36 78 64 81]
 [62 73 83 39 59 96 71 14 26 97]
 [60 42 17 43 67 14 62 17 27 10]
 [71 45 74  3 89 31 92 16 59  3]
 [83 79  5 88 64 39  2 89 10 68]
 [24 81 21 49 47 42 70 15 54 83]
 [ 7 58 57 33 14 69 32 84 30 58]
 [18 80 20 41 83 61 94 25 86  8]]
Sliced Matrix:
[[ 9 80 12]
 [83 39 59]
 [17 43 67]]'''
