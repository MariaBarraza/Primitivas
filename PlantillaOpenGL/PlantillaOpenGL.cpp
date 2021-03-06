// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h" //ayuda a que compile mas rapido
#include <stdio.h> // esta cosa para librerias incluidas en c#
#include <stdlib.h>

#define GLEW_STATIC 

#include "GL/glew.h" //comillas para librerias personalizadas
#include "GLFW/glfw3.h"
#include <iostream>

using namespace std; //aqui esta lo de c++

void dibujarTriangulos(){
	glBegin(GL_TRIANGLES); //que comience a dibujar (un triangulo), cada 3 vertices que lea crea un triangulo 
						   //Aqui se dicen sus colores y la posicion del vertice
	glColor3f(1, 0, 0);
	glVertex3f(0, 1, 0); // el 3f significa que acepta 3 flotantes
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);


	//cuadrado morado
	glColor3f(138.0f / 255.0f, 43.0f / 255.0f, 225.0f / 255.0f);

	glVertex3f(1, 1, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 0, 0);

	glVertex3f(1, 1, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(0, 0, 0);

	//Asi se hace el degradado
	glColor3f(1, .5, .2);
	glVertex3f(1, 1, 0);
	glColor3f(.7, .2, .8);
	glVertex3f(0, 1, 0);
	glColor3f(.3, .4, .1);
	glVertex3f(0, 0, 0);

	glEnd(); // Aqui termina de dibujar
}

void dibujarPuntos(){
	
	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	glVertex3f(0.5f,0.1f,0.0f);
	glColor3f(0, 0, 0);
	glVertex3f(0.55f, 0.1f, 0.0f);
	glEnd();


	glEnd();

}

void dibujarLineas(){
	glBegin(GL_LINES); //toma los vertices de 2 en 2
	
	glColor3f(1, 1, 1);

	glVertex3f(0, 0, 0);
	
	glColor3f(0,0, 0);

	glVertex3f(0, 0.5, 0);
	
	glVertex3f(0.2, 0.4, 0);
	glVertex3f(-0.2, 0.4, 0);

	
	glEnd();
}


void dibujarLineaContinua() {
	glBegin(GL_LINE_STRIP); //dos vertices la primera linea y despues va a tomando el siguiente es como unir puntos
		glColor3f(0, 0, 0);
			glVertex3f(0, 0, 0);
			glVertex3f(0, -0.2, 0);
			glVertex3f(0.3,-0.2,0);
			glVertex3f(0.3, 0, 0);
			glVertex3f(0, 0, 0);
	glEnd();
}

void dibujarTrianguloContinuo() {
	
	glBegin(GL_TRIANGLE_STRIP); //tres vertices el primer triangulo, despues toma los ultimos 2 vertices + el nuevo para crear un triangulo
		glColor3f(1, 1, 1);
			glVertex3f(0, 0, 0);
			glVertex3f(-0.2, -0.2, 0);
			glVertex3f(0.2, -0.2, 0);
			glColor3f(0, 0, 0);
			glVertex3f(0.2, -0.4, 0);
			glColor3f(0.3, 0.3, 0.3);
			glVertex3f(0.4, -0.4, 0);
	glEnd();
}

void dibujarPoligono() {
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(0.2, 0.1, 0);
	glVertex3f(-0.2, 0.3, 0);
	glColor3f(0, 0, 0);
	glVertex3f(-0.4, 0.2, 0);
	glVertex3f(0.4, 0.3,0);
	glEnd();

}

void dibujarCirculo() {
	glBegin(GL_POLYGON);
	glColor3f(1, 0.8, 0);

	for (int i = 0; i < 360; i++) {
		glVertex3f(0.15* cos((double) i * 3.14159 / 180.0) - 0.7, 0.15 * sin((double) i * 3.14159 / 180.0) + 0.6, 0);
	}


	glEnd();
}

void dibujarCasa() {
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex3f(0,0,0);
	glVertex3f(0.6, 0, 0);
	glVertex3f(0.6, -0.5, 0);
	glVertex3f(0, -0.5, 0);
	glEnd();
}

void dibujarTecho() {
	glBegin(GL_TRIANGLES);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0.6, 0, 0);
	glVertex3f(.3, .2, 0);
	glEnd();

}

void dibujarPiso() {
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex3f(1, -0.5, 0);
	glVertex3f(-1, -0.5, 0);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);
	glEnd();

}

