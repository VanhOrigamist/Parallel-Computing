    #include <stdio.h>
    #include <chrono>
    #include <omp.h>
    #include <iostream>
    #include <cstdlib>
    #include <time.h>
    #include <math.h>
    using namespace std;
    using namespace std::chrono;
    #define MAX 200000000
    int main()
    {
        srand(time(NULL)); 
        long long sum = 0;
        long long* arr = new long long[MAX];
        for (int i = 0; i < MAX; i++){
            arr[i] = (rand() % 6 * 46 + (215 * sin(rand()%32) - 12 * tan(rand()))) * 56 * sin(rand());
            
        }

        // Sequential Computing
        auto start1 = high_resolution_clock::now();
        for(int i = 0; i < MAX; i++)
            {
                sum += arr[i];
            }
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>((stop1 - start1));
        cout << "Sum = " << sum;
        cout << "\nSequential Computing took: "
            << double(duration1.count())/1000 << " miliseconds" << endl;


        // Parallel Computing w/ OpenMP using Reduction
        sum = 0;
        double start2 = omp_get_wtime(); 
        omp_set_num_threads(10);
        #pragma omp parallel
        {
            #pragma omp for reduction (+:sum)
            for(int i = 0; i < MAX; i++)
            {
                sum += arr[i];
            }
        }
        double end2 = omp_get_wtime(); 
        printf("Parallel Computing took %f miliseconds\n", (end2 - start2)*1000 );

        return 0;
    }

