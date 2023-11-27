#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Usuario.hpp"

class Aluno : public Usuario {
private:
    std::string _matricula;     // Matrícula do aluno

public:
    Aluno(const std::string& id, const std::string& senha);         // Construtor
    ~Aluno();                                        // Destrutor
};

#endif