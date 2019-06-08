ROOTDIR := ../../
PROJDIR := ../

FILENAME := getopt_s
OUTFILE := $(FILENAME)
MAIN_C := main.c

PREREQ :=
PREREQ += $(PROJDIR)$(MAIN_C)

INC :=
INC += -I$(ROOTDIR)
INC += -I$(PROJDIR)


$(OUTFILE): $(PREREQ)
#	$(MAKE) -C $(ROOTDIR)
	gcc $(INC) $(PREREQ) -o $(OUTFILE) -lnsl
