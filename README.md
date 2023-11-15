# UNIVERSIDAD CENTROAMERICANA "JOSE SIMEON CAÑAS"
## "IMPLEMENTACIÓN DE UN NUEVO SISTEMA INFORMÁTICO"

## Información del Proyecto

- *Materia:* Administración de Bases de Datos
- *Catedrático:* Erick Varela
-  *Fecha:* Miercoles 14 de  Noviembre del 2023
- *Alumnos:*
  - Diego Eduardo Castro Quintanilla (Carnet: 00117322)
  - Katherin Gabriela Pérez Baires (Carnet: 00141621)

## Descripción del problema
La universidad se enfrenta a un reto importante con la implementación de un nuevo sistema digital para optimizar tareas administrativas, reemplazando los antiguos métodos manuales. Este cambio, previsto para empezar en el nuevo año académico, ha encontrado un obstáculo: la necesidad urgente de preparar una prueba piloto para el 14 de noviembre. El jefe del departamento de tecnologías ha revelado que se dispone de un banco de datos con información básica de 5000 personas, cada una asignada a un rol específico (estudiante, docente, administrativo, director), y que el sistema se desarrollará en Oracle Database.

## Descripción de la solución
 Como programadores hemos tratado de encontrar la solucion mas eficiente para resolver la problematica llegando a la conclusion que lo mas eficiente es este código el cual esta escrito en en C++  ya que convierte datos de un archivo de texto en instrucciones SQL para tablas 'estudiante' y 'empleado', y para crear usuarios con contraseñas seguras. Utiliza estructuras eficientes como `stringstream` y `vector<string>` para procesar y organizar los datos. Además, implementa un sistema de generación de contraseñas seguras combinando caracteres alfanuméricos y especiales, utilizando un generador de números aleatorios avanzado y una distribución uniforme para asegurar aleatoriedad y seguridad en las contraseñas.


## Instrucciones de Uso

Para utilizar este código, primero coloque un archivo de texto llamado "Banco de datos.txt" en la misma carpeta del programa con datos separados por punto y coma (;). Compile y ejecute el programa en C++. Este generará dos archivos SQL, `databank.sql` y `users.sql`, con comandos para insertar datos en las tablas y crear usuarios con contraseñas seguras. Asegúrese de tener las tablas relevantes creadas en su base de datos SQL para utilizar los scripts generados.

## Links
[Google Drive](https://drive.google.com/drive/folders/14juJdmqe8L_foTnyZSA4dC01tizuzCdH?usp=sharing)
[GitHub](https://github.com/DarkCastro24/Taller-2-ABD)