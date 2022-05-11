EJECUTABLE = $(DIR_BIN)/rwnio
DIR_INC  = ./headers
DIR_OBJ = ./temp
DIR_BIN = ./bin
DIR_MAIN = ./src
OBJETOS = $(DIR_OBJ)/main.o $(DIR_OBJ)/http.o $(DIR_OBJ)/message.o $(DIR_OBJ)/display.o 


CPPFLAGS = -std=c++17 -lcurl -I$(DIR_INC)
CC = g++


$(EJECUTABLE) : $(OBJETOS)
	@mkdir -p $(DIR_BIN)
	@$(CC) $(OBJETOS)  $(CPPFLAGS) -o $(EJECUTABLE)


$(DIR_OBJ)/%.o : $(DIR_MAIN)/%.cpp
	@mkdir -p $(DIR_OBJ)
	@$(CC) -c -MD $(CPPFLAGS) $< -o $@
-include $(DIR_OBJ)/*.d


.PHONY: clean
clean:
	@rm -r $(DIR_BIN) $(DIR_OBJ)

.PHONY: install
install:
	apt-get install libcurl4-openssl-dev