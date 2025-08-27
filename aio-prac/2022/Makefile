.PHONY: new build run

new%:
	python3 make_new.py $*

build%:
	c++ -Wall -Wconversion -Wfatal-errors -g -std=c++20 -fsanitize=undefined,address $*.cpp -o $*

run%: build%
	./$*
