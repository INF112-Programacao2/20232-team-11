#include "Usuario.hpp"
#include "Aluno.hpp"
#include <iostream>

Aluno::Aluno(const std::string nome, const std::string id, const std::string senha, const std::string matricula) : Usuario(nome, id, senha), _matricula(matricula){}
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

void Aluno::alterar_senha(const std::string& senha) {
    // Lógica para permitir que apenas o aluno mude sua própria senha
    _senha = senha;
}

void Aluno::inativar() {
    Usuario::inativar();
}

bool Aluno::esta_ativo() const {
   return Usuario::esta_ativo();
}

// Função para "excluir" o aluno
void Aluno::excluir(std::vector<Aluno>& alunos) {
    // Encontrar o iterador para o aluno no vetor
    auto it = std::find(alunos.begin(), alunos.end(), *this);

    if (it != alunos.end()) {
        // Remover o aluno do vetor
        alunos.erase(it);

        // Marcar o aluno como inativo
        Usuario::inativar();

        std::cout << "Aluno excluído com sucesso." << std::endl;
    } else {
        std::cout << "Aluno não encontrado." << std::endl;
    }
}