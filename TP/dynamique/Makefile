CC=g++
CFLAGS=-Wall -g
all:CUT_ROD_TOP CUT_ROD_BOTTOM

CUT_ROD_TOP:cut_rod_top.cpp
	$(CC) $(CFLAGS) $^ -o $@
	
CUT_ROD_BOTTOM:cut_rod_bottom.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f CUT_ROD_TOP CUT_ROD_BOTTOM
	
bench:
	@echo "## cut_rod_top ##"
	./CUT_ROD_TOP
	
	@echo ""
	@echo "## cut_rod_bottom ##"
	./CUT_ROD_BOTTOM		