void dibujarNubes() {

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);

	for (int i = 0; i < 360; i++) {
		glVertex3f(.09 * cos((double)i * 3.14159 / 180.0) + 0.6, 0.09 * sin((double)i * 3.14159 / 180.0) + 0.6, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		glVertex3f(.09 * cos((double)i * 3.14159 / 180.0) + 0.7, 0.09 * sin((double)i * 3.14159 / 180.0) + 0.6, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		glVertex3f(.09 * cos((double)i * 3.14159 / 180.0) + 0.8, 0.09 * sin((double)i * 3.14159 / 180.0) + 0.6, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		glVertex3f(.09 * cos((double)i * 3.14159 / 180.0) + 0.1, 0.09 * sin((double)i * 3.14159 / 180.0) + 0.6, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		glVertex3f(.09 * cos((double)i * 3.14159 / 180.0) + 0.2, 0.09 * sin((double)i * 3.14159 / 180.0) + 0.6, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		glVertex3f(.09 * cos((double)i * 3.14159 / 180.0) + 0.3, 0.09 * sin((double)i * 3.14159 / 180.0) + 0.6, 0);
	}
	glEnd();

}

void dibujarArbol() {
	glBegin(GL_POLYGON);
	glColor3f(0.647059, 0.164706, 0.164706);
	glVertex3f(-0.25, -0.5, 0);
	glVertex3f(-0.25, 0.06, 0);
	glVertex3f(-0.5, 0.06, 0);
	glVertex3f(-0.5, -0.5, 0);

	glEnd();

	glColor3f(0, 1.0, 0.498039);

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		glVertex3f(.2 * cos((double)i * 3.14159 / 180.0) -0.3, 0.15 * sin((double)i * 3.14159 / 180.0) +0.36, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		glVertex3f(.2 * cos((double)i * 3.14159 / 180.0) - 0.2, 0.15 * sin((double)i * 3.14159 / 180.0) + 0.17, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		glVertex3f(.2 * cos((double)i * 3.14159 / 180.0) - 0.42, 0.15 * sin((double)i * 3.14159 / 180.0) + 0.1, 0);
	}
	glEnd();


	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		glVertex3f(.2 * cos((double)i * 3.14159 / 180.0) - 0.5, 0.15 * sin((double)i * 3.14159 / 180.0) + 0.32, 0);
	}
	glEnd();


}

void dibujarPuerta() {
	glBegin(GL_POLYGON);
	glColor3f(1, .5, 0);

	glVertex3f(0.2, -0.3, 0);
	glVertex3f(0.3, -0.3, 0);
	glVertex3f(0.3, -0.5, 0);
	glVertex3f(0.2, -0.5, 0);

	glEnd();
}

void dibujarVentana(){
	glBegin(GL_POLYGON);
	glColor3f(0.498039, .03, 1.0);

	glVertex3f(0.5, -0.25, 0);
	glVertex3f(0.4, -0.25, 0);
	glVertex3f(0.4, -0.1, 0);
	glVertex3f(0.5, -0.1, 0);

	glEnd();
}

//GL_QUADS utiliza 4 vertices para hacer cuadrados
//GL_QUAD_STRIP utiliza 4 vertices y luego va de 2 en 2 utilizando los ultimos 2

void dibujar() {
	
	//dibujarTriangulos();
	//dibujarPuntos();
	//dibujarLineas();
	//dibujarLineaContinua();
	//dibujarTrianguloContinuo();
	//dibujarPoligono();
	dibujarCirculo();
	dibujarCasa();
	dibujarTecho();
	dibujarPiso();
	dibujarNubes();
	dibujarArbol();
	dibujarPuerta();
	dibujarVentana();
}

void actualizar() {

}

int main()
{
	//Declaramos apuntador de ventana

	GLFWwindow *window;

	//Si no se pudo iniciar glfw terminamos ejecución

	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	//Si se pudo iniciar GLFW entonces inicializamos la ventana

	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);

	//Si no podemos iniciar la ventana entonces terminamos la ejecución
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido e contexto activamos funciones modernas
	glewExperimental = true; //permite trabajar con gpu y cpu al mismo tiempo,solo va a funcionar si ya esta establecido el contexto

	//en caso de haber error se guarda en la variable errorGlew que es tipo GLenum 
	GLenum errorGlew = glewInit(); //inicializa glew

	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	//se obtiene la version de OpenGL y se imprime
	const GLubyte *versionGL = glGetString(GL_VERSION); 
	cout << "Version OpenGL: " << versionGL; 

	//ciclo de dibujo (draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 768); //dice donde va a empezar a renderear y donde va a terminar
		//Establecer color de borrado
		glClearColor(0.560784, 0.74902, 1, 1);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffer
		glfwSwapBuffers(window); //cambia el buffer de la pantalla por el otro que se lleno
		//reconocer si hay entradas
		glfwPollEvents();

	}

	glfwDestroyWindow(window); //terminamos los procesos y eliminamos la ventana
	glfwTerminate();
	return 0;
}



