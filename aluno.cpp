#include "Usuario.hpp"
#include "Aluno.hpp"
#include <iostream>

Aluno::Aluno(const std::string id, const std::string senha, const std::string matricula) : Usuario(id, senha), _matricula(matricula){}
Aluno::~Aluno(){}

std::string Aluno::get_matricula() const{
    return _matricula;
}

std::string Aluno::get_id() const{
    return _id;
}

// Sobrescreve o método criarEvento para adicionar eventos ao calendário
void Aluno::criarEvento(Calendario& calendario, const Evento& evento) {
    calendario.adicionarEvento(evento);
}


