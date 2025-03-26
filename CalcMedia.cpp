#include "CalcMedia.h"

void CalculadoraMedia::adicionarNota(float nota) {
	Notas.push_back(nota); //adiciona quantidade ao vetor
}

float CalculadoraMedia::calcularMedia() {
	if (Notas.empty()) {
		return 0; //retorna 0 se o vetor estiver vazio
	}
	float soma = 0;
	for (float nota : Notas) { //percorre todo o vetor notas
		soma += nota;
	}
	return soma / Notas.size(); //calcula e retorna as notas
}

void CalculadoraMedia::exibirResultado() {

	float resultado = calcularMedia(); //recebe a média 

	std::cout << "\nMédia: " << std::fixed << std::setprecision(1) << resultado << "\n"; //print a média com 1 casa decimal
	if (resultado >= 7) {
		std::cout << "Aluno aprovado!" << std::endl;
	}
	else {
		std::cout << "Aluno reprovado!" << std::endl;
	}
}

void CalculadoraMedia::limparNotas() {
	Notas.clear(); //limpa o vetor notas
}