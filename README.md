# bignum

## C++ Big Numbers Library

### Objectives of the project

Main objective of creating this library is to explore and understand how does arbitrary precision arithmetic works.
Don't use this soulution for any production need, only for educational purposes.
If you have any question, willing to collaborate or just to discus some parts of the project, feel free to reach out to me.
bohdan.kornatskyi@gmail.com

### How to use

#### Ubuntu

```bash
git clone https://github.com/kornatskyi/bignum.git

cd bignum

# Generate build system to the build folder (will be created automatically)
cmake -S . -B build

cd ./build

# Run from `build` folder. Builds the project 
make

# Run tests
./bignum_test

# Run main file from `src/`
./bignum
```

For using as a library
Clone the `bignum` project to your project. Include header file `BigInt.hpp` from `include/` directory into your file why you going to use the BigInt. Add source files from  `src/` folder to your building tool.

### Classes implemented at this point

- **BigInt** - signed integer data type

### Data structure for storing a number

 Dynamic array of characters

```cpp
std::vector<char> _digits;
```

Boolean value for storing a sign, initially positive

```cpp
bool _sign = ture;
```

### Arithmetics algorithms

#### Addition

- **School book addition algorithm**. O(n) time complexity

#### Substruction

- **School book substruction algorithm**. O(n) time complexity

#### Multiplication

- **School book multiplication algorithm**. O(n^2) time complexity
- **Karatsuba's algorithm**. O(n^lg3) time complexity

#### Division

- **School book division algorithm**. O(n^2) time complexity

#### Modulus operation

- **Repeated multiplication and reduction**. O(n^2) time complexity


### Testing

#### Unit testing

Unit testing is pretty straight forward and self explanatory. 

#### Benchmarking

The are to part to benchmarking, test data generation and measuring function efficiency
`DataGenerator.hpp` header file contains `generateNumberSets()` function which has self explanatory comments and will produce output to the file, by default it's `data.txt` file in the same folder where program was started.
After data was generated you need copy-paste int from `data.txt` to `DataSet.hpp` file in the appropriate field.
Then this data will be fetched by functions in `PerformanceTest.hpp` file. The functions fill put output into `bignum/performance_test_results/` folder by default.

