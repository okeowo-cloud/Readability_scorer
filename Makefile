.PHONY: all clean test
all: test clean 
test:
	python3 -m unittest test/*.py

#%.o: %.c %.h
#	gcc -c -o $@ $<

clean:
	rm -fr *.o *.so *_.c *.pyc __pycache__/
