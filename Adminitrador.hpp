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

    // Sobrescreva o método alterar_senha para permitir apenas ao aluno mudar sua própria senha
    void alterar_senha(const std::string& senha) override;
    
};


#endif