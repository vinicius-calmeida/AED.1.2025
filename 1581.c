#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() 
{
	unsigned short qtdcasos, qtdpessoas;
	char palavraAtual[21], palavraAnterior[21];
	bool idiomaIngles;

	scanf("%hu", &qtdcasos);

	while (qtdcasos--)
	{
		scanf("%hu", &qtdpessoas);

		scanf(" %s", palavraAtual);

		qtdpessoas--;
		idiomaIngles = false;
		strcpy(palavraAnterior, palavraAtual);

		while (qtdpessoas--)
		{
			if (strcmp(palavraAtual, palavraAnterior) != 0 && idiomaIngles == false)
				idiomaIngles = true;
			else
				strcpy(palavraAnterior, palavraAtual);

			scanf(" %s", palavraAtual);
		}

		if (idiomaIngles)
			printf("ingles\n");
		else
			printf("%s\n", palavraAtual);

		idiomaIngles = false;
	}

	return 0; 
}
