## What is Endiannes?

Operations in computers such as storing, reading, transfering occurs with the help of binary numbers, 0s and 1s. For example, a computer wants to store the data (e.g., 0xabc123456) in its memory. The computer read the number either from right-to-left or left-to-right. It looks like either we read english text or arabic text. The order of reading the data is significant. To sum up my explanation, endiannes is the order in which bytes are arranged in computer memory. The importance of understanding endiannes emerge when we work with different hardware architectures or transferring data between systems. 

## What are the ## {types of Endiannes?}
In the above explanation, I somehow touched the types of Endiannes, left-to-right / right-to-left. Actually they have special names, Big Endian, and Little Endian.

## Big-endian: 
In this format, the most signifiant byte (MSB) is stored at the smallest memory address. For example, in the word, 'azerbaijan', the leftmost byte ('a') is stored first (smalllest address). The method is familiar to use because we also use the same method, read or write numbers starting with the most significant digit (from left-to-right). The big-endian format is mostly used in network protocols, otherwise computers may not understand how to read the transferred data. Let's provide another example: 
Number = 0x10112024. With big-endian format, it is stored in the memory like this: 10 | 11 | 20 | 24.


## Little-endian: 
In this format, the least significant byte (LSB) is stored in the smallest memory address. This format is specially famous in personal computers. It remainds 'reading arabic text'. 
For example, the number = 0x10112024 is stored in the memory like this: 24 | 20 | 11 | 10. 


## Importance of Endianness: 
Above, I touched a little bit to its importance as if they haven't handled correctly, misinterpretation of data can occur. For example, a computer that send data in big-endian format may not be understood correctly by a system that reads data in little-endian format. Therefore, the one who works with low-level data structures, file formats, or network communication must account for endiannes to ensure compatibility.

