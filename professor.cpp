#include "Usuario.hpp"
#include "Professor.hpp"
#include <iostream>

Professor::Professor(const std::string id, const std::string senha) : Usuario(id, senha){}
Professor::~Professor(){}

std::string Professor::get_senha() const{
    return _senha;
}

std::string Professor::get_id() const{
    return _id;
}
void Professor::adicionarAlunoTurma(const std::string idAluno) {
    _turma.push_back(idAluno);
}
void Professor::criarEventoTurma(std::string titulo, std::string descricao, tm DataHora, std::string local) {
    // Crie um evento com a marca de que é um evento da turma
    Evento evento(titulo, descricao, DataHora, local);
    _eventos.push_back(evento);
}

// Sobrescreve o método criarEvento para adicionar eventos ao calendário
void Professor::criarEvento(Calendario& calendario, const Evento& evento) {
    calendario.adicionarEvento(evento);
}




