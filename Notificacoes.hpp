#ifndef NOTIFICACAO_HPP
#define NOTIFICACAO_HPP

#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <iostream>
#include <vector>
#include "Evento.hpp"
#include "Calendario.hpp"
#include "Usuario.hpp"

// enum TipoEvento {
//     PROVA,
//     TRABALHO,
//     APRESENTACAO,
//     OUTRO,
// };

class Notificacao {
private:
    std::string _mensagem;
    std::string _data;
    std::string _hora;

public:
    Notificacao();      // Construtor
    ~Notificacao();     // Destrutor

    // Métodos
    std::string getMensagem() const;
    std::string getData() const;
    std::string getHora() const;

    void setMensagem(const std::string& mensagem);
    void setData(const std::string& data);
    void setHora(const std::string& hora);
    bool verificarDataHora(const std::vector<Evento>& eventos);
    bool umaSemanaAntes(const std::vector<Evento>& eventos);
    bool tresDiasAntes(const std::vector<Evento>& eventos);
    bool umDiaAntes(const std::vector<Evento>& eventos);
    bool umaHoraAntes(const std::vector<Evento>& eventos);
    bool quinzeMinutosAntes(const std::vector<Evento>& eventos);
    void exibirNotificacao(const std::vector<Evento>& eventos);
};

#endif