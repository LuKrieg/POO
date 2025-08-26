#include <iostream>
#include <string>
#include <vector>

// --- Clase Libro ---
class Libro {
public:
    std::string titulo;
    std::string autor;
    int anioPublicacion;
    bool estaDisponible; // Nuevo atributo

    // Constructor para inicializar los valores fácilmente
    Libro() : titulo(""), autor(""), anioPublicacion(0), estaDisponible(true) {}

    void mostrarDetallesCompletos() {
        std::cout << "Titulo: " << titulo << std::endl;
        std::cout << "Autor: " << autor << std::endl;
        std::cout << "Anio de publicacion: " << anioPublicacion << std::endl;
        std::cout << "Disponible: " << (estaDisponible ? "Si" : "No") << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
};

// Clase para la biblioteca
class Biblioteca {
private:
    std::vector<Libro> coleccion;

public:
    void agregarLibro(const Libro& nuevoLibro) {
        coleccion.push_back(nuevoLibro);
        std::cout << "Libro agregado correctamente.\n";
    }

    void mostrarInventario() {
        if (coleccion.empty()) {
            std::cout << "La biblioteca esta vacia.\n";
            return;
        }

        for (auto& libro : coleccion) {
            libro.mostrarDetallesCompletos();
        }
    }

    Libro* buscarLibro(const std::string& tituloBuscado) {
        for (auto& libro : coleccion) {
            if (libro.titulo == tituloBuscado) {
                return &libro;
            }
        }
        return nullptr;
    }

    void prestarLibro(const std::string& tituloPrestamo) {
        Libro* libro = buscarLibro(tituloPrestamo);
        if (libro == nullptr) {
            std::cout << "Libro no encontrado.\n";
        } else if (!libro->estaDisponible) {
            std::cout << "El libro ya ha sido prestado.\n";
        } else {
            libro->estaDisponible = false;
            std::cout << "Libro prestado correctamente.\n";
        }
    }

    void devolverLibro(const std::string& tituloDevolucion) {
        Libro* libro = buscarLibro(tituloDevolucion);
        if (libro == nullptr) {
            std::cout << "Libro no encontrado.\n";
        } else if (libro->estaDisponible) {
            std::cout << "El libro ya estaba disponible.\n";
        } else {
            libro->estaDisponible = true;
            std::cout << "Libro devuelto correctamente.\n";
        }
    }
};

// Menú de función principal
int main() {
    Biblioteca miBiblioteca;
    int opcion = 0;

    // Agregar un libro de ejemplo
    Libro libroInicial;
    libroInicial.titulo = "Los diarios de la boticaria";
    libroInicial.autor = "Natsu Hyuga";
    libroInicial.anioPublicacion = 2014;
    miBiblioteca.agregarLibro(libroInicial);

    while (opcion != 5) {
        std::cout << "\n--- BIBLIOTECA DIGITAL ---\n";
        std::cout << "1. Anadir libro\n";
        std::cout << "2. Mostrar inventario\n";
        std::cout << "3. Prestar libro\n";
        std::cout << "4. Devolver libro\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar el buffer

        if (opcion == 1) {
            Libro nuevoLibro;
            std::cout << "Ingrese el titulo: ";
            std::getline(std::cin, nuevoLibro.titulo);
            std::cout << "Ingrese el autor: ";
            std::getline(std::cin, nuevoLibro.autor);
            std::cout << "Ingrese el anio de publicacion: ";
            std::cin >> nuevoLibro.anioPublicacion;
            std::cin.ignore();

            miBiblioteca.agregarLibro(nuevoLibro);
        } else if (opcion == 2) {
            miBiblioteca.mostrarInventario();
        } else if (opcion == 3) {
            std::string titulo;
            std::cout << "Ingrese el titulo del libro a prestar: ";
            std::getline(std::cin, titulo);
            miBiblioteca.prestarLibro(titulo);
        } else if (opcion == 4) {
            std::string titulo;
            std::cout << "Ingrese el titulo del libro a devolver: ";
            std::getline(std::cin, titulo);
            miBiblioteca.devolverLibro(titulo);
        } else if (opcion == 5) {
            std::cout << "Saliendo del programa...\n";
        } else {
            std::cout << "Opcion invalida.\n";
        }
    }

    return 0;
}
