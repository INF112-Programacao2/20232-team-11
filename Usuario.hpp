#ifndef USUARIO_HPP 
#define USUARIO_HPP

#include <string>
#include "Evento.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

//classe usuario
class Usuario{
protected:
    std::string _id;  //variavel que armazena o id do usuario
    std::string _senha; //variavel que armazena a senha do usuario
    std::string _tipo;  //variavel que armazena o tipo do usuario
    std::vector<Evento> _eventos; //vetor que armazena os eventos 
    std::vector<Usuario> _usuarios; //vetor que armazena os usuarios

public:
    //construtor e destrutor
    Usuario();  // Construtor sem parametros                                               
    Usuario(const std::string& tipo, const std::string& id, const std::string& senha);    // Construtor
    ~Usuario();   // Destrutor

    //metodos
    virtual std::string getTipo() const;   // Retorna o tipo do usuario
    virtual void setTipo(const std::string& tipo); // Altera o tipo do usuario 
    virtual std::string getId() const;   // Retorna o id do usuario
    virtual void setId(const std::string& id);  // Altera o id do usuario
    virtual std::string getSenha() const;   // Retorna a senha do usuario
    virtual void setSenha(const std::string& senha);   // Altera a senha do usuario
    virtual void criarUsuario(std::vector<Usuario>& usuarios);                        // Cria um usuario
    virtual void adicionarUsuario(const Usuario& usuario); // Adiciona um usuario
    virtual std::vector<Usuario> getUsuarios(); // Retorna os usuarios
    virtual void criarEvento(std::vector<Evento>& eventos);   // Cria um evento  
    virtual void adicionarEvento(const Evento& evento); // Adiciona um evento
    virtual std::vector<Evento> getEventos(); // Retorna os eventos
    virtual bool fazerLogin(); // Faz o login do usuario
    virtual void listarUsuarios(); // Lista os usuarios
    virtual std::vector<Usuario> getUsuarios() const; // Retorna os usuarios
    virtual void logout(); // Faz o logout do usuario
};

#endif