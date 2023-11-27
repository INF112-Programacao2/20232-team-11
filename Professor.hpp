#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Usuario.hpp"

class Professor : public Usuario {
public:
    Professor(const std::string& id, const std::string& senha);     // Construtor
    ~Professor();                                            // Destrutor
};

#endif