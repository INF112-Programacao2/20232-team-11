#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <string>
#include <vector>
#include <algorithm>

#include "Usuario.hpp"
#include "Evento.hpp"
#include "Calendario.hpp"


class Aluno : public Usuario{
private:
    std::string _matricula;
    std::vector<Evento> _eventos; // Eventos criados pelo aluno
    
public:
    Aluno(const std::string nome,const std::string id, const std::string senha, const std::string matricula);
    ~Aluno();
    std::string get_matricula() const;
    std::string get_id() const override;
    
    // Sobrescreve o método criarEvento para adicionar eventos ao calendário
    void criarEvento(Calendario& calendario, const Evento& evento) ;

    // Sobrescreva o método alterar_senha para permitir apenas ao aluno mudar sua própria senha
    void alterar_senha(const std::string& senha) override;
    void cadastrar() override; // Sobrescreve a função cadastrar da classe bases

    // Função para "excluir" o aluno
    void inativar() override;
    
    // Verifica se o aluno está ativo
    bool esta_ativo() const override;

    // Função para "excluir" o aluno
    void excluir(std::vector<Aluno>& alunos);

};

#endif