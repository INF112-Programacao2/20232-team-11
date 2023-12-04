#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Usuario.hpp"

//classe administrador
class Administrador : public Usuario {
public:
    Administrador(const std::string& tipo, const std::string& id, const std::string& senha);  // Construtor
    ~Administrador();    // Destrutor
};

#endif