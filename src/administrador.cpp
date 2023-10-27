#include "Usuario.hpp"
#include "Adminitrador.hpp"
#include <iostream>

std::string Administrador::get_senha() const{
    return _senha;
}

std::string Administrador::get_id() const{
    return _id;
}