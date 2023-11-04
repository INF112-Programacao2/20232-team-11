#include "Usuario.hpp"
#include <iostream>

Usuario::Usuario(const std::string id, const std::string senha) : _id(id), _senha(senha){}
Usuario::~Usuario(){}


void Usuario::set_senha(const std::string& senha){
    _senha = senha;
}

std::string Usuario::get_senha() const{
    return _senha;
}

std::string Usuario::get_id() const{
    return _id;
}
// Implementação padrão vazia para criarEvento
void Usuario::criarEvento(Calendario& calendario, const Evento& evento) {
    // Não faz nada por padrão
}


