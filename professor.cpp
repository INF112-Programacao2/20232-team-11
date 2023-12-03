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

 std::vector<Evento>& Professor::getEventos()  {
    return _eventos;
}

void Professor::adicionarAlunoTurma(const std::string& idAluno) {
    _turma.push_back(idAluno);
}
/*void Professor::criarEventoTurma(const std::string& tipo, const std::string& titulo, const std::string& descricao, const std::string& data, const std::string& hora, const std::string& local, const std::string& criador) {
    // Crie um evento com a marca de que é um evento da turma
    Evento evento(tipo ,titulo, descricao, DataHora, local);
    _eventos.push_back(evento);
}*/

// Sobrescreve o método criarEvento para adicionar eventos ao calendário
void Professor::criarEvento(const Evento& evento) {
    _calendario.adicionarEvento(evento);
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
void Professor::adicionarEvento(const Evento& evento) {
    _calendario.adicionarEvento(evento);
}

void Professor::excluirEvento(const Evento& evento) {
    _calendario.excluirEvento(evento, get_id());
}

void Professor::editarEvento(const Evento& evento) {
    _calendario.editarEvento(evento, get_id());
}

void Professor::pesquisarEventoPorTitulo(const std::string& titulo) {
    _calendario.pesquisarEventoPorTitulo(titulo);
}

void Professor::listarEventosTipo(const std::string& tipo) {
    _calendario.listarEventosTipo(tipo);
}

void Professor::pesquisarEventoPorData(const std::string& data) {
    _calendario.pesquisarEventoPorData(data);
}

void Professor::listarEventosTodos() const {
    _calendario.listarEventosTodos();
}

void Professor::listarEventosDia(const std::string& data) {
    _calendario.listarEventosDia(data);
}

void Professor::listarMeusEventos() const {
    _calendario.listarMeusEventos(get_id());
}