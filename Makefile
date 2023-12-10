CXX := g++
CXXFLAGS := -std=c++11 -Wall
EXECUTABLE := Calendario

SOURCES := administrador.cpp aluno.cpp calendario.cpp evento.cpp professor.cpp usuario.cpp main.cpp
OBJECTS := $(SOURCES:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Gera as dependências
depend: .depend

	.depend: $(SOURCES)
		$(RM) ./.depend
		$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

	clean:
		$(RM) $(OBJECTS) $(EXECUTABLE)

	distclean: clean
		$(RM) *~ .depend

	include .depend
