#include <stdio.h>
#include <string.h>

// Nível de lixo em que o container precisa ser esvaziado
#define NIVEL_CRITICO_LIXO 80

void verificarContainer(char *local, int *nivelLixo);
void avaliarESolicitarColeta(char *local, int nivelLixo);
void solicitarColetaAutonoma(char *local);
void coletaEspecial(char *local, char *tipoResiduos);

int main() {
    printf("Sistema de Gestão de Resíduos de Zenithia (SGR)\n");

    // Variáveis para armazenar os níveis de lixo
    int nivelRuaFlores, nivelAvenidaCentral, nivelPracaLiberdade;

    // Verificando diferentes locais e obtendo o nível de lixo
    verificarContainer("Rua das Flores", &nivelRuaFlores);
    verificarContainer("Avenida Central", &nivelAvenidaCentral);
    verificarContainer("Praça da Liberdade", &nivelPracaLiberdade);

    // Avaliando e solicitando coleta
    avaliarESolicitarColeta("Rua das Flores", nivelRuaFlores);
    avaliarESolicitarColeta("Avenida Central", nivelAvenidaCentral);
    avaliarESolicitarColeta("Praça da Liberdade", nivelPracaLiberdade);

    // Solicitando coleta especial
    coletaEspecial("Hospital Geral", "lixo hospitalar");
    coletaEspecial("Centro Tecnológico", "eletrônicos");

    return 0;
}

// Função para verificar o nível de lixo do container e atribuir o valor à variável fornecida
void verificarContainer(char *local, int *nivelLixo) {
    printf("\nVerificando container em %s...\n", local);

    // Simulando o nível de lixo (substituir por um sensor real em um sistema real)
    if (strcmp(local, "Rua das Flores") == 0) {
        *nivelLixo = 30;  // Exemplo: 30% de lixo
    } else if (strcmp(local, "Avenida Central") == 0) {
        *nivelLixo = 80;  // Exemplo: 80% de lixo
    } else if (strcmp(local, "Praça da Liberdade") == 0) {
        *nivelLixo = 100; // Exemplo: 100% de lixo
    } else {
        *nivelLixo = 0;   // Valor padrão para outros locais
    }

    printf("O container em %s está com %d%% de lixo.\n", local, *nivelLixo);
}

// Função para avaliar o nível de lixo e solicitar a coleta se necessário
void avaliarESolicitarColeta(char *local, int nivelLixo) {
    if (nivelLixo >= NIVEL_CRITICO_LIXO) {
        printf("O container em %s atingiu o nível crítico de lixo.\n", local);
        solicitarColetaAutonoma(local);
    } else {
        printf("O container em %s ainda não precisa de coleta.\n", local);
    }
}

// Função para solicitar a coleta automatizada
void solicitarColetaAutonoma(char *local) {
    printf("Veículo autônomo a caminho para coletar o lixo em %s.\n", local);
}

// Função para solicitar a coleta especial
void coletaEspecial(char *local, char *tipoResiduos) {
    printf("\nSolicitando coleta especial para %s em %s.\n", tipoResiduos, local);
}