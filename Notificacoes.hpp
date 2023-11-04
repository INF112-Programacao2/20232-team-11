#ifndef NOTIFICACOES_HPP
#define NOTIFICACOES_HPP

#include <string>
#include <vector>
#include "Evento.hpp"
#include "Usuario.hpp"

class Notificacoes{
private:
    std::string _mensagem;
    void set_mensagem(const std::string& mensagem);
protected:
    std::vector<Evento> _eventos;
    std::vector<Usuario> _usuarios;
public:
    Notificacoes(std::string mensagem);
    ~Notificacoes();
    std::string get_mensagem() const;
    std::string affichar_mensagem() const;
};

#endif