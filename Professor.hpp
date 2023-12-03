#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Usuario.hpp"
#include "Evento.hpp"
#include "Calendario.hpp"

#include <algorithm>

class Professor : public Usuario{
private:
    std::vector<std::string> _turma; // Lista de IDs dos alunos na turma
    std::vector<Evento> _eventos;  // Lista de eventos criados pelo professor
    Calendario _calendario;           // Instância de Calendario
    void adicionarAlunoTurma(const std::string& idAluno);
    void criarEventoTurma(const std::string& tipo, const std::string& titulo, const std::string& descricao, const std::string& data, const std::string& hora, const std::string& local, const std::string& criador);
public:
    Professor(const std::string nome, const std::string& id, const std::string& senha);
    ~Professor();
    std::string get_senha() const override;
    std::string get_id() const override;
    std::vector<Evento>& getEventos() ;
    void criarEvento(const Evento& evento);

    // Sobrescreva o método alterar_senha para permitir apenas ao professor mudar sua própria senha
    void alterar_senha(const std::string& senha) override;
    // Função para "excluir" o professor
    void excluir(std::vector<Professor>& professores);  

    void adicionarEvento(const Evento& evento);
    void excluirEvento(const Evento& evento);
    void editarEvento(const Evento& evento);
    void pesquisarEventoPorTitulo(const std::string& titulo);
    void listarEventosTipo(const std::string& tipo);
    void pesquisarEventoPorData(const std::string& data);
    void listarEventosTodos() const;
    void listarEventosDia(const std::string& data);
    void listarMeusEventos() const;
};
   



#endif