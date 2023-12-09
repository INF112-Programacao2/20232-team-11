# Makefile para compilar o projeto

# Compilador
CXX := g++

# Opções de compilação
CXXFLAGS := -std=c++11 -Wall

# Lista de arquivos fonte
SOURCES := administrador.cpp aluno.cpp calendario.cpp evento.cpp professor.cpp usuario.cpp main.cpp

# Gera a lista de arquivos objeto
OBJECTS := $(SOURCES:.cpp=.o)

# Nome do executável (alterado para Calendario)
EXECUTABLE := Calendario

# Regra padrão: compilar todos os arquivos objeto e vincular
all: $(EXECUTABLE)

# Regra para cada arquivo objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra de vinculação
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Limpeza: remove arquivos objeto e o executável
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
