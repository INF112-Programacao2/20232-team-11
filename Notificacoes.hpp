#ifndef NOTIFICACOES_HPP
#define NOTIFICACOES_HPP

#include <string>
#include <vector>
#include "Evento.hpp"
#include "Usuario.hpp"

class Notificacoes{
private:
    const std::string _messagem;
protected:
    std::vector<Evento> _eventos;
    std::vector<Usuario> _usuarios;
public:
    Notificacoes();
    ~Notificacoes();
    std::string get_messagem() const;
    std::string affichar_messagem() const;
};

#endif