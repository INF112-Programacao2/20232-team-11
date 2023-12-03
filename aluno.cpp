#include "Usuario.hpp"
#include "Aluno.hpp"
#include <iostream>

Aluno::Aluno(const std::string nome, const std::string id, const std::string senha, const std::string matricula) : Usuario(nome, id, senha), _matricula(matricula){}
Aluno::Aluno() : Usuario("", "", ""), _matricula(""){};
Aluno::~Aluno(){}

std::string Aluno::get_matricula() const{
    return _matricula;
}

std::string Aluno::get_id() const{
    return _id;
}

 std::vector<Evento>& Aluno::getEventos()  {
    return _eventos;
}

// Sobrescreve o método criarEvento para adicionar eventos ao calendário
void Aluno::criarEvento( const Evento& evento) {
    _calendario.adicionarEvento(evento);
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

void Aluno::adicionarEvento(const Evento& evento) {
    _calendario.adicionarEvento(evento);
}

void Aluno::excluirEvento(const Evento& evento) {
    _calendario.excluirEvento(evento, get_id());
}

void Aluno::editarEvento(const Evento& evento) {
    _calendario.editarEvento(evento, get_id());
}

void Aluno::pesquisarEventoPorTitulo(const std::string& titulo) {
    _calendario.pesquisarEventoPorTitulo(titulo);
}

void Aluno::listarEventosTipo(const std::string& tipo) {
    _calendario.listarEventosTipo(tipo);
}

void Aluno::pesquisarEventoPorData(const std::string& data) {
    _calendario.pesquisarEventoPorData(data);
}

void Aluno::listarEventosTodos() const {
    _calendario.listarEventosTodos();
}

void Aluno::listarEventosDia(const std::string& data) {
    _calendario.listarEventosDia(data);
}

void Aluno::listarMeusEventos() const {
    _calendario.listarMeusEventos(get_id());
}

bool Aluno::operator==(const Aluno& other) const {
    return (this->get_id() == other.get_id()) &&
           (this->get_senha() == other.get_senha()) &&
           (this->get_nome() == other.get_nome()) && 
           (this->get_matricula() == other.get_matricula());
}