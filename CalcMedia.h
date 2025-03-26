#include <iostream>
#include <iomanip>
#include <vector>

class CalculadoraMedia {

private:
	std::vector<float> Notas; //vetor que armazena as notas

public:
	void adicionarNota(float Nota);
	float calcularMedia();
	void exibirResultado();
	void limparNotas();
};