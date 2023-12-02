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
    void adicionarAlunoTurma(const std::string& idAluno);
    void criarEventoTurma(std::string titulo, std::string descricao, tm DataHora, std::string local);
public:
    Professor(const std::string nome, const std::string& id, const std::string& senha);
    ~Professor();
    std::string get_senha() const override;
    std::string get_id() const override;
    void criarEvento(Calendario& calendario, const Evento& evento);

    // Sobrescreva o método alterar_senha para permitir apenas ao professor mudar sua própria senha
    void alterar_senha(const std::string& senha) override;
    // Função para "excluir" o professor
    void excluir(std::vector<Professor>& professores);  
};
   



#endif