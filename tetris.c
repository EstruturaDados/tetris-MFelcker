#include <stdio.h>

typedef struct {
    char tipo; // I, O, T, L
    int id;    // Único
} Peca;

#define MAX 5

typedef struct {
    Peca pecas [MAX];
    int inicio;
    int fim;
    int total;
} Fila;

void inicializaFila(Fila* f) {
    f->inicio = 0;
    f->fim = -1;
    f->total = 0;
}

int filaVazia(Fila* f) {
    return (f->total == 0);
}

int filaCheia(Fila* f) {
    return (f->total == MAX);
}

void inserir(Fila* f, Peca p) {
    if (filaCheia(f)) {
        printf("Fila cheia! Não é possível inserir nova peça.\n");
        return;
    }
    f->pecas[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
    printf("Peça inserida: Tipo %c, ID %d\n", p.tipo, p.id);
}

void remover(Fila *f, Peca *p) {
    if (filaVazia(f)) {
        printf("Fila vazia! Não é possível remover peça.\n");
        return;
    }
    *p = f->pecas[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
    printf("Peça removida: Tipo %c, ID %d\n", p->tipo, p->id);
}

void mostrarFila(Fila* f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Peças na fila:\n");
    for (int i = 0; i < f->total; i++) {
        int index = (f->inicio + i) % MAX;
        printf("Tipo: %c, ID: %d\n", f->pecas[index].tipo, f->pecas[index].id);
    }
}

int main() {

    Fila f;
    inicializaFila(&f);

    Peca p1 = {'I', 1};
    Peca p2 = {'O', 2};
    Peca p3 = {'T', 3};
    Peca p4 = {'L', 4};
    Peca p5 = {'I', 5};
    inserir(&f, p1);
    inserir(&f, p2);
    inserir(&f, p3);
    inserir(&f, p4);
    inserir(&f, p5);

    mostrarFila(&f);

    Peca removida;
    remover(&f, &removida);
    printf("Peça removida: Tipo %c, ID %d", removida.tipo, removida.id);

    mostrarFila(&f);

    return 0;

}