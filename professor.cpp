#include "Usuario.hpp"
#include "Professor.hpp"


#include <iostream>

Professor::Professor(const std::string nome, const std::string& id, const std::string& senha) : Usuario(nome, id, senha){}
Professor::~Professor(){}

std::string Professor::get_senha() const{
    return _senha;
}

std::string Professor::get_id() const{
    return _id;
}
void Professor::adicionarAlunoTurma(const std::string& idAluno) {
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

void Professor::alterar_senha(const std::string& senha) {
    // Lógica para permitir que apenas o professor mude sua própria senha
    _senha = senha;
}

// Função para "excluir" o aluno
void Professor::excluir(std::vector<Professor>& professores) {
    // Encontrar o iterador para o aluno no vetor
    auto it = std::find(professores.begin(), professores.end(), *this);

    if (it != professores.end()) {
        // Remover o aluno do vetor
        professores.erase(it);

        // Marcar o aluno como inativo
        Usuario::inativar();

        std::cout << "Professor excluído com sucesso." << std::endl;
    } else {
        std::cout << "Professor não encontrado." << std::endl;
    }
}