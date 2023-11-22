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

void Administrador::alterar_senha(const std::string& senha) {
    // Lógica para permitir que apenas o aluno mude sua própria senha
    _senha = senha;
}