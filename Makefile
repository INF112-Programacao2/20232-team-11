CXX := g++
CXXFLAGS := -std=c++11 -Wall
EXECUTABLE := Calendario

# Diretórios
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Gera as dependências
depend: .depend

	.depend: $(SOURCES)
		$(RM) ./.depend
		$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -MM $^>>./.depend;

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	$(RM) $(OBJECTS)

	clean:
		$(RM) $(OBJECTS) $(EXECUTABLE)

	distclean: clean
		$(RM) *~ .depend

	include .depend