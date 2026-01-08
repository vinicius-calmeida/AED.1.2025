#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Jogador{
	int saques, bloqueios, ataques, PontoS, PontoB, PontoA;
};

int main()
{
	short Njogadores;
	char nomeJogador[100];
	long S = 0;
    long B = 0;
    long A = 0;
    long TotPontoS = 0;
    long TotPontoB = 0;
    long TotPontoA = 0;
	struct Jogador jogador;
	
	scanf("%hd", &Njogadores);
	
	while(Njogadores--)
    {
		scanf("%s %d %d %d", nomeJogador, &jogador.saques, &jogador.bloqueios, &jogador.ataques);
		scanf("%d %d %d", &jogador.PontoS, &jogador.PontoB, &jogador.PontoA);
		
        S += jogador.saques;
        B += jogador.bloqueios;
        A += jogador.ataques;	
        TotPontoS += jogador.PontoS;
        TotPontoB += jogador.PontoB;
        TotPontoA += jogador.PontoA;
	}
	printf("Pontos de Saque: %.2lf %%.\n", (TotPontoS*100.)/S);
	printf("Pontos de Bloqueio: %.2lf %%.\n", (TotPontoB*100.)/B);
	printf("Pontos de Ataque: %.2lf %%.\n", (TotPontoA*100.)/A);
	
	return 0;
}
