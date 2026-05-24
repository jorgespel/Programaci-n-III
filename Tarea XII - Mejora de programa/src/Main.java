import java.util.List;

public class Main {

    public static void main(String[] args) {

        String archivo = "clientes.csv";

        // Puedes cambiar este valor para pruebas
        int cantidadClientes = 500000;

        System.out.println("======================================");
        System.out.println("Nombre del estudiante: Jorge Eduardo Espel Melgar");
        System.out.println("Carnet: 9941-24-10596");
        System.out.println("Curso: Programacion III");
        System.out.println("Actividad: Tarea XII");
        System.out.println("======================================");

        long inicioGeneracion = System.currentTimeMillis();

        GeneradorClientes.generarArchivo(
                archivo,
                cantidadClientes
        );

        long finGeneracion = System.currentTimeMillis();

        System.out.println(
                "\nTiempo generación: "
                        + (finGeneracion - inicioGeneracion)
                        + " ms"
        );

        mostrarMemoria();

        System.out.println(
                "\nCargando clientes..."
        );

        long inicioCarga = System.currentTimeMillis();

        List<Cliente> clientes =
                ProcesadorMalo.cargarTodosLosClientes(
                        archivo
                );

        long finCarga = System.currentTimeMillis();

        System.out.println(
                "Clientes cargados: "
                        + clientes.size()
        );

        System.out.println(
                "Tiempo carga: "
                        + (finCarga - inicioCarga)
                        + " ms"
        );

        mostrarMemoria();

        System.out.println(
                "\n===== PROCESAMIENTO ORIGINAL ====="
        );

        ProcesadorIneficiente.procesar(
                clientes
        );

        System.out.println(
                "\n===== PROCESAMIENTO OPTIMIZADO ====="
        );

        ProcesadorOptimizado.procesar(
                clientes
        );

        mostrarMemoria();

        System.out.println(
                "\nProceso finalizado."
        );
    }

    private static void mostrarMemoria() {

        Runtime runtime = Runtime.getRuntime();

        long usada =
                runtime.totalMemory()
                        - runtime.freeMemory();

        System.out.println(
                "\nMemoria usada: "
                        + (usada / 1024 / 1024)
                        + " MB"
        );
    }
}