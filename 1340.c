#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

typedef struct{
    int arr[MAX];
    int topo;
}pilha;

typedef struct{
    int arr[MAX];
    int comeco,fim;
}fila;

typedef struct{
    int arr[MAX];
    int tamanho;
} prioridade;

void iniciapilha(pilha*s);
int pilhavazia(pilha* s);
void pushpilha(pilha*s,int x);
int poppilha(pilha*s);
void iniciafila(fila*q);
int filavazia(fila*q);
void pushfila(fila*q,int x);
int popfila(fila* q);
void iniciafp(prioridade*fp);
int fpvazia(prioridade*fp);
void pushfp(prioridade*fp,int x);
int popfp(prioridade*fp);

int main(){
    int n;
    while (scanf("%d",&n)!=EOF){
        pilha stack;
        fila queue;
        prioridade fp;
        iniciapilha(&stack);
        iniciafila(&queue);
        iniciafp(&fp);
        int ehpilha=1,ehfila=1,ehfp=1;
        for (int i=0;i<n;i++){
            int op;
            scanf("%d",&op);
            if (op==1){
                int x;
                scanf("%d",&x);
                if (ehpilha){ 
                    pushpilha(&stack, x);
                }
                if (ehfila){
                    pushfila(&queue, x);
                }
                if (ehfp){
                    pushfp(&fp, x);
                }
            } 
            else if (op==2){
                int esperado;
                scanf("%d",&esperado);
                if (ehpilha){
                    if (pilhavazia(&stack) || poppilha(&stack)!=esperado){
                        ehpilha=0;
                    }
                }
                if (ehfila){
                    if (filavazia(&queue) || popfila(&queue)!=esperado){
                        ehfila=0;
                    }
                }
                if (ehfp){
                    if (fpvazia(&fp) || popfp(&fp) != esperado){
                        ehfp=0;
                    }
                }
            }
        }
        if (ehpilha+ehfila+ehfp>1){
            printf("not sure\n");
        }
        else if (ehpilha){
            printf("stack\n");
        }
        else if (ehfila){
            printf("queue\n");
        }
        else if(ehfp){
            printf("priority queue\n");
        }
        else{
            printf("impossible\n");
        }
    }
    return 0;
}

void iniciapilha(pilha*s){
    s->topo=-1;
}

int pilhavazia(pilha* s){
    return s->topo==-1;
}

void pushpilha(pilha*s,int x){
    s->arr[++(s->topo)]=x;
}

int poppilha(pilha*s){
    return s->arr[(s->topo)--];
}

void iniciafila(fila*q){
    q->comeco=q->fim=0;
}

int filavazia(fila*q){
    return q->comeco==q->fim;
}

void pushfila(fila*q,int x){
    q->arr[q->fim++]=x;
}

int popfila(fila* q){
    return q->arr[q->comeco++];
}

void iniciafp(prioridade*fp){
    fp->tamanho=0;
}

int fpvazia(prioridade*fp){
    return fp->tamanho==0;
}

void pushfp(prioridade*fp,int x){
    fp->arr[fp->tamanho++]=x;
}

int popfp(prioridade*fp){
    int max=0;
    for (int i=1;i<fp->tamanho;i++){
        if (fp->arr[i]>fp->arr[max]){
            max=i;
        }
    }
    int val=fp->arr[max];
    for (int i=max;i<fp->tamanho-1;i++){
        fp->arr[i]=fp->arr[i+1];
    }
    fp->tamanho--;
    return val;
}
