#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Calendario.hpp"

//classe professor
class Professor : public Calendario {
public:
    Professor(); // Construtor
    ~Professor();  // Destrutor

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