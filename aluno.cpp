#include "Aluno.hpp"

Aluno::Aluno(const std::string& tipo, const std::string& id, const std::string& senha) : Usuario(tipo, id, senha) {        // Construtor
    _matricula = id;   // Matrícula do aluno é o próprio id
}

Aluno::~Aluno() {}      // Destrutor

//metodo get para matricula
std::string Aluno::getMatricula() const { // Retorna a matrícula do aluno
    return _matricula;
}