#include <iostream>
#include <random>
#include <string>
#include <locale>
#include <clocale>

std::string gerarAlfaNumericoAleatorio(int comprimento) {
    const std::string caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string resultado;

    std::random_device rd;
    std::mt19937 gen(rd());
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

int main() {
    setlocale(LC_ALL, "Portuguese");

    int comprimento = 25;
    std::string codigoAleatorio = gerarAlfaNumericoAleatorio(comprimento);
    std::string codigoFormatado = formatarCodigo(codigoAleatorio);
    std::cout << "Código de ativação : " << codigoFormatado << std::endl;

    return 0;
}
