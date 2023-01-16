// Ejemplo de manejo de archivos en C++

//manejo de consola
#include <iostream> 
//biblioteca de manejo de archivos
#include <fstream>
#define MAXSIZE 128

int main()
{
    //enviar la cadena HW al flujo std::cout
    std::cout << "Leyendo archivo" << std::endl;

    std::ifstream file;
    file.open("datos.txt", std::ifstream::in);

    if (file.is_open())
    {
        std::cout << "archivo abierto\n";
        //buffer o memoria temporal para almacenar el contenido
        // una linea
        char buffer[MAXSIZE];
        //leer linea a linea el archivo
        while ( !file.eof())
        {
            file.getline(buffer, MAXSIZE);
            std::cout << buffer << std::endl;
        }
    }
    else
    {
        std::cout << "no se encuentra el archivo\n";
    }
}
