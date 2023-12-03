#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include "Evento.hpp"

class Usuario{
protected:
    std::string _id;
    std::string _senha;
    std::string _nome;
    bool _ativo; // Flag para indicar se o usuario esta ativo ou nao

public:
    Usuario(const std::string& nome,const std::string& id, const std::string& senha);       // Construtor
    ~Usuario();                                                // Destrutor
    //metodos 
    virtual std::string get_id() const;                    // Retorna o id do usuario
    virtual std::string get_senha() const;          // Retorna a senha do usuario
    virtual std::string get_nome() const;
    virtual void alterar_senha(const std::string& senha) ;        // Altera a senha do usuario
    virtual void criarEvento(const std::string& tipo, const std::string& titulo, const std::string& descricao, const std::string& data, const std::string& hora, const std::string& local, const std::string& criador);   // Cria um evento  
    virtual bool fazer_login(const std::string& id, const std::string& senha);       // Faz o login do usuario
    virtual void cadastrar();       // Cadastra um usuario
    virtual void inativar();       // inativa um usuario 
    virtual bool esta_ativo() const;      // Verifica se esta ativo
};

#endif