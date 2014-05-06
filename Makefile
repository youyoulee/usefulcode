all: test-adlist
	
test-adlist:
	clang -g -D DEBUG test-adlist.c adlist.c -o $@
	
clean:
	rm -rf test-adlist test-adlist.dSYM
