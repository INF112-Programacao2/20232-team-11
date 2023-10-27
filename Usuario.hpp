#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <vector>
#include "Evento.hpp"

class Usuario{
protected:
    const std::string _id;
public:
    virtual void set_id(std::string id);
    virtual std::string get_id() const;
    
};

#endif