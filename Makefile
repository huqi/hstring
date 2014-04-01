test: hstring.cc test.cc
	g++ -o $@ -g $^

.PHONY : clean
clean:
	rm -f *.o test
