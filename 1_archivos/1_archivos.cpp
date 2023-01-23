// Ejemplo de manejo de archivos en C++

//manejo de consola
#include <iostream> 
//biblioteca de manejo de archivos
#include <fstream>
#define MAXSIZE 128

void ejemploApuntadores()
{
    std::cout << "ejemplo de apuntadores\n";
    int valor = 66;
    int  *ref2 = &valor; //operador de referencia
    *ref2 = 128;
    printf("Valor: %i  Mem:%#010x \n", *ref2, ref2);
    std::cout << "valor = " << valor << std::endl;
}

void acumular(float & a, float b)
{
    a += b;
}
int main()
{
    float valor = 0;
    int num_vals = 0;

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
            acumular(valor, atof(buffer));

            std::cout << "valor acumulado: " << valor << std::endl;
            num_vals++;
        }
        valor /= num_vals;

        std::ofstream file_o("datos.txt", std::ofstream::app ); 
        file_o << "\npromedio: " << valor << std::endl;
    }
    else
    {
        std::cout << "no se encuentra el archivo\n";
    }
}
