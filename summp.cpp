#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <math.h>
#include <omp.h>

using namespace std;
#define MAX 10000000

int main()
{
    double start2 = omp_get_wtime(); 
    srand(time(NULL));
    long long sum = 0;
    long long* arr = new long long[MAX];
    for (int i = 0; i < MAX; i++){
        arr[i] = (rand() % 652132448 * 46454 + (2154344 * sin(rand()%3245) - 122345235 * tan(rand()))) * 238761456 * sin(rand());
    }
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        #pragma omp for reduction (+:sum)
        for(int i = 0; i < MAX; i++)
        {
            sum += arr[i];
        }
    }
    double end2 = omp_get_wtime(); 
    cout << "Sum = " << sum;
    printf("\nWork took %f miliseconds\n", (end2 - start2) * 1000);

	return 0;
}
