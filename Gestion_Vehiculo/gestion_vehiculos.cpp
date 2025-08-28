#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Clase base Vehiculo
class Vehiculo {
protected:
  string marca;
  string modelo;
  int anio;
  double precioBase;

public:
  // Constructor
  Vehiculo(string marca, string modelo, int anio, double precioBase)
      : marca(marca), modelo(modelo), anio(anio), precioBase(precioBase) {}

  // Destructor virtual
  virtual ~Vehiculo() {}

  // Método virtual para calcular precio final
  virtual double calcularPrecioFinal() const {
    return precioBase;
  }

  // Getters
  string getMarca() const { return marca; }
  string getModelo() const { return modelo; }
  int getAnio() const { return anio; }
  double getPrecioBase() const { return precioBase; }
};

// Clase derivada de Auto
class Auto : public Vehiculo {
private:
  int numeroPuertas;

public:
  // Constructor
  Auto(string marca, string modelo, int anio, double precioBase,
       int numeroPuertas)
      : Vehiculo(marca, modelo, anio, precioBase), numeroPuertas(numeroPuertas) {
  }

  // Anulación del método calcularPrecioFinal
  double calcularPrecioFinal() const override {
    double impuesto = precioBase * 0.15; 
    return precioBase + impuesto;
  }

  // Getter adicional
  int getNumeroPuertas() const { return numeroPuertas; }
};

// Clase derivada de Moto
class Moto : public Vehiculo {
private:
  int cilindrada;

public:
  // Constructor
  Moto(string marca, string modelo, int anio, double precioBase, int cilindrada)
      : Vehiculo(marca, modelo, anio, precioBase), cilindrada(cilindrada) {}

  // Anulación del método calcularPrecioFinal
  double calcularPrecioFinal() const override {
    double impuesto = precioBase * 0.10;
    return precioBase + impuesto;
  }

  // Getter adicional
  int getCilindrada() const { return cilindrada; }
};

int main() {
  // Vector de punteros a Vehiculo
  vector<Vehiculo *> vehiculos;

  // Crear objetos de Auto y Moto dinámicamente
  vehiculos.push_back(new Auto("Toyota", "Corolla", 2023, 25000.0, 4));
  vehiculos.push_back(new Moto("Honda", "CBR600RR", 2023, 12000.0, 600));
  vehiculos.push_back(new Auto("Ford", "Mustang", 2023, 45000.0, 2));
  vehiculos.push_back(new Moto("Yamaha", "YZF-R1", 2023, 18000.0, 1000));

  cout << "=== GESTIÓN DE VEHÍCULOS - CONCESIONARIA ===" << endl;
  cout << "=============================================" << endl;

  // Recorrer el vector e imprimir información de cada vehículo
  for (size_t i = 0; i < vehiculos.size(); i++) {
    Vehiculo *vehiculo = vehiculos[i];

    cout << "\nVehículo #" << (i + 1) << ":" << endl;
    cout << "Marca: " << vehiculo->getMarca() << endl;
    cout << "Modelo: " << vehiculo->getModelo() << endl;
    cout << "Año: " << vehiculo->getAnio() << endl;
    cout << "Precio Base: $" << vehiculo->getPrecioBase() << endl;

    // Usar polimorfismo para obtener información específica
    if (Auto *auto_ptr = dynamic_cast<Auto *>(vehiculo)) {
      cout << "Tipo: Auto" << endl;
      cout << "Número de Puertas: " << auto_ptr->getNumeroPuertas() << endl;
    } else if (Moto *moto_ptr = dynamic_cast<Moto *>(vehiculo)) {
      cout << "Tipo: Moto" << endl;
      cout << "Cilindrada: " << moto_ptr->getCilindrada() << "cc" << endl;
    }

    // Calcular precio final usando polimorfismo
    double precioFinal = vehiculo->calcularPrecioFinal();
    cout << "Precio Final (con impuestos): $" << precioFinal << endl;
    cout << "----------------------------------------" << endl;
  }

  // Liberar memoria
  for (Vehiculo *vehiculo : vehiculos) {
    delete vehiculo;
  }
  vehiculos.clear();

  cout << "\nMemoria liberada correctamente." << endl;

  return 0;
}