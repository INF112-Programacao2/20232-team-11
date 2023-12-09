#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Calendario.hpp"

//classe professor
class Professor : public Calendario {
public:
    Professor(); // Construtor
    ~Professor();  // Destrutor

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