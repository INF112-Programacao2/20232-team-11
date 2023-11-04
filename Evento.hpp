#ifndef EVENTO_HPP
#define EVENTO_HPP

#include <string>

class Evento{
protected:
    std::string _titulo;
    std::string _descricao;
    tm *_DataHora;
    std::string _local;
public:
    Evento(std::string titulo, std::string descricao, tm DataHora, std::string local);
    ~Evento();

    void set_titulo(std::string titulo);
    std::string get_titulo();

    void set_descricao(std::string descricao);
    std::string get_descricao();

    void set_DataHora(tm DataHora);
    tm get_DataHora();

    void set_local(std::string local);
    std::string get_local();

};

#endif