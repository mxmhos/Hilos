
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


#define NUM_HILOS 3
#define NUM_MENSAJES 2

void *imprimir(void *p) {

	int *index = (int *)p;

	for(int i = 0; i < NUM_MENSAJES; i ++)
	{
		printf("\nIndex: %d Hilo %ld - MESAJE %d", *index, pthread_self(), (i+1));
		usleep(100);
	}

	return NULL;
}

int main() {
	pthread_t hilos[NUM_HILOS];

	for (int i = 0; i < NUM_HILOS; i++)
		pthread_create(&hilos[i], NULL, imprimir, (void *) &i);

	for (int i = 0; i < NUM_HILOS; i++)
			pthread_join(hilos[i], NULL);

	std::cout << "no entiendo" << std::endl;

	return 0;

}





