#include "Notificacoes.hpp"
#include <iostream>

Notificacoes::Notificacoes(std::string mensagem) : _mensagem(mensagem){}
Notificacoes::~Notificacoes(){}

std::string Notificacoes::get_mensagem() const{
    return _mensagem;
}

void Notificacoes::set_mensagem(const std::string& mensagem){
    _mensagem = mensagem;
}


