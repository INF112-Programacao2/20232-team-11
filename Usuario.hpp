#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include "Evento.hpp"

class Usuario{
protected:
    std::string _id;
    std::string _senha;

public:
    Usuario(const std::string& id, const std::string& senha);       // Construtor
    ~Usuario();                                                // Destrutor
    //metodos 
    virtual std::string getId() const;                    // Retorna o id do usuario
    virtual std::string getSenha() const;          // Retorna a senha do usuario
    virtual void setSenha(const std::string& senha);        // Altera a senha do usuario
    virtual void criarEvento(const TipoEvento& tipo, const std::string& titulo, const std::string& descricao, const std::string& data, const std::string& hora, const std::string& local, const std::string& criador);   // Cria um evento  
    virtual bool fazerLogin(const std::string& id, const std::string& senha);       // Faz o login do usuario
};

#endif