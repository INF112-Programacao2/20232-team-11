#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <vector>
#include "Evento.hpp"

class Usuario{
protected:
    const std::string _id;
    const std::string _senha;
    virtual void set_id(std::string id);
    virtual void set_senha(std::string senha);
public:
    Usuario(const std::string id, const std::string senha);
    ~Usuario();
    virtual std::string get_senha() const;
    virtual std::string get_id() const;
    
};

#endif