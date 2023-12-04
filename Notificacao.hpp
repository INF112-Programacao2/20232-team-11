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

class Notificacao {
private:
    std::string _mensagem;  //variavel para armazenar a mensagem
    std::string _data;    //variavel para armazenar a data
    std::string _hora;  //variavel para armazenar a hora

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
    bool umaSemanaAntes(const std::vector<Evento>& eventos);
    bool tresDiasAntes(const Evento& eventos);
    bool umDiaAntes(const std::vector<Evento>& eventos);
    bool umaHoraAntes(const std::vector<Evento>& eventos);
    bool quinzeMinutosAntes(const std::vector<Evento>& eventos);
    void exibirNotificacao(const std::vector<Evento>& eventos);
};

#endif