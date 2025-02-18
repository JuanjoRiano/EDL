package estructuras;

public class Main {

    public static void main(String[] args) {
        // Pila de enteros
        Pila<Integer> pila = new Pila<>();
        pila.push(5);
        pila.push(15);
        pila.push(25);
        pila.push(35);
        pila.pop();
        pila.pop();
        System.out.println("Tamaño de la pila: " + pila.size()); // 2
        System.out.println("Cima de la pila: " + pila.peek()); // 15

        // Cola de cadenas
        Cola<String> cola = new Cola<>();
        cola.push("Juan");
        cola.push("María");
        cola.push("Carlos");
        cola.push("Lucía");
        cola.pop();
        cola.pop();
        System.out.println("Tamaño de la cola: " + cola.tamaño()); // 2
        System.out.println("Frente de la cola: " + cola.frente()); // "Carlos"
    }
}
