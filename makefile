evolve_A.png. : graficador.py datos.dat 
	python graficador.py
    
datos.dat : ejercicio.x
	./ejercicio.x

ejercicio.x : ejercicio31.cpp
	c++ ejercicio31.cpp -o ejercicio.x

clean:
	rm ejercicio.x *.dat evolve_A.png