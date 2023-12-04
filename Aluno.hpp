#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Usuario.hpp"
#include <string>
#include <iostream>

//classe aluno
class Aluno : public Usuario {
private:
    std::string _matricula;  // Matrícula do aluno

public:
    Aluno(const std::string& tipo, const std::string& id, const std::string& senha); // Construtor
    ~Aluno();   // Destrutor

    std::string getMatricula() const;  // Retorna a matrícula do aluno
};

#endif