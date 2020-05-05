## How_To_Run

```
$ mkdir build && cd build
$ cmake .. -DCMAKE_BUILD_TYPE=Release
$ make
$ mkdir mnist_data && cd mnist_data
$ wget -c http://yann.lecun.com/exdb/mnist/train-images-idx3-ubyte.gz
$ wget -c http://yann.lecun.com/exdb/mnist/train-labels-idx1-ubyte.gz
$ wget -c http://yann.lecun.com/exdb/mnist/t10k-images-idx3-ubyte.gz
$ wget -c http://yann.lecun.com/exdb/mnist/t10k-labels-idx1-ubyte.gz
$ gunzip train-images-idx3-ubyte.gz 
$ gunzip train-labels-idx1-ubyte.gz 
$ gunzip t10k-labels-idx1-ubyte.gz 
$ gunzip t10k-images-idx3-ubyte.gz 
$ cd .. && ./mnist
```
