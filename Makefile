include config.mk
lib_name = libiterm
sources = iterm_data
OBJ_F = obj
SRC_F = src

def: build
	@

$(OBJ_F):
	mkdir -p ./$(OBJ_F)

$(OBJ_F)/%.o : $(SRC_F)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

build: $(OBJ_F) $(sources:%=$(OBJ_F)/%.o)
	ar rcs $(lib_name).a $(libs:%=$(OBJ_F)/%.o)

clean: 
	-rm $(OBJ)/*.o 2> /dev/null
	-rm $(lib_name).a 2> /dev/null

full: build clean

.PHONY: def build clean full
