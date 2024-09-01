#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
using namespace std::chrono;
#define MAX 10000000

int main()
{
    srand(time(NULL));
	auto start = high_resolution_clock::now();
    long long* arr = new long long[MAX];
    long long sum = 0;
    for (int i = 0; i < MAX; i++){
        arr[i] = (rand() % 652132448 * 46454 + (2154344 * sin(rand())- 122345235 * tan(rand()))) * 238761456 * sin(rand());
    }

    for(int i = 0; i < MAX; i++)
    {
        sum += arr[i];
    }

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
    cout << "Sum = " << sum;
	cout << "\nWork took: "
		<< duration.count() / 1000 << " miliseconds" << endl;

	return 0;
}
