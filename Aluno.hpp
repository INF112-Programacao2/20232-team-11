#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <string>
#include <vector>
#include "Usuario.hpp"
#include "Evento.hpp"

class Aluno : public Usuario{
private:
    const std::string _id;
    const std::string _matricula;
public:
    std::string get_matricula() const;
    std::string get_id() const override;
};

#endif