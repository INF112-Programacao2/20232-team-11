#include "Calendario.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Evento.hpp"

Calendario::Calendario() {}     // Construtor

Calendario::~Calendario() {}        // Destrutor

// Métodos para adicinar eventos
void Calendario::adicionarEvento(const Evento& evento) {
    eventos.push_back(evento);      // Adiciona o evento no final do vetor
}

// Métodos para excluir eventos
void Calendario::excluirEvento(const Evento& evento, const std::string& id) {
    for (int i = 0; i < eventos.size(); i++) {      // Percorre o vetor de eventos
        if (eventos[i].getTitulo() == evento.getTitulo() && eventos[i].getCriador() == id) {        // Verifica se o evento existe
            eventos.erase(eventos.begin() + i);     // Apaga o evento
            std::cout << "Evento excluido com sucesso!" << std::endl;       
        }
    }
    std::cout << "Evento nao encontrado!" << std::endl;     // Caso o evento nao exista
}

// Métodos para editar eventos
void Calendario::editarEvento(const Evento& evento, const std::string& id) {        // Edita o evento
    for (int i = 0; i < eventos.size(); i++) {    // Percorre o vetor de eventos
        if (eventos[i].getTitulo() == evento.getTitulo() && eventos[i].getCriador() == id) {    // Verifica se o evento existe
            // Edita o evento
            eventos[i].setTitulo(evento.getTitulo());
            eventos[i].setDescricao(evento.getDescricao());
            eventos[i].setData(evento.getData());
            eventos[i].setHora(evento.getHora());
            eventos[i].setLocal(evento.getLocal());
            std::cout << "Evento editado com sucesso!" << std::endl;
        }
    }
    std::cout << "Evento nao encontrado!" << std::endl;     // Caso o evento nao exista
}

// Métodos para pesquisar eventos
void Calendario::pesquisarEventoPorTitulo(const std::string& titulo) {
    for (int i = 0; i < eventos.size(); i++) {      // Percorre o vetor de eventos
        if (eventos[i].getTitulo() == titulo) {     // Verifica se o evento existe
            // Imprime o evento
            std::cout << "Tipo: " << eventos[i].getTipo() << std::endl;
            std::cout << "Titulo: " << eventos[i].getTitulo() << std::endl;
            std::cout << "Descricao: " << eventos[i].getDescricao() << std::endl;
            std::cout << "Data: " << eventos[i].getData() << std::endl;
            std::cout << "Hora: " << eventos[i].getHora() << std::endl;
            std::cout << "Local: " << eventos[i].getLocal() << std::endl;
        }
    }
    std::cout << "Evento nao encontrado!" << std::endl;     // Caso o evento nao exista
}

// Métodos para listar eventos por tipo
void Calendario::listarEventosTipo(const std::string& tipo) {       
    for (int i = 0; i < eventos.size(); i++) {      // Percorre o vetor de eventos
        if (eventos[i].getTipo() == tipo) {     // Verifica se o evento existe
            // Imprime o evento
            std::cout << "Tipo: " << eventos[i].getTipo() << std::endl;
            std::cout << "Titulo: " << eventos[i].getTitulo() << std::endl;
            std::cout << "Descricao: " << eventos[i].getDescricao() << std::endl;
            std::cout << "Data: " << eventos[i].getData() << std::endl;
            std::cout << "Hora: " << eventos[i].getHora() << std::endl;
            std::cout << "Local: " << eventos[i].getLocal() << std::endl;
            std::cout << std::endl;
        }
    }
}

// Métodos para listar eventos por data
void Calendario::pesquisarEventoPorData(const std::string& data) {      
    for (int i = 0; i < eventos.size(); i++) {      // Percorre o vetor de eventos
        if (eventos[i].getData() == data) {     // Verifica se o evento existe
            // Imprime o evento
            std::cout << "Tipo: " << eventos[i].getTipo() << std::endl;
            std::cout << "Titulo: " << eventos[i].getTitulo() << std::endl;
            std::cout << "Descricao: " << eventos[i].getDescricao() << std::endl;
            std::cout << "Data: " << eventos[i].getData() << std::endl;
            std::cout << "Hora: " << eventos[i].getHora() << std::endl;
            std::cout << "Local: " << eventos[i].getLocal() << std::endl;
        }
    }
    std::cout << "Evento nao encontrado!" << std::endl;     // Caso o evento nao exista
}

// Métodos para listar todos os eventos
void Calendario::listarEventosTodos() {
    for (int i = 0; i < eventos.size(); i++) {    // Percorre o vetor de eventos
        // Imprime o evento
        std::cout << "Tipo: " << eventos[i].getTipo() << std::endl;
        std::cout << "Titulo: " << eventos[i].getTitulo() << std::endl;
        std::cout << "Descricao: " << eventos[i].getDescricao() << std::endl;
        std::cout << "Data: " << eventos[i].getData() << std::endl;
        std::cout << "Hora: " << eventos[i].getHora() << std::endl;
        std::cout << "Local: " << eventos[i].getLocal() << std::endl;
        std::cout << std::endl;
    }
}

// Métodos para listar eventos por dia
void Calendario::listarEventosDia(const std::string& data) {
    for (int i = 0; i < eventos.size(); i++) {      // Percorre o vetor de eventos
        if (eventos[i].getData() == data) {     // Verifica se o evento existe
            // Imprime o evento
            std::cout << "Tipo: " << eventos[i].getTipo() << std::endl;
            std::cout << "Titulo: " << eventos[i].getTitulo() << std::endl;
            std::cout << "Descricao: " << eventos[i].getDescricao() << std::endl;
            std::cout << "Data: " << eventos[i].getData() << std::endl;
            std::cout << "Hora: " << eventos[i].getHora() << std::endl;
            std::cout << "Local: " << eventos[i].getLocal() << std::endl;
            std::cout << std::endl;
        }
    }
}

// Métodos para listar eventos por criador
void Calendario::listarMeusEventos(const std::string& id) { 
    for (int i = 0; i < eventos.size(); i++) {      // Percorre o vetor de eventos
        if (eventos[i].getCriador() == id) {        // Verifica se o evento existe
            // Imprime o evento
            std::cout << "Tipo: " << eventos[i].getTipo() << std::endl;
            std::cout << "Titulo: " << eventos[i].getTitulo() << std::endl;
            std::cout << "Descricao: " << eventos[i].getDescricao() << std::endl;
            std::cout << "Data: " << eventos[i].getData() << std::endl;
            std::cout << "Hora: " << eventos[i].getHora() << std::endl;
            std::cout << "Local: " << eventos[i].getLocal() << std::endl;
            std::cout << std::endl;
        }
    }
}
