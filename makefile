P=apatank2_phone_directory
all: $(P).out
$(P).out: $(P).cpp
	g++ $(P).cpp -o $(P).out
clean:
	rm -rf $(P) $(Q) *.out
