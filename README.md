# UNIVERSIDAD CENTROAMERICANA "JOSE SIMEON CA�AS"
## "IMPLEMENTACI�N DE UN NUEVO SISTEMA INFORM�TICO"

## Informaci�n del Proyecto

- *Materia:* Administraci�n de Bases de Datos
- *Catedr�tico:* Erick Varela
-  *Fecha:* Miercoles 14 de  Noviembre del 2023
- *Alumnos:*
  - Diego Eduardo Castro Quintanilla (Carnet: 00117322)
  - Katherin Gabriela P�rez Baires (Carnet: 00141621)

## Descripci�n del problema
La universidad se enfrenta a un reto importante con la implementaci�n de un nuevo sistema digital para optimizar tareas administrativas, reemplazando los antiguos m�todos manuales. Este cambio, previsto para empezar en el nuevo a�o acad�mico, ha encontrado un obst�culo: la necesidad urgente de preparar una prueba piloto para el 14 de noviembre. El jefe del departamento de tecnolog�as ha revelado que se dispone de un banco de datos con informaci�n b�sica de 5000 personas, cada una asignada a un rol espec�fico (estudiante, docente, administrativo, director), y que el sistema se desarrollar� en Oracle Database.

## Descripci�n de la soluci�n
 Como programadores hemos tratado de encontrar la solucion mas eficiente para resolver la problematica llegando a la conclusion que lo mas eficiente es este c�digo el cual esta escrito en en C++  ya que convierte datos de un archivo de texto en instrucciones SQL para tablas 'estudiante' y 'empleado', y para crear usuarios con contrase�as seguras. Utiliza estructuras eficientes como `stringstream` y `vector<string>` para procesar y organizar los datos. Adem�s, implementa un sistema de generaci�n de contrase�as seguras combinando caracteres alfanum�ricos y especiales, utilizando un generador de n�meros aleatorios avanzado y una distribuci�n uniforme para asegurar aleatoriedad y seguridad en las contrase�as.


## Instrucciones de Uso

Para utilizar este c�digo, primero coloque un archivo de texto llamado "Banco de datos.txt" en la misma carpeta del programa con datos separados por punto y coma (;). Compile y ejecute el programa en C++. Este generar� dos archivos SQL, `databank.sql` y `users.sql`, con comandos para insertar datos en las tablas y crear usuarios con contrase�as seguras. Aseg�rese de tener las tablas relevantes creadas en su base de datos SQL para utilizar los scripts generados.

## Links
[Google Drive](https://drive.google.com/drive/folders/14juJdmqe8L_foTnyZSA4dC01tizuzCdH?usp=sharing)
[GitHub](https://github.com/DarkCastro24/Taller-2-ABD)