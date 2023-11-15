#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    // Limpiamos la consola
    system("cls");

    // Inicializamos los objetos el fichero donde se obtendran los datos y el archivo donde se guardaran
    ifstream inputFile("../Banco de datos.txt"); 
    ofstream outputFile("../databank.sql");

    string line;

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
                outputFile << "INSERT INTO estudiante (carnet, nombre, correo) VALUES ('"
                       << fields[2] << "', '" << fields[0] << "', '" << fields[3] << "');\n";
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
                outputFile << "INSERT INTO empleado (carnet, nombre, correo, id_tipo_empleado) VALUES ('"
                       << fields[2] << "', '" << fields[0] << "', '" << fields[3] << "', '" << id_tipo << "');\n";
            }
        }
    }
    // Cerrando la conexion con los archivos
    inputFile.close();
    outputFile.close();

    cout << "Databank generado correctamente, presione cualquier tecla y luego enter para salir!!!";
    cin >> line;

    return 0;
}
