#include "Aluno.hpp"

Aluno::Aluno(const std::string& id, const std::string& senha) : Usuario(id, senha) {        // Construtor
    _matricula = id;        // Matrícula do aluno é o próprio id
}

Aluno::~Aluno() {}      // Destrutor