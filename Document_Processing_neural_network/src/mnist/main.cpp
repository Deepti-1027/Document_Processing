#include <dataset.hpp>
#include <mnist.hpp>
#include <omp.h>

#define BATCH_SIZE 2 //128
#define LEARNING_RATE 0.003
#define L2 0.0001
#define EPOCHS 10 //30
#define BETA 0.99

int main() {
  // DataSet dataset("./mnist_data", true);
  // dataset.forward(64, true);
  // dataset.print_im();

  // auto cudaStatus = cudaSetDevice(0);
  // CHECK_EQ(cudaStatus, cudaSuccess,
          //  "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");

//#pragma omp parallel for
//    for (int i = 0; i < 10; i++) {
//        for(int j = 0; j < 3; j++)
//        cout << "start " <<  omp_get_thread_num() << " here " << i << "end" << j << endl;
//    }
//    cout << "done" << endl;
  Minist mnist("./mnist_data", LEARNING_RATE, L2, BETA);
  mnist.train(EPOCHS, BATCH_SIZE);
}
