import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ProcesadorOptimizado {

    public static void procesar(List<Cliente> clientes) {

        HashMap<String, List<Cliente>> campanias = new HashMap<>();

        long inicio = System.currentTimeMillis();

        for (Cliente cliente : clientes) {

            String tipo = determinarCampania(cliente);

            campanias
                    .computeIfAbsent(tipo, k -> new ArrayList<>())
                    .add(cliente);
        }

        long fin = System.currentTimeMillis();

        System.out.println("\n===== RESUMEN DE CAMPAÑAS =====");
        System.out.println("Total campañas: " + campanias.size());

        for (Map.Entry<String, List<Cliente>> entry : campanias.entrySet()) {

            System.out.println(
                    entry.getKey()
                            + ": "
                            + entry.getValue().size()
            );
        }

        System.out.println(
                "\nTiempo de procesamiento optimizado: "
                        + (fin - inicio)
                        + " ms"
        );
    }

    private static String determinarCampania(Cliente cliente) {

        String nivelIngreso;

        if (cliente.getIngreso() >= 25000) {
            nivelIngreso = "INGRESO_ALTO";
        }
        else if (cliente.getIngreso() >= 15000) {
            nivelIngreso = "INGRESO_MEDIO";
        }
        else if (cliente.getIngreso() >= 10000) {
            nivelIngreso = "INGRESO_BAJO";
        }
        else {
            nivelIngreso = "NO_APLICA";
        }

        String nivelScore;

        if (cliente.getScore() >= 800) {
            nivelScore = "SCORE_EXCELENTE";
        }
        else if (cliente.getScore() >= 600) {
            nivelScore = "SCORE_BUENO";
        }
        else if (cliente.getScore() >= 400) {
            nivelScore = "SCORE_REGULAR";
        }
        else {
            nivelScore = "SCORE_RIESGO";
        }

        String nivelDeuda;

        if (cliente.getDeuda() >= 7000) {
            nivelDeuda = "DEUDA_ALTA";
        }
        else if (cliente.getDeuda() >= 3000) {
            nivelDeuda = "DEUDA_MEDIA";
        }
        else {
            nivelDeuda = "DEUDA_BAJA";
        }

        return cliente.getSegmento()
                + "_"
                + cliente.getRegion()
                + "_"
                + nivelIngreso
                + "_"
                + nivelScore
                + "_"
                + nivelDeuda;
    }
}