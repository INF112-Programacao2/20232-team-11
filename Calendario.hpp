#ifndef CALENDARIO_HPP
#define CALENDARIO_HPP

#include <string>
#include <vector>
#include "Evento.hpp"
#include "Usuario.hpp"

class Calendario{
protected:
    std::vector<Evento> _eventos;
public:
    Calendario(std::vector<Evento> eventos);
    ~Calendario();
    void adicionarEvento(Evento evento);
    void excluirEvento(Evento evento);
    void editarEvento(Evento evento);
    void pesquisarEvento(std::string titulo);
    void pesquisarEvento(tm data);
    void listarEventos();
    void listarEventos(tm data);
    std::vector<Evento> get_eventos() const;


};

#endif