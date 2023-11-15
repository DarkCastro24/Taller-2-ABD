#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>
#include <unistd.h>

using namespace std;

// Predeclaracion de funciones 
char generateChar();
string generarClave();
void generarDatabank(ifstream &inputFile, ofstream &databankFile);
void generarUsers(ifstream &inputFile, ofstream &usersFile);

// Variable auxiliar
string line;

int main()
{
    // Limpiamos la consola
    system("cls");

    // Inicializamos los objetos el fichero donde se obtendran los datos y el archivo donde se guardaran
    ifstream inputDatabank("../Banco de datos.txt");
    ofstream databankFile("../databank.sql");
    ofstream usersFile("../users.sql");

    // Ejecutamos la funcion para generar el databank con los inserts
    generarDatabank(inputDatabank, databankFile);

    // Cargamos nuevamente el banco de datos.txt
    ifstream inputUsers("../Banco de datos.txt");

    // Ejecutamos la funcion para generar el archivo sql con el script de usuarios
    generarUsers(inputUsers, usersFile);

    cout << "Archivos de datos generados correctamente, presione cualquier tecla y enter: ";
    cin >> line;
    return 0;
}

// Funcion para generar el databank
void generarDatabank(ifstream &inputFile, ofstream &databankFile)
{
    while (getline(inputFile, line))
    {
        // Creamos los atributos para la gestion de ficheros
        stringstream data(line);
        vector<string> fields;
        string field;

        // Dividir la línea en campos
        while (getline(data, field, ';'))
        {
            fields.push_back(field);
        }

        // Crear la sentencia SQL
        if (fields.size() >= 4)
        {
            // Verificamos si es tipo estudiante
            if (fields[1] == "Estudiante")
            {
                // Creamos la sentencia INSERT en estudiante con el orden solicitado
                databankFile << "INSERT INTO estudiante (carnet, nombre, correo) VALUES ('" << fields[2] << "', '" << fields[0] << "', '" << fields[3] << "');\n";
            }
            else
            {
                // En caso de ser Administrativo no cambia su valor
                int id_tipo = 0;
                // Comparamos el tipo de usuario
                if (fields[1] == "Coordinador")
                {
                    id_tipo = 1;
                }
                else if (fields[1] == "Docente")
                {
                    id_tipo = 2;
                }
                // Creamos la sentencia INSERT en empleado con el orden solicitado
                databankFile << "INSERT INTO empleado (carnet, nombre, correo, id_tipo_empleado) VALUES ('"
                             << fields[2] << "', '" << fields[0] << "', '" << fields[3] << "', '" << id_tipo << "');\n";
            }
        }
    }
    // Cerrando la conexion con los archivos
    inputFile.close();
    databankFile.close();
}

void generarUsers(ifstream &inputFile, ofstream &usersFile)
{
    while (getline(inputFile, line))
    {
        // Dividir la línea en campos separados por ;
        stringstream data(line);
        vector<string> fields;
        string field;
        while (getline(data, field, ';'))
        {
            fields.push_back(field);
        }

        // Obtener los valores de los campos
        string name = fields[0];
        string category = fields[1];
        string code = fields[2];
        string email = fields[3];

        // Generar una contraseña aleatoria de 10 caracteres (FIX)
        string password = generateChar() + generarClave();

        // Escribir la sentencia SQL en el archivo
        usersFile << "CREATE USER " << "user" << code << " IDENTIFIED BY \"" << password << "\";\n";

        // Asignar el tablespace y el rol según la categoría del usuario
        if (category == "Administrativo")
        {
            usersFile << "ALTER USER user" << code << " DEFAULT TABLESPACE T_EMPLEADOS QUOTA UNLIMITED ON T_EMPLEADOS PROFILE user_profile;\n";
            usersFile << "GRANT administrativo TO user" << code << ";\n";
        }
        else if (category == "Coordinador")
        {
            usersFile << "ALTER USER user" << code << " DEFAULT TABLESPACE T_EMPLEADOS QUOTA UNLIMITED ON T_EMPLEADOS PROFILE user_profile;\n";
            usersFile << "GRANT coordinador TO user" << code << ";\n";
        }
        else if (category == "Docente")
        {
            usersFile << "ALTER USER user" << code << " DEFAULT TABLESPACE T_EMPLEADOS QUOTA UNLIMITED ON T_EMPLEADOS PROFILE user_profile;\n";
            usersFile << "GRANT docente TO user" << code << ";\n";
        }
        else if (category == "Estudiante")
        {
            usersFile << "ALTER USER user" << code << " DEFAULT TABLESPACE T_ESTUDIANTES QUOTA UNLIMITED ON T_ESTUDIANTES PROFILE user_profile;\n";
            usersFile << "GRANT estudiante TO user" << code << ";\n";
        }
    }
    // Cerrando la conexion con los archivos
    inputFile.close();
    usersFile.close();
}

// Funcion para generar la clave con las comprabaciones ora12c_strong_verify_function
string generarClave()
{
    string password;
    // Dispositivo para generar una semilla aleatoria
    random_device rd;
    // Generador de números pseudoaleatorios basado en Mersenne Twister
    mt19937 gen(rd());
    // Distribución uniforme entre 0 y 61
    uniform_int_distribution<> dis(0, 61);
    // Bucle para generar 10 caractere
    for (int i = 0; i < 10; ++i)
    {
        // Genera un número aleatorio entre 0 y 61
        int r = dis(gen);
        if (r < 10)
        {
            // Si el número está entre 0 y 9, se añade un dígito al password
            password += '0' + r;
        }
        else if (r < 36)
        {
            // Si el número está entre 10 y 35, se añade una letra minúscula
            password += 'a' + r - 10;
        }
        else
        {
            // Si el número está entre 36 y 61, se añade una letra mayúscula
            password += 'A' + r - 36;
        }
    }
    // Retornamos la clave generada
    return password;
}

char generateChar()
{
    // Definición de la cadena de caracteres especiales permitidos.
    const string specialChars = "!$%@";
    // Crea un objeto 'random_device' para proporcionar una semilla aleatoria.
    random_device rd;
    // Utiliza 'random_device' (rd) para generar una semilla y la usa para inicializar 
    mt19937 gen(rd());
    // Crea una distribución de enteros uniforme que puede generar números 
    uniform_int_distribution<> dis(0, specialChars.size() - 1);
    // Retornamos el caracter generado
    return specialChars[dis(gen)];
}