## What is Endiannes?

Operations in computers such as storing, reading, transfering occurs with the help of binary numbers, 0s and 1s. For example, a computer wants to store the data (e.g., 0xabc123456) in its memory. The computer read the number either from right-to-left or left-to-right. It looks like either we read english text or arabic text. The order of reading the data is significant. To sum up my explanation, endiannes is the order in which bytes are arranged in computer memory. The importance of understanding endiannes emerge when we work with different hardware architectures or transferring data between systems. 

## What are the types of Endiannes?
In the above explanation, I somehow touched the types of Endiannes, left-to-right / right-to-left. Actually they have special names, Big Endian, and Little Endian.

## Big-endian: 
In this format, the most signifiant byte (MSB) is stored at the smallest memory address. For example, in the word, 'azerbaijan', the leftmost byte ('a') is stored first (smalllest address). The method is familiar to use because we also use the same method, read or write numbers starting with the most significant digit (from left-to-right). The big-endian format is mostly used in network protocols, otherwise computers may not understand how to read the transferred data. Let's provide another example: 
Number = 0x10112024. With big-endian format, it is stored in the memory like this: 10 | 11 | 20 | 24.


## Little-endian: 
In this format, the least significant byte (LSB) is stored in the smallest memory address. This format is specially famous in personal computers. It remainds 'reading arabic text'. 
For example, the number = 0x10112024 is stored in the memory like this: 24 | 20 | 11 | 10. 


## Importance of Endianness: 
Above, I touched a little bit to its importance as if they haven't handled correctly, misinterpretation of data can occur. For example, a computer that send data in big-endian format may not be understood correctly by a system that reads data in little-endian format. Therefore, the one who works with low-level data structures, file formats, or network communication must account for endiannes to ensure compatibility.

# Task #2

Firstly, I will explain how to calculate the size of the tuple by experimenting with different number of elements in the tuple. Total size of the tuple can be measured with below basic formula. 

Total Size = Base Overhead + (Number of Elements x Size of Each Element)

Base Overhead is 24 bytes. It can also be rechecked by calculating the size of empty tuple. Size of Element varies for different data types of the element. For integers and floats, they occupy 8 bytes in 64-bit system, and 4 bytes in 32-bit system. In the sample, I have three integers in the tuple. The size of the tuple is: 24 + 3*8 = 48.

Calculating the size of the list is similar to tuple. Base Overhead of the list is 40 bytes. It also can be rechecked by calculating empty list size. When there is three elements in the list, the size is 72 bytes: 40 bytes of base overhead, 24 bytes of three pointers, and 8 bytes for future growth.

In C++ language, the std::vector provides a dynamically resizable array, similar to a Python list, however the size of the vector is calculated in a different way. 

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3};  

    std::cout <<sizeof(vec) + vec.capacity() * sizeof(int) << std::endl;
    
    return 0;
}

The space occupied by empty vector is 24 bytes. For an extra elements in the vector, the size is increased by 4 bytes. For example, it there are three elements, the total size of the vector will be 24 bytes + 12 bytes = 36 bytes.


# Task #3

The code I have written in Python programming language varies from GPT version on account of using functions. In the code, I asked from the user to enter number of rows and columns which is followed by iteratively asking from the user to enter the elements of the matrix. However, GPT asks from the user to seperate the elements by space and semicolon between rows. Matrix multiplication phrase also shares the difference only in the context of writing for loop and summation in a single line of the code. Execution time also varies, mine was executed in 24.11 microseconds, while the code of gpt was executed in 25 microseconds. The source I benefited: https://www.geeksforgeeks.org/python-program-multiply-two-matrices/

The prompt I asked from GPT: "Write the python code that takes two matrices and multiply them by calculating also the execution time. Print the result matrix and the execution time. Try to avoid writing comments, I can figure out."

The code I have written in C++ programming languages varies from GPT again on account of using methods. GPT seperates the function that enables it to repeteadly multiplying matrices. The codes also share difference on reading inputs. GPT code beats mine in execution time, 2.07 microseconds by GPT and 5.06 performed by mine 5.08 microseconds. I read: https://www.programiz.com/cpp-programming/examples/matrix-multiplication

The prompt I asked from GPT: "Write the code in C++ language, (smae instructions)"

Overall, as expected, C++ outperforms Python in execution time. 


# Task #4

The implementation of slicing operation in Python is easy, visualization as well, using numpy and matplotlib. My code asks from user to enter size of the matrix and fill it with ascending number. I sliced the 2D matrix from 1 to size-1. For visualization, I used matplotlib to display both the original and the sliced matrix. Each element is labeled in the plot with its respective value, and the Blues color map is applied for better contrast. The two matrices are displayed side by side for comparison.

The code written by GPT is a bit different. It asks row and column indexes and randomly fill the matrix in the range of 1 to 100. User also enters start and end indexes for slicing. GPT also uses matplotlib library for visualization.

The promt I asked from GPT: "Write 2D matrix slicing in Python and visualize the results."

The implementation of slicing operation in C++ is a bit complicated, at least it was't easy as Python. In my code, I ask from the user to enter the size of the matrix and fill n x n matrix with numbers in ascending order. Unlike Python, I use nested for loops to slice the matrix on the specified border, from 1 till n-1. I print the original and sliced matrices to visualize the results, of course not the same quality as matplotlib enables Python users. At least, I searched for alternative libraries for C++ that allows visualzation, and found this resource: https://stackoverflow.com/questions/4283731/plotting-package-for-c

GPT approach is similar to mine, it also tries to iterate over all elements in the matrix and got slice it. GPT also uses <SFML/Graphics.hpp> library for visualization, but the execution of code is fails in the first attempt. It requires the setup of the library and other processes.

The promt I asked from GPT: "Now implement the code either in C or C++ or Java (that enables visualization)".

Overall, my code is easy to execute and does slicing successfully without acquiring additional setups. However, the code provided by GPT fails in the first attempt of execution.

