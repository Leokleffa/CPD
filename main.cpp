#include <iostream>

#include "include/Dados.h"

int main()
{
    std::cout << "LAB 1" << std::endl;

    Dados dados;
    Timer timer;
    Estatisticas est;
    float tempo;

    for(int tamanho=2; tamanho<20; tamanho*=2){

        dados.geraVetorAleatorio(tamanho,1,tamanho);
//        dados.geraVetorOrdenado(tamanho,1,tamanho);
//        dados.geraVetorQuaseOrdenado(tamanho,1,tamanho);
//        dados.geraVetorReverso(tamanho,1,tamanho);

        std::cout << "N " << tamanho;
        std::cout.flush();

        timer.iniciaContagem();

//        est = dados.ordenaComBubbleSort();
//        est = dados.ordenaComInsertionSort();
//        est = dados.ordenaComShellSort(SHELL59);
//        est = dados.ordenaComShellSort(KNUTH71);
//        est = dados.ordenaComShellSort(TOKUDA92);
        est = dados.ordenaComShellSort(CIURA01);

        tempo = timer.finalizaContagem();

        std::cout << " tempo " << tempo << " trocas " << est.trocas << " comparacoes " << est.comparacoes << std::endl;

        dados.imprime_registros();

        bool estaOrdenado = dados.checaSeRegistrosOrdenados();
        bool ordenacaoEstavel = dados.checaSeOrdenacaoFoiEstavel();
        std::cout << (estaOrdenado ? "Vetor ordenado" : "Vetor NAO ordenado") << " - "
                  << (ordenacaoEstavel ? "Ordenacao foi estavel" : "Ordenacao NAO foi estavel") << std::endl << std::endl;

    }

    getchar();

    return 0;
}
