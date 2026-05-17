import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        HashMap<Integer, Estudiante> estudiantes = new HashMap<>();

        Scanner scanner = new Scanner(System.in);

        System.out.println("================================");
        System.out.println("Nombre del estudiante: Jorge Eduardo Espel Melgar");
        System.out.println("Carnet: 9941-24-10596");
        System.out.println("Curso: Programacion III");
        System.out.println("================================");

        // CARGAR CSV
        try {

            BufferedReader br = new BufferedReader(
                    new FileReader("estudiantes.csv")
            );

            String linea;

            // Saltar encabezado
            br.readLine();

            while ((linea = br.readLine()) != null) {

                String[] datos = linea.split(",");

                int studentId = Integer.parseInt(datos[0]);
                String fullName = datos[1];
                String career = datos[2];
                int semester = Integer.parseInt(datos[3]);
                double gpa = Double.parseDouble(datos[4]);
                int skillScore = Integer.parseInt(datos[5]);

                // Validar duplicados
                if (estudiantes.containsKey(studentId)) {

                    System.out.println(
                            "Estudiante duplicado encontrado: "
                                    + studentId
                    );

                } else {

                    Estudiante estudiante = new Estudiante(
                            studentId,
                            fullName,
                            career,
                            semester,
                            gpa,
                            skillScore
                    );

                    estudiantes.put(studentId, estudiante);
                }
            }

            br.close();

            System.out.println("\nArchivo CSV cargado correctamente.");

        } catch (IOException e) {

            System.out.println("Error al leer el archivo CSV.");
        }

        int opcion;

        do {

            System.out.println("\n========= MENU =========");
            System.out.println("1. Buscar estudiante");
            System.out.println("2. Eliminar estudiante");
            System.out.println("3. Mostrar estudiantes");
            System.out.println("4. Mostrar total");
            System.out.println("5. Salir");

            System.out.print("Seleccione una opcion: ");
            opcion = scanner.nextInt();

            if (opcion == 1) {

                System.out.print("Ingrese ID: ");
                int idBuscar = scanner.nextInt();

                if (estudiantes.containsKey(idBuscar)) {

                    System.out.println("\n=== ESTUDIANTE ENCONTRADO ===");

                    System.out.println(
                            estudiantes.get(idBuscar)
                    );

                } else {

                    System.out.println("Estudiante no encontrado.");
                }
            }

            else if (opcion == 2) {

                System.out.print("Ingrese ID a eliminar: ");
                int idEliminar = scanner.nextInt();

                if (estudiantes.containsKey(idEliminar)) {

                    estudiantes.remove(idEliminar);

                    System.out.println(
                            "Estudiante eliminado correctamente."
                    );

                } else {

                    System.out.println(
                            "No existe estudiante con ese ID."
                    );
                }
            }

            else if (opcion == 3) {

                System.out.println("\n=== ESTUDIANTES ===");

                for (Integer key : estudiantes.keySet()) {

                    System.out.println("-------------------");

                    System.out.println(
                            estudiantes.get(key)
                    );
                }
            }

            else if (opcion == 4) {

                System.out.println(
                        "\nTotal estudiantes cargados: "
                                + estudiantes.size()
                );

                System.out.println(
                        "Estructura utilizada: HashMap<Integer, Estudiante>"
                );
            }

            else if (opcion == 5) {

                System.out.println("Saliendo del programa...");
            }

            else {

                System.out.println("Opcion invalida.");
            }

        } while (opcion != 5);

        scanner.close();
    }
}