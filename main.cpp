#include <iostream>
#include <string>
#include <clocale>
#include <Windows.h>
#include "CalcMedia.h"

//verifica se é um número inteiro caso contrário retorna erro.
bool numInteiroValido(const std::string& str) {
	if (str.empty() || (str[0] == '-' && str.length() == 1)) {
		return false;
	}

	for (char c : str) {
		if (!std::isdigit(c) && !(c == '-' && &c == &str[0])) {
			return false;
		}
	}

	return true;
}

//verifica se é um número válido (caso seja caracter retorna erro) e inválida caso o usuário digitar mais de um ponto.
bool numeroValido(const std::string& str) {
	if (str.empty()) return false;

	bool pontoEncontrado = false;
	bool numeroAntesDoPonto = false;

	for (size_t i = 0; i < str.length(); ++i) {
		char c = str[i];

		if (c == '.') {

			if (pontoEncontrado || i == 0 || i == str.length() - 1) {
				return false;
			}
			pontoEncontrado = true;
		}
		else if (!std::isdigit(c)) {
			return false;
		}
		else {
			if (pontoEncontrado) {
				numeroAntesDoPonto = true;
			}
		}
	}

	if (pontoEncontrado && !numeroAntesDoPonto) {
		return false;
	}

	return true;
}


int main() {

	std::setlocale(LC_ALL, "Portuguese"); //comando para usar acentuação

	CalculadoraMedia calc; //chamada da classe
	std::string Opcao;

	do {

		std::cout << "*************************CALCULADORA DE MÉDIAS***************************\n";
		std::cout << "\nLEMBRETE: Aprovação somente com nota acima de 7\n";

		int qtdNotas;
		std::string inputQtdNotas;
		bool qtdValida = false;

		while (!qtdValida) { //enquanto a quantidade for válida é executado o loop
			std::cout << "\nDigite a quantidade de notas que deseja obter a média: " << "\n";
			std::getline(std::cin, inputQtdNotas);  //obtem a quantidade em string

			if (numInteiroValido(inputQtdNotas)) { //verifica se é número inteiro válido
				try {
					qtdNotas = std::stoi(inputQtdNotas);  //converte a string para inteiro
					if (qtdNotas > 0) {
						qtdValida = true;  //caso seja válidado sai do loop
					}
					else {
						std::cout << "Por favor, insira um número maior que 0.\n"; //caso seja 0 ou número negativo da erro
					}
				}
				catch (const std::invalid_argument& e) {
					std::cout << "Entrada inválida. Tente novamente.\n"; //inválida a entrada caso não seja númerica
				}
			}
			else {
				std::cout << "Entrada inválida. Por favor, digite apenas números inteiros.\n";//inválida a entrada caso não seja um numero inteiro
			}
		}

		std::cout << "\n";

		for (int i = 0; i < qtdNotas; i++) { //loop para executar a quantidade de notas digitada pelo usuário
			float Notas;
			std::string inputNota;
			bool notaValida = false;

			while (!notaValida) { //loop q continua somente se a nota for válida
				std::cout << "Digite a nota " << i + 1 << ": ";
				std::getline(std::cin, inputNota);

				if (numeroValido(inputNota)) { //verificada se a entrada é um número válido
					try {
						Notas = std::stof(inputNota);  //converte a string para um float
						calc.adicionarNota(Notas);   //adiciona a nota na calculadora
						notaValida = true;
					}
					catch (const std::invalid_argument& e) {
						std::cout << "Entrada inválida. Tente novamente.\n"; //falha caso a conversao para float de errado.
					}
				}
				else {//caso não seja um número válido resulta em falha
					std::cout << "Entrada inválida. Use apenas números e ponto para separar a casa decimal.\n";
				}
			}
		}

		calc.exibirResultado();

		std::cout << "*************************************************************************\n";


		bool entradaValida = false;

		while (!entradaValida) { //continua apos entrada válida fornecida
			std::cout << "\nDeseja realizar outro cálculo de média? (S/N): ";
			std::getline(std::cin, Opcao);

			if (Opcao == "S" || Opcao == "s") { //caso seja "S" ou "s" a calculadora é reiniciada
				entradaValida = true;
				std::cout << "\nAguarde enquanto a calculadora é reiniciada...\n";
				calc.limparNotas();
				Sleep(1000);
				system("CLS"); //apaga os resultados anteriores (só funciona em OS Windows)

			}
			else if (Opcao == "N" || Opcao == "n") {
				entradaValida = true;
				std::cout << "\nEncerrando a calculadora! Obrigado por utilizar.\n";
				Sleep(1000);
				return 0; //sai do programa caso a entrada seja "N" ou "n"
			}
			else {
				std::cout << "Opção inválida. Por favor, insira 'S' para continuar ou 'N' para encerrar.\n";
			}
		}

	} while (Opcao != "N" && Opcao != "n"); // o loop continua enquanto a opção não for "N" ou "n"

	return 0;
}