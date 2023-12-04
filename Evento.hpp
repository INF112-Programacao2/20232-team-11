#ifndef EVENTO_HPP
#define EVENTO_HPP

#include <string>

class Evento {
private:
    std::string _tipo;  //variável que armazena o tipo de evento
    std::string _titulo;  //variável que armazena o título do evento   
    std::string _descricao; //variável que armazena a descrição do evento
    std::string _data; //variável que armazena a data do evento
    std::string _hora;  //variável que armazena a hora do evento
    std::string _local; //variável que armazena o local do evento
    std:: string _criador;  //variável que armazena o criador do evento
    std::string _id; //variável que armazena o id do evento

public:
    Evento();  // Construtor
    Evento(const std::string& tipo, const std::string& titulo, const std::string& descricao, const std::string& data, const std::string& hora, const std::string& local, const std::string& criador, const std::string id);    // Construtor
    ~Evento();  // Destrutor

    // Métodos get
    std::string getTipo() const;    
    std::string getTitulo() const;
    std::string getDescricao() const;
    std::string getData() const;
    std::string getHora() const;
    std::string getLocal() const;
    std::string getCriador() const;
    std::string getId() const;

    // Métodos set
    void setTipo(const std::string& tipo);
    void setTitulo(const std::string& titulo);
    void setDescricao(const std::string& descricao);
    void setData(const std::string& data);
    void setHora(const std::string& hora);
    void setLocal(const std::string& local);
    void setCriador(const std::string& criador);
};

#endif