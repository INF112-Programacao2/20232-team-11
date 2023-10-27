#include "Usuario.hpp"
#include "Professor.hpp"
#include <iostream>

Professor::Professor(const std::string id, const std::string senha) : Usuario(id, senha){}
Professor::~Professor(){}

std::string Professor::get_senha() const{
    return _senha;
}

std::string Professor::get_id() const{
    return _id;
}




