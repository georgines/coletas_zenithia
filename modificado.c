#include <stdio.h>
#include <string.h>

#define NIVEL_CRITICO_LIXO 80

typedef struct
{
    char local[50];
    int nivelLixo;
} Container;

typedef struct
{
    char local[50];
    char tipoResiduos[50];
} ColetaEspecial;

void processarContainers(Container *containers, int quantidadeContainers);
void processarColetasEspeciais(ColetaEspecial *coletasEspeciais, int quantidadeColetasEspeciais);
void avaliarESolicitarColeta(char *local, int nivelLixo);
void solicitarColetaAutonoma(char *local);

int main()
{
    printf("Sistema de Gestão de Resíduos de Zenithia (SGR)\n");

    Container containers[] = {
        {"Rua das Flores", 30},
        {"Avenida Central", 80},
        {"Praça da Liberdade", 100},
    };

    ColetaEspecial coletasEspeciais[] = {
        {"Hospital Geral", "lixo hospitalar"},
        {"Centro Tecnológico", "eletrônicos"},
    };

    int quantidadeContainers = sizeof(containers) / sizeof(containers[0]);
    int quantidadeColetasEspeciais = sizeof(coletasEspeciais) / sizeof(coletasEspeciais[0]);

    processarContainers(containers, quantidadeContainers);
    processarColetasEspeciais(coletasEspeciais, quantidadeColetasEspeciais);

    return 0;
}

void processarContainers(Container *containers, int quantidadeContainers)
{
    for (int indiceContainer = 0; indiceContainer < quantidadeContainers; indiceContainer++)
    {
        char *localContainer = containers[indiceContainer].local;
        int nivelLixoContainer = containers[indiceContainer].nivelLixo;

        printf("\nVerificando container em %s...\n", localContainer);
        printf("O container em %s está com %d%% de lixo.\n", localContainer, nivelLixoContainer);
        avaliarESolicitarColeta(localContainer, nivelLixoContainer);
    }
}

void processarColetasEspeciais(ColetaEspecial *coletasEspeciais, int quantidadeColetasEspeciais)
{
    printf("\nColetas Especiais:\n");
    for (int indiceColetaEspecial = 0; indiceColetaEspecial < quantidadeColetasEspeciais; indiceColetaEspecial++)
    {
        char *localColetaEspecial = coletasEspeciais[indiceColetaEspecial].local;
        char *tipoResiduosColetaEspecial = coletasEspeciais[indiceColetaEspecial].tipoResiduos;

        printf("- Local: %s | Tipo de Resíduos: %s\n", localColetaEspecial, tipoResiduosColetaEspecial);
        printf("Solicitando coleta especial para %s em %s.\n", tipoResiduosColetaEspecial, localColetaEspecial);
    }
}

void avaliarESolicitarColeta(char *local, int nivelLixo)
{
    if (nivelLixo >= NIVEL_CRITICO_LIXO)
    {
        printf("O container em %s atingiu o nível crítico de lixo.\n", local);
        solicitarColetaAutonoma(local);
    }
    else
    {
        printf("O container em %s ainda não precisa de coleta.\n", local);
    }
}

void solicitarColetaAutonoma(char *local)
{
    printf("Veículo autônomo a caminho para coletar o lixo em %s.\n", local);
}
