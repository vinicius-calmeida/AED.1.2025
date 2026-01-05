#include <stdio.h>
#include <stdlib.h>

int main(){
    int v[7], n, dados[100000], maior=0, obj=0, movimentos=0, mlhr=-1;
    
    memset(v, 0, sizeof(v));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dados[i]);
    }

    for (int obj = 1; obj < 8; obj++)
    {
        movimentos = 0;
        for (int i = 0; i < n; i++)
        {
            if (dados[i] == (7-obj))
            {
                movimentos+=2;
            }
            if (dados[i] != obj && dados[i] != (7-obj))
            {
                movimentos+=1;
            }
        }
        if (mlhr == -1 || movimentos < mlhr)
        {
            mlhr = movimentos;
        }
        
    }
    printf("%d\n", mlhr);
}
