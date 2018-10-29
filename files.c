#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int genRand(){
	int file;
	file = open("/dev/urandom", O_RDONLY);
	int out;
	read(file, &out, 4);
	close(file);
	return out;
}
int main(){
	int arr[10];
	printf("Generating Random Numbers:\n");
	for (int i = 0; i < 10; i++){
		arr[i] = genRand();
		printf("Random number %d: %d\n",i,arr[i]);
	}

	int file1 = open("file.txt", O_WRONLY,0777);
	printf("\nWriting numbers to file.txt...\n");
	write(file1, &arr, 40);

	printf("Reading numbers from file.txt...\n\n");
	int arr1[10];
	int file2 = open("file.txt", O_RDONLY,0777);
	read(file2, &arr1, 40);

	printf("Verification that written values were the same:\n");
	for (int i = 0; i < 10; i++){
		printf("Random number %d: %d\n",i,arr1[i]);
	}


	close(file1);
	close(file2);
	return 0;
}

