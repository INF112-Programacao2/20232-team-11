#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <vector>
#include "Evento.hpp"
#include "Calendario.hpp"

class Usuario{
protected:
    const std::string _id;
    std::string _senha;
    
    virtual void set_senha(const std::string& senha);
public:
    Usuario(const std::string id, const std::string senha);
    ~Usuario();
    virtual std::string get_senha() const;
    virtual std::string get_id() const;
    void criarEvento(Calendario& calendario, const Evento& evento) {
    
}
    
};

#endif