Generate random data points for mathematical functions.
The data points are saved in the text-based format used by [fann](https://github.com/libfann/fann) to train neural networks.

This project depends on [math_eval](https://github.com/merlinmarek/math_eval).

Build with:
```
mkdir build
cd build
cmake ..
make
```

Usage:
```
generator "<mathematical expression>" <number of samples> <lower limit> <upper limit>
```
