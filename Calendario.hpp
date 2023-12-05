#ifndef CALENDARIO_HPP
#define CALENDARIO_HPP

#include <string>
#include <vector>
#include "Evento.hpp"
#include "Usuario.hpp"

class Calendario {
private:
    std::vector<Evento> eventos;  //vetor de eventos para armazenar os eventos
    std::vector<Usuario> usuarios; //vetor de usuarios para armazenar os usuarios

public:
    Calendario();   // Construtor
    ~Calendario();      // Destrutor

    // Métodos
    void excluirEvento();
    void editarEvento();
    void pesquisarEventoPorTitulo();
    void pesquisarEventoPorData();
    void pesquisarEventoPorTipo();
    void listarEventosTodos();
    void listarEventosTipo();
    void listarMeusEventos();
    std::vector<Evento> getEventos() const;
    void imprimirEvento(const Evento& evento);
};

#endif