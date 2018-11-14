#Makefile Ejercicio 25

All: sample.pdf

sample.pdf: histograma.py sample.dat
	python histograma.py

sample.dat: sample.c
	gcc sample.c -o sample -lm
	./sample


