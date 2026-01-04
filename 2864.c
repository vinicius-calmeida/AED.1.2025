#include <stdio.h>

int main(){
    double a,b,c;
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%lf",&a);
        scanf("%lf",&b);
        scanf("%lf",&c);
        printf("%.2lf\n",-1*((b*b)-(4*a*c))/(4*a));
    }
}
