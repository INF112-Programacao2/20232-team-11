#ifndef CALENDARIO_HPP
#define CALENDARIO_HPP

#include <string>
#include <vector>
#include "Evento.hpp"
#include "Usuario.hpp"

class Calendario {
private:
    std::vector<Evento> eventos;

public:
    Calendario();   // Construtor
    ~Calendario();      // Destrutor

    // Métodos
    void adicionarEvento(const Evento& evento);
    void excluirEvento(const Evento& evento, const std::string& id);
    void editarEvento(const Evento& evento, const std::string& id);
    void pesquisarEventoPorTitulo(const std::string& titulo);
    void pesquisarEventoPorData(const std::string& data);
    void listarEventosTodos()const ;
    void listarEventosTipo(const std::string& tipo);
    void listarEventosDia(const std::string& data);
    void listarMeusEventos(const std::string& id) const ;
};

#endif