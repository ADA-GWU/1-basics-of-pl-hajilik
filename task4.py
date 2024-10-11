import numpy as np # it will be used to create matrices
import matplotlib.pyplot as plt  # this library is perfect choice for visual representation
size = int(input("Enter number of rows: "))

matrix = np.arange(1, size * size + 1).reshape(size, size)
print("Original Matrix:")
print(matrix)

sliced_matrix = matrix[1:size-1, 1:size-1]
print("\nSliced Matrix:")
print(sliced_matrix)
'''output: Original Matrix:
[[ 1  2  3  4]
 [ 5  6  7  8]
 [ 9 10 11 12]
 [13 14 15 16]]

Sliced Matrix:
[[ 6  7]
 [10 11]]'''
 
fig, axs = plt.subplots(1, 2, figsize=(12, 6))

axs[0].imshow(matrix, cmap='Blues', aspect='auto')
axs[0].set_title("Original")
for (i, j), value in np.ndenumerate(matrix):
    axs[0].text(j, i, value, ha='center', va='center', color='white')

axs[1].imshow(sliced_matrix, cmap='Blues', aspect='auto')
axs[1].set_title("Sliced")
for (i, j), value in np.ndenumerate(sliced_matrix):
    axs[1].text(j, i, value, ha='center', va='center', color='white')

plt.tight_layout()
plt.show()
