evolve_A.png. : graficador.py datos.dat 
	python graficador.py
    
datos.dat : ejercicio.x
	./ejercicio.x

ejercicio.x : ejercicio30.cpp
	c++ ejercicio30.cpp -o ejercicio.x

clean:
	rm ejercicio.x *.dat evolve_A.png