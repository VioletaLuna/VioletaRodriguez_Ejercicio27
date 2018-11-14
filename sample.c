#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

//Definimso el número de muestras que queremos


double gaussiana (int N, double media, double desviacion);
void exportarDatos(double* muestram , int N);

int main()
{
	int N;
	float mu;
	float sigma;
	printf("Número de muestras: ");
	scanf("%i",&N );
	printf("Valor medio: ");
	scanf("%g",&mu );
	printf("Desviación estandar: ");
	scanf("%g",&sigma );
	double *muestra;
	muestra = malloc(N*sizeof(double));

	for(int i=0; i < N; i++)
	{
		muestra[i] = gaussiana(N, mu, sigma);
	}

	exportarDatos(muestra, N);	
	
	return 0;

}


//Genera un numero con una distribución normal de la media y la desivación dadas por paramatro.
double gaussiana (int N, double media, double desviacion)
{
	double z = 0;
	int n = 1000;
	//Usamos el teorem del límite central para generar un número aletorio con media 0 y desviación estandar 0.
	for (int i = 0; i < n; ++i)
	{
		z += 0.5 - drand48();
	}
	//Desestandarizamos z. Rercoando la las propiedades del valor esperado y la varianza para suma de variables aletarias identicas. 
	double m = sqrt(N);
	double desv = desviacion/m;
	double med = media;
	double num = z*desv + med;
	
	return num;
}

void exportarDatos(double* muestra, int N)
{
	
	FILE *arch;
	arch= fopen("sample.dat", "w");
	if (!arch)
	{
		printf("Problemas abriendo el archivos %s\n", "sample.dat" );
		exit(1);
	}

	for (int i = 0; i < N; ++i)
	{

		fprintf(arch, "%lf \n", muestra[i]);
	}

	fclose(arch);
}

