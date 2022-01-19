# bignum

## 0️⃣1️⃣1️⃣0️⃣0️⃣0️⃣1️⃣0️⃣0️⃣1️⃣1️⃣0️⃣1️⃣0️⃣0️⃣1️⃣0️⃣1️⃣1️⃣0️⃣0️⃣1️⃣1️⃣1️⃣
## 0️⃣1️⃣1️⃣0️⃣1️⃣1️⃣1️⃣0️⃣0️⃣1️⃣1️⃣1️⃣0️⃣1️⃣0️⃣1️⃣0️⃣1️⃣1️⃣0️⃣1️⃣1️⃣0️⃣1️⃣

## C++ Big Numbers Library

At this point library consist only of BigInt (big integers) datatype

`std::vector<char>` chosen as a data structure for storing big integers.
Length of a number limited only by data type which is used for accessing nth digit in the vector.
In this case it is `int` so in a standard implementation of C++ it would be 2^31 (31 because signed int used) and of course by computer's memory.

Implemented all arithmetic, assignment and comparison operations
Also added couple of util method, such as converting number to string, streaming number to the standard output stream, reading numbers from standard input, etc.
