#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Usuario.hpp"

//classe professor
class Professor : public Usuario {
public:
    Professor(const std::string& tipo, const std::string& id, const std::string& senha); // Construtor
    ~Professor();  // Destrutor
};

#endif