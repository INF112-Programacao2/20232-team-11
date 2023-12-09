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
    void pesquisarEventoPorTitulo() override;
    void pesquisarEventoPorData() override;
    void pesquisarEventoPorTipo() override;
    void listarEventosTodos() override;
    void exibirNotificacoes() override;
    int getNumeroNotificacao() override;
    void contTipoEvento() const;
};

#endif