evolve_A.png. : graficador.py Datos.dat 
	python graficador.py
    
Datos.dat : ejercicio.x
	./ejercicio.x

ejercicio.x : ejercicio30.cpp
	c++ ejercicio30.cpp -o ejercicio.x

clean:
	rm ejercicio.x *.dat