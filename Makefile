include config.mk
OBJ_F = obj
SRC_F = src
INC_F = inc
TEST_F = tests
TEST_BIN_F = tbin
inc_dir = /usr/local/include

lib_name = libiterm
sources = iterm_data iterm_util
tests = $(shell ls $(TEST_F) | grep .c | cut -d '.' -f 1)

def: test_all
	@

$(inc_dir):
	sudo mkdir -p $@

$(INC_F):
	mkdir $(INC_F)

$(inc_dir)/%.h : $(INC_F)/%.h
	cp $< $@

copy_incs: $(inc_dir) $(INC_F) $(sources:%=$(inc_dir)/%.h)
	@

$(TEST_BIN_F):
	mkdir ./$@

$(TEST_F):
	mkdir ./$@

$(TEST_BIN_F)/% : $(TEST_F)/%.c $(lib_name).a
	$(CC) $< -o $@ $(lib_name).a $(CFLAGS)

rem_tests:
	$(tests:%=rm ./$(TEST_BIN_F)/%;)

retest: rem_tests test_all
	@

test_all: $(lib_name).a copy_incs $(TEST_BIN_F) $(TEST_F) $(tests:%=$(TEST_BIN_F)/%) $(copy_incs)
	$(tests:%=./$(TEST_BIN_F)/%;)

$(OBJ_F):
	mkdir -p ./$(OBJ_F)

$(OBJ_F)/%.o : $(SRC_F)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(lib_name).a: $(OBJ_F) $(sources:%=$(OBJ_F)/%.o) $(copy_incs)
	ar rcs $(lib_name).a $(sources:%=$(OBJ_F)/%.o)

build: $(lib_name).a
	@

clean: 
	-rm $(OBJ)/*.o 2> /dev/null
	-rm $(lib_name).a 2> /dev/null

full: build clean

.PHONY: def build clean full
