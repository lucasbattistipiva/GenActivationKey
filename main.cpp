#include <iostream> // cout,cin , etc
#include <random>   // randomizar valores
#include <string>
#include <locale>   //utilizar ABNT2
#include <clocale>  //necessario para a utilizacao do locale
#include <fstream> // utilizado para criarmos o arquivo "logs.txt"
#include <chrono> //para criar diferentes resultados

std::string gerarAlfaNumericoAleatorio(int comprimento) {
    const std::string caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string resultado;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distrib(0, caracteres.size() - 1);

    for (int i = 0; i < comprimento; i++) {
        resultado += caracteres[distrib(gen)];
    }

    return resultado;
}

std::string formatarCodigo(const std::string& codigo) {
    std::string codigoFormatado;
    for (size_t i = 0; i < codigo.size(); i++) {
        codigoFormatado += codigo[i];
        if ((i + 1) % 5 == 0 && i != codigo.size() - 1) {
            codigoFormatado += "-";
        }
    }
    return codigoFormatado;
}

void escreverLog(const std::string& codigo){
    std::ofstream arquivo("logs.txt",std::ios::app);
    if(arquivo.is_open()){
        arquivo << codigo << std::endl;
        arquivo.close();
    }else{
    std::cerr << "Não foi possivel abrir o arquivo de log. " << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int comprimento = 25;
    std::string codigoAleatorio = gerarAlfaNumericoAleatorio(comprimento);
    std::string codigoFormatado = formatarCodigo(codigoAleatorio);
    std::cout << "Código de ativação : " << codigoFormatado << std::endl;

    escreverLog(codigoFormatado);

    return 0;
}
