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
    void adicionarEvento(const Evento& evento);
    void excluirEvento(std::vector<Evento>& eventos, std::vector<Usuario>& usuarios);
    void editarEvento(std::vector<Evento>& eventos, std::vector<Usuario>& usuarios);
    void pesquisarEventoPorTitulo(std::vector<Evento>& eventos, std::vector<Usuario>& usuarios);
    void pesquisarEventoPorData(std::vector<Evento>& eventos);
    void pesquisarEventoPorTipo(std::vector<Evento>& eventos, std::vector<Usuario>& usuarios);
    void listarEventosTodos(std::vector<Evento>& eventos, std::vector<Usuario>& usuarios);
    void listarEventosTipo(std::vector<Evento>& eventos, std::vector<Usuario>& usuarios);
    void listarMeusEventos(std::vector<Evento>& eventos, std::vector<Usuario>& usuarios);
    std::vector<Evento> getEventos() const;
    void imprimirEvento(const Evento& evento);
};

#endif