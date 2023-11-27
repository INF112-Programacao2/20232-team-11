#include "Usuario.hpp"
#include <iostream>

Usuario::Usuario(const std::string& id, const std::string& senha) : _id(id), _senha(senha) {}       //construtor

Usuario::~Usuario() {}      //destrutor

std::string Usuario::getId() const {        
    return _id; 
}

std::string Usuario::getSenha() const {
    return _senha;
}

void Usuario::setSenha(const std::string& senha) {
    _senha = senha;
}

void Usuario::criarEvento(const TipoEvento& tipo, const std::string& titulo, const std::string& descricao, const std::string& data, const std::string& hora, const std::string& local, const std::string& criador){
    Evento evento(tipo, titulo, descricao, data, hora, local, criador);     //cria um evento
    std::cout << "Evento criado com sucesso!" << std::endl;
}

bool Usuario::fazerLogin(const std::string& id, const std::string& senha){      
    if(id == _id && senha == _senha){           //verifica se o id e a senha estao corretos
        std::cout << "Login realizado com sucesso!" << std::endl;
        return true;
    }
    else{
        std::cout << "Login ou senha incorretos!" << std::endl;
        return false;
    }
}



