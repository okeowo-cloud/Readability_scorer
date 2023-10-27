.PHONY: all clean test
all: test clean 
test:
	python3 -m unittest test/test_add.py
	python3 -m unittest test/test_coleman.py
	python3 -m unittest test/test_auto_readable.py
	python3 -m unittest test/test_word_attributes.py

#%.o: %.c %.h
#	gcc -c -o $@ $<

clean:
	rm -fr *.o *.so *_.c *.pyc __pycache__/
