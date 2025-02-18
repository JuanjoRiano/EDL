package estructuras;

// Mateo 20:16

public class Pila<T> {
    private Nodo<T> tope;
    private int tamaño;

    public Pila() {
        this.tope = null;
        this.tamaño = 0;
    }

    public void push (T dato) {
        Nodo<T> nuevoNodo = new Nodo<>(dato);
        nuevoNodo.setSiguiente(tope);
        tope = nuevoNodo;
        tamaño++;
    }

    public T pop () {
        if (isEmpty()) {
            throw new IllegalStateException("La pila está vacía");
        }
        T dato = tope.getDato();
        tope = tope.getSiguiente();
        tamaño--;
        return dato;
    }

    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("La pila está vacía");
        }
        return tope.getDato();
    }

    public boolean isEmpty() {
        return tope == null;
    }

    public int size() {
        return tamaño;
    }
}
