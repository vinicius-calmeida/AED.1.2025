#include <stdio.h>

int main() {
    int n, k;
    
    while (scanf("%d %d", &n, &k) == 2) {
        int pos[1001];
        pos[0] = 0;
        
        for (int i = 1; i < n; i++) {
            scanf("%d", &pos[i]);
        }
        int diferencas[1000];
        for (int i = 1; i < n; i++) {
            diferencas[i-1] = pos[i] - pos[i-1];
        }
        for (int i = 0; i < n-2; i++) {
            for (int j = i+1; j < n-1; j++) {
                if (diferencas[i] > diferencas[j]) {
                    int temp = diferencas[i];
                    diferencas[i] = diferencas[j];
                    diferencas[j] = temp;
                }
            }
        }
        int soma = 0;
        for (int i = 0; i < n-k; i++) {
            soma += diferencas[i];
        }
        
        printf("%d\n", soma);
    }
    
    return 0;
}
