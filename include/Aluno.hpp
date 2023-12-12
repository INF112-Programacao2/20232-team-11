#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Calendario.hpp"
#include <string>
#include <iostream>

//classe aluno
class Aluno : public Calendario {
public:
    Aluno(); // Construtor
    ~Aluno();   // Destrutor

    // Métodos
    void criarEvento(std::vector<Evento>& eventos) override;
    void editarEvento() override;
    void pesquisarEventoPorTitulo() override;
    void pesquisarEventoPorData() override;
    void pesquisarEventoPorTipo() override;
    void listarTodosEventosFuturos() override;
    void listarTodosEventosPassados() override;
    void exibirNotificacoes() override;
    int getNumeroNotificacao() override;
    void contTipoEvento() const override;
    void calendarioComEventos() override;
};

#endif