#ifndef CALENDARIO_HPP
#define CALENDARIO_HPP

#include <string>
#include <vector>
#include "Evento.hpp"
#include "Usuario.hpp"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <algorithm>

class Calendario : public Usuario{
protected:
    std::vector<Evento> eventos;  //vetor de eventos para armazenar os eventos
    std::vector<Usuario> usuarios; //vetor de usuarios para armazenar os usuarios
    int contEventoAcademico = 0; // variável para contar o número de notificações
    int contEventoPessoal = 0; // variável para contar o número de notificações
    int contEventoApresentacao = 0; // variável para contar o número de notificações
    int contEventoProva = 0; // variável para contar o número de notificações
    int contEventoTrabalho = 0; // variável para contar o número de notificações
    std::string idLogin; // variável para armazenar o id do usuário logado

public:
    Calendario();   // Construtor
    ~Calendario();      // Destrutor

    // Métodos
    void excluirEvento();
    void editarEvento();
    virtual void pesquisarEventoPorTitulo() = 0;
    virtual void pesquisarEventoPorData() = 0;
    virtual void pesquisarEventoPorTipo() = 0;
    virtual void listarTodosEventosFuturos() = 0;
    virtual void listarTodosEventosPassados() = 0;
    virtual void listarMeusEventosPassados();
    virtual void listarMeusEventosFuturos();
    std::vector<Evento> getEventos() const;
    void imprimirEvento(const Evento& evento);
    void imprimirEventoOrdenado(const std::vector<Evento>& eventos);
    static bool compararPorData(const Evento& a, const Evento& b);
    virtual void exibirNotificacoes() = 0;
    virtual int getNumeroNotificacao() = 0;
    virtual void contTipoEvento() const = 0;
};

#endif