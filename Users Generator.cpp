#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>

using namespace std;

char generateCharacter();

int main()
{
    // Variable auxiliar
    string line;
    // Abrir el archivo Banco de datos.txt
    ifstream inputFile("../Banco de datos.txt");
    if (!inputFile.is_open())
    {
        cerr << "No se pudo abrir el archivo Banco de datos.txt" << endl;
        return 1;
    }

    // Crear un archivo para guardar las sentencias SQL
    ofstream outputFile("../users.sql");
    if (!outputFile.is_open())
    {
        cerr << "No se pudo crear el archivo users.sql" << endl;
        return 1;
    }

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
        string password;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 61);
        for (int i = 0; i < 10; ++i)
        {
            int r = dis(gen);
            if (r < 10)
            {
                password += '0' + r;
            }
            else if (r < 36)
            {
                password += 'a' + r - 10;
            }
            else
            {
                password += 'A' + r - 36;
            }
        }

        password = generateCharacter() + password;

        // Escribir la sentencia SQL en el archivo
        outputFile << "CREATE USER "
                   << "user" << code << " IDENTIFIED BY \"" << password << "\";\n";

        // Asignar el tablespace y el rol según la categoría del usuario
        if (category == "Administrativo")
        {
            outputFile << "ALTER USER user" << code << " DEFAULT TABLESPACE T_EMPLEADOS QUOTA UNLIMITED ON T_EMPLEADOS PROFILE user_profile;\n";
            outputFile << "GRANT administrativo TO user" << code << ";\n";
        }
        else if (category == "Coordinador")
        {
            outputFile << "ALTER USER user" << code << " DEFAULT TABLESPACE T_EMPLEADOS QUOTA UNLIMITED ON T_EMPLEADOS PROFILE user_profile;\n";
            outputFile << "GRANT coordinador TO user" << code << ";\n";
        }
        else if (category == "Docente")
        {
            outputFile << "ALTER USER user" << code << " DEFAULT TABLESPACE T_EMPLEADOS QUOTA UNLIMITED ON T_EMPLEADOS PROFILE user_profile;\n";
            outputFile << "GRANT docente TO user" << code << ";\n";
        }
        else if (category == "Estudiante")
        {
            outputFile << "ALTER USER user" << code << " DEFAULT TABLESPACE T_ESTUDIANTES QUOTA UNLIMITED ON T_ESTUDIANTES PROFILE user_profile;\n";
            outputFile << "GRANT estudiante TO user" << code << ";\n";
        }
    }

    // Cerrando la conexion con los archivos
    inputFile.close();
    outputFile.close();

    cout << "Archivos users.sql generado correctamente, presione una tecla y presione enter" << endl;
    cin >> line;

    return 0;
}

char generateCharacter()
{
    const string specialChars = "!$%@";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, specialChars.size() - 1);
    return specialChars[dis(gen)];
}