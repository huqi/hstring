test: KM_String.cc test.cc
	g++ -o $@ -g $^

.PHONY : clean
clean:
	rm --force *.o test
