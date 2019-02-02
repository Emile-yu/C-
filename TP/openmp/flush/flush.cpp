#include <iostream>
#include <omp.h>
using namespace std;
int main() {
    int data, flag=0;
    #pragma omp parallel sections num_threads(2) shared(data, flag)
    {
        #pragma omp section // thread 0
        {
            #pragma omp critical
            cout << "thread:" << omp_get_thread_num() << endl;
            for(int i=0; i<10000; ++i)
                ++data;
            #pragma omp flush(data);//将变量修改的值写入内存
            flag = 1;
            #pragma omp flush(flag);//将变量修改的值写入内存
        }
        #pragma omp section // thread 1
        {
            while(!flag) ;
            #pragma omp critical
            cout << "thread:" << omp_get_thread_num() << endl;
            -- data;
            cout << data << endl;
        }
    }
    return 0;
}