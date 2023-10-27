#include "Usuario.hpp"
#include "Adminitrador.hpp"
#include <iostream>

Administrador::Administrador(const std::string id, const std::string senha) : Usuario(id, senha){}

Administrador::~Administrador(){}


std::string Administrador::get_senha() const{
    return _senha;
}

std::string Administrador::get_id() const{
    return _id;
}

