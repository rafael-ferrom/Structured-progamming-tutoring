/*
 * Modulo 09 - Acesso aleatorio e estruturas em arquivos binarios
 * Module 09 - Random access and structs in binary files
 * Compilar: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 * Compile: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 * O programa cria "alunos.bin" na pasta de execucao.
 * The program creates "alunos.bin" in the working folder.
 */
#include <stdio.h>

typedef struct {
    int   ra;
    char  nome[30];        /* tamanho fixo: NUNCA char* em arquivo binario | fixed size: NEVER char* in a binary file */
    float nota;
} Registro;

int main(void) {
    const char *arq = "alunos.bin";
    Registro turma[5] = {
        {1001, "Ana",   8.5f},
        {1002, "Bruno", 6.0f},
        {1003, "Carla", 9.0f},
        {1004, "Diego", 5.5f},
        {1005, "Elisa", 7.5f}
    };

    /* --- 1. Gravando os 5 registros de uma vez (fwrite) --- */
    /* --- 1. Writing all 5 records at once (fwrite) --- */
    FILE *f = fopen(arq, "wb");
    if (f == NULL) {
        printf("Erro ao criar %s\n", arq);
        return 1;
    }
    size_t gravados = fwrite(turma, sizeof(Registro), 5, f);
    fclose(f);
    printf("Registros gravados: %lu\n", (unsigned long)gravados);
    printf("sizeof(Registro) = %lu bytes\n\n", (unsigned long)sizeof(Registro));

    /* --- 2. Tamanho do arquivo e numero de registros --- */
    /* --- 2. File size and number of records --- */
    f = fopen(arq, "rb");
    if (f == NULL) return 1;
    fseek(f, 0, SEEK_END);                       /* vai para o fim | goes to the end */
    long bytes = ftell(f);                       /* posicao = tamanho | position = size */
    printf("Tamanho do arquivo: %ld bytes\n", bytes);
    printf("Numero de registros: %ld\n\n", bytes / (long)sizeof(Registro));

    /* --- 3. Acesso aleatorio: ler DIRETO o registro 3 (indice 2) --- */
    /* --- 3. Random access: read record 3 (index 2) DIRECTLY --- */
    Registro r;
    fseek(f, 2L * (long)sizeof(Registro), SEEK_SET);
    if (fread(&r, sizeof(Registro), 1, f) == 1)
        printf("Registro de indice 2: RA %d | %s | nota %.1f\n\n", r.ra, r.nome, r.nota);

    /* --- 4. Lendo o arquivo todo do inicio --- */
    /* --- 4. Reading the whole file from the start --- */
    rewind(f);
    printf("Todos os registros:\n");
    while (fread(&r, sizeof(Registro), 1, f) == 1)
        printf("  RA %d | %-6s | %.1f\n", r.ra, r.nome, r.nota);
    fclose(f);

    /* --- 5. Atualizando o registro de indice 1 (rb+) --- */
    /* --- 5. Updating the record at index 1 (rb+) --- */
    f = fopen(arq, "rb+");
    if (f == NULL) return 1;

    long pos = 1L * (long)sizeof(Registro);
    fseek(f, pos, SEEK_SET);
    fread(&r, sizeof(Registro), 1, f);
    r.nota = 10.0f;
    fseek(f, pos, SEEK_SET);                     /* volta ao inicio do registro! | go back to the start of the record! */
    fwrite(&r, sizeof(Registro), 1, f);
    fclose(f);

    /* --- 6. Conferindo --- */
    /* --- 6. Checking --- */
    f = fopen(arq, "rb");
    if (f == NULL) return 1;
    fseek(f, pos, SEEK_SET);
    if (fread(&r, sizeof(Registro), 1, f) == 1)
        printf("\nApos atualizar: %s agora tem nota %.1f\n", r.nome, r.nota);
    fclose(f);

    return 0;
}
