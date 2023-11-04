#include "Calendario.hpp"
#include <iostream>
#include <iomanip>

Calendario::Calendario(std::vector<Evento> eventos) : _eventos(eventos){}
Calendario::~Calendario(){}

void Calendario::adicionarEvento(Evento evento){
    _eventos.push_back(evento);
}

void Calendario::excluirEvento(Evento evento){
    for(int i = 0; i < _eventos.size(); i++){
        if(_eventos[i].get_titulo() == evento.get_titulo()){
        }
    }
}

void Calendario::editarEvento(Evento evento){
    for(int i = 0; i < _eventos.size(); i++){
        if(_eventos[i].get_titulo() == evento.get_titulo()){
            _eventos[i] = evento;
        }
    }
}

void Calendario::pesquisarEvento(std::string titulo){   //perquisar por titulo
    for(int i = 0; i < _eventos.size(); i++){
        if(_eventos[i].get_titulo() == titulo){
            std::cout << "Titulo: " << _eventos[i].get_titulo() << std::endl;
            std::cout << "Descricao: " << _eventos[i].get_descricao() << std::endl;
            std::cout << "Data: " << _eventos[i].get_DataHora().tm_mday << "/" << _eventos[i].get_DataHora().tm_mon << "/" << _eventos[i].get_DataHora().tm_year << std::endl;
            std::cout << "Hora: " << std::setfill('0') << std::setw(2) << _eventos[i].get_DataHora().tm_hour << ":" << std::setfill('0') << std::setw(2) << _eventos[i].get_DataHora().tm_min << std::endl;
            std::cout << "Local: " << _eventos[i].get_local() << std::endl;
        }else{
            std::cout << "Nao ha eventos com esse titulo" << std::endl;
        }
    }
}

void Calendario::pesquisarEvento(tm data){   //pesquisar por data
    for(int i = 0; i < _eventos.size(); i++){
        if(_eventos[i].get_DataHora().tm_mday == data.tm_mday && _eventos[i].get_DataHora().tm_mon == data.tm_mon && _eventos[i].get_DataHora().tm_year == data.tm_year){
            std::cout << "Titulo: " << _eventos[i].get_titulo() << std::endl;
            std::cout << "Descricao: " << _eventos[i].get_descricao() << std::endl;
            std::cout << "Data: " << _eventos[i].get_DataHora().tm_mday << "/" << _eventos[i].get_DataHora().tm_mon << "/" << _eventos[i].get_DataHora().tm_year << std::endl;
            std::cout << "Hora: " << std::setfill('0') << std::setw(2) << _eventos[i].get_DataHora().tm_hour << ":" << std::setfill('0') << std::setw(2) << _eventos[i].get_DataHora().tm_min << std::endl;
            std::cout << "Local: " << _eventos[i].get_local() << std::endl;
        }else{
            std::cout << "Nao ha eventos nessa data" << std::endl;
        }
    }
}

void Calendario::listarEventos(){       //listar todos os eventos
    for(int i = 0; i < _eventos.size(); i++){
        std::cout << "Titulo: " << _eventos[i].get_titulo() << std::endl;
        std::cout << "Descricao: " << _eventos[i].get_descricao() << std::endl;
        std::cout << "Data: " << _eventos[i].get_DataHora().tm_mday << "/" << _eventos[i].get_DataHora().tm_mon << "/" << _eventos[i].get_DataHora().tm_year << std::endl;
        std::cout << "Hora: " << std::setfill('0') << std::setw(2) << _eventos[i].get_DataHora().tm_hour << ":" << std::setfill('0') << std::setw(2) << _eventos[i].get_DataHora().tm_min << std::endl;
        std::cout << "Local: " << _eventos[i].get_local() << std::endl;
        std::cout << std::endl;
    }
}

void Calendario::listarEventos(tm data){        //listar eventos por data
    for(int i = 0; i < _eventos.size(); i++){
        if(_eventos[i].get_DataHora().tm_mday == data.tm_mday && _eventos[i].get_DataHora().tm_mon == data.tm_mon && _eventos[i].get_DataHora().tm_year == data.tm_year){
            std::cout << "Titulo: " << _eventos[i].get_titulo() << std::endl;
            std::cout << "Descricao: " << _eventos[i].get_descricao() << std::endl;
            std::cout << "Data: " << _eventos[i].get_DataHora().tm_mday << "/" << _eventos[i].get_DataHora().tm_mon << "/" << _eventos[i].get_DataHora().tm_year << std::endl;
            std::cout << "Hora: " << std::setfill('0') << std::setw(2) << _eventos[i].get_DataHora().tm_hour << ":" << std::setfill('0') << std::setw(2) << _eventos[i].get_DataHora().tm_min << std::endl;
            std::cout << "Local: " << _eventos[i].get_local() << std::endl;
            std::cout << std::endl;
        }
    }
}

std::vector<Evento> Calendario::get_eventos() const{
    return _eventos;
}



