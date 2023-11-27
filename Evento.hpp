#ifndef EVENTO_HPP
#define EVENTO_HPP

#include <string>

// Enumeração para os tipos de eventos
enum TipoEvento {
    PROVA,
    TRABALHO,
    APRESENTACAO,
    OUTRO,
};

class Evento {
private:
    TipoEvento _tipo;
    std::string _titulo;
    std::string _descricao;
    std::string _data;
    std::string _hora;
    std::string _local;
    std:: string _criador;

public:
    Evento(const TipoEvento& tipo, const std::string& titulo, const std::string& descricao, const std::string& data, const std::string& hora, const std::string& local, const std::string& criador);    // Construtor
    ~Evento();                    // Destrutor

    // Métodos get
    TipoEvento getTipo() const;
    std::string getTitulo() const;
    std::string getDescricao() const;
    std::string getData() const;
    std::string getHora() const;
    std::string getLocal() const;
    std::string getCriador() const;

    // Métodos set
    void setTipo(const TipoEvento& tipo);
    void setTitulo(const std::string& titulo);
    void setDescricao(const std::string& descricao);
    void setData(const std::string& data);
    void setHora(const std::string& hora);
    void setLocal(const std::string& local);
    void setCriador(const std::string& criador);
};

#endif