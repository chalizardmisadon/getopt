ROOTDIR := ../../
PROJDIR := ../

OUTFILE := $(FILENAME)
MAIN_C := main.c

PREREQ :=
PREREQ += $(PROJDIR)$(MAIN_C)

INC :=
# INC += -I$(ROOTDIR)
# INC += -I$(PROJDIR)


$(OUTFILE): $(PREREQ)
	gcc $(INC) $(PREREQ) -o $(OUTFILE)
