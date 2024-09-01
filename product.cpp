#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
using namespace std::chrono;
int main()
{
    srand(time(NULL));
	auto start = high_resolution_clock::now();
    long long product = 1;
	long long arr[10];
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
        arr[i] = ((rand() % 6 + (2 * sin(rand())- 2 * cos(rand()))) *5 * sin(rand()));
    }

    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        product *= arr[i];
    }

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
    cout << "Product = " << product;
	cout << "\nWork took: "
		<< duration.count() / 1000 << " miliseconds" << endl;
    cout << arr[0]<<endl;
    cout << arr[1];

	return 0;
}
