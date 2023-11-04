#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <string>
#include <vector>
#include "Usuario.hpp"
#include "Evento.hpp"

class Aluno : public Usuario{
private:
    const std::string _matricula;
    std::vector<Evento> _eventos; // Eventos criados pelo aluno
public:
    Aluno(const std::string id, const std::string senha, const std::string matricula);
    ~Aluno();
    std::string get_matricula() const;
    std::string get_id() const override;
    
    // Sobrescreve o método criarEvento para adicionar eventos ao calendário
    void criarEvento(Calendario& calendario, const Evento& evento) ;

};

#endif