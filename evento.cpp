#include "Evento.hpp"
#include <iostream>
#include <ctime>

Evento::Evento(std::string titulo, std::string descricao, tm DataHora, std::string local) : _titulo(titulo), _descricao(descricao), _DataHora(&DataHora), _local(local){}
Evento::~Evento(){}

void Evento::set_titulo(std::string titulo){
    _titulo = titulo;
}

std::string Evento::get_titulo(){
    return _titulo;
}

void Evento::set_descricao(std::string descricao){
    _descricao = descricao;
}

std::string Evento::get_descricao(){
    return _descricao;
}

void Evento::set_DataHora(tm DataHora){
    _DataHora = &DataHora;
}

tm Evento::get_DataHora(){
    return *_DataHora;
}

void Evento::set_local(std::string local){
    _local = local;
}

std::string Evento::get_local(){
    return _local;
}
