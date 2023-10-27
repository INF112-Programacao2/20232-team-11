#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Usuario.hpp"

class Administrador : public Usuario{
private:
public:
    Administrador(const std::string id, const std::string senha);
    ~Administrador();
    std::string get_senha() const override;
    std::string get_id() const override;
    
};


#endif