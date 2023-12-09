#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Calendario.hpp"

//classe administrador
class Administrador : public Calendario {
public:
    Administrador();  // Construtor
    ~Administrador();    // Destrutor

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