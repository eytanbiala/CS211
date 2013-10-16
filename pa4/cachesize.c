#include <stdio.h>
#include <sys/time.h> 
#include <unistd.h>
#include "cachesize.h"
#define ARRAY_SIZE 64 * 1024 * 1024
#define SOME_ACCESS_SIZE 64 * 1024
#define SOME_LARGE_NUMBER 1024 * 1024

#define KB 1024
#define MB 1024 * 1024

int main() {
	unsigned int steps = 256 * 1024 * 1024;
	static int arr[4 * 1024 * 1024];
	int lengthMod;
	unsigned int i;
	double timeTaken;


	int sizes[] = { 
		1 * KB, 4 * KB, 8 * KB, 16 * KB, 32 * KB, 64 * KB, 128 * KB, 256 * KB,
		512 * KB, 1 * MB, 1.5 * MB, 2 * MB, 2.5 * MB, 3 * MB, 3.5 * MB, 4 * MB, 4.5 * MB, 5 * MB, 5.5 * MB, 6 * MB
	};
	int results[sizeof(sizes)/sizeof(int)];
	int s;
	struct timeval st;
	struct timeval et;
	time_t start, end;

	for (s = 0; s < sizeof(sizes)/sizeof(int); s++) {
		lengthMod = sizes[s] - 1;
	    // start = clock();
		gettimeofday(&st,NULL);
		for (i = 0; i < steps; i++) {
			arr[(i * 16) & lengthMod] *= 10;
			arr[(i * 16) & lengthMod] /= 10;
		}
		gettimeofday(&et,NULL);

		timeTaken = (et.tv_sec * 1000000 + et.tv_usec) - (st.tv_sec *1000000 + st.tv_usec);
		printf("%d, %.8f \n", sizes[s] / 1024, timeTaken);
	}
	printf("Cache size: %.5i \n", sizes[sizeof(sizes)]);

	return 0;
}