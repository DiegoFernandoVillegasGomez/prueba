#include <iostream>

/*
Ejercicio – Conversor de Divisas: Euro y Dólar

En una casa de cambio, los clientes pueden consultar el valor de una divisa, comprar euros utilizando dólares o vender euros para recibir dólares.

El sistema trabajará con un tipo de cambio fijo establecido para el ejercicio. A partir de las funciones proporcionadas, implemente las tres operaciones solicitadas, aplicando correctamente cada mecanismo de paso de parámetros. Para facilitar el manejo de la información del cliente, se utilizará un struct Cliente que permitirá almacenar sus saldos en dólares y euros.

Funciones por implementar:

Consultar divisa (float precio de compra, float precio de venta), Muestra el tipo de cambio recibido utilizando paso por valor, sin modificar el valor original.
Comprar euros (float &dolares, float &euros, float precio de venta, float cantidad a comprar), Permite al cliente comprar euros utilizando sus dólares. La función deberá modificar los saldos de dólares y euros mediante paso por referencia.
Vender euros (float *euros, float *dolares float precio de compra, float cantidad a vender), Permite al cliente vender euros para recibir dólares. La función deberá modificar los saldos de euros y dólares mediante paso por puntero.
Requisitos del sistema

El programa deberá desarrollarse en C++.
La función main() deberá crear y manejar los saldos del cliente.
El cliente inicia con $1000.00 dólares y €500.00 euros.
Se utilizarán los siguientes valores fijos:
Precio de compra: 1 EUR = 1.08 USD
Precio de venta: 1 EUR = 1.12 USD
Al comprar euros, el cliente paga dólares utilizando el precio de venta.
Al vender euros, el cliente recibe dólares utilizando el precio de compra.
Las cantidades para comprar o vender deben ser mayores que 0.
Los saldos no pueden ser menores que 0.
Se deberán utilizar if para realizar las validaciones.
Cada operación deberá mostrar un mensaje indicando si fue realizada correctamente o si ocurrió un error.
Se deberá mostrar el saldo antes y después de cada operación.
El funcionamiento de las tres funciones deberá demostrarse mediante datos ingresados por el usuario.
El código deberá estar organizado y utilizar una estructura clara, respetando las convenciones de estilo para C++ por Google.
*/

struct Cliente {
  float saldo_dolares;
  float saldo_euros;
};

void consultar_divisa(float precio_compra, float precio_venta) {
  std::cout << "Precio de compra:  = " << precio_compra << " USD"<< std::endl;

  std::cout << "Precio de venta:  = " << precio_venta << " USD" << std::endl;
}

void comprar_euros(float &dolares, float &euros, float precio_venta, float cantidad_a_comprar) {
    
  std::cout << "Saldo antes: $ " << dolares << " | €" << euros << std::endl;

  if (cantidad_a_comprar <= 0) {
    std::cout << "Error: la cantidad a comprar debe ser mayor a 0."
              << std::endl;
    return;
  }

  float costo = cantidad_a_comprar * precio_venta;

  if (dolares < costo) {
    std::cout << "Saldo insuficiente de dolares." << std::endl;
    return;
  }

  dolares -= costo;
  euros += cantidad_a_comprar;
  std::cout << "Operacion realizada con exito." << std::endl;
  std::cout << "Saldo despues: $" << dolares << " | €" << euros << std::endl;
}

void vender_euros(float *euros, float *dolares, float precio_compra, float cantidad_a_vender) {

  std::cout << "Saldo antes: $" << *dolares << " | €" << *euros << std::endl;

  if (cantidad_a_vender <= 0) {
    std::cout << "Error: la cantidad a vender debe ser mayor a 0." << std::endl;
    return;
  }

  if (*euros < cantidad_a_vender) {
    std::cout << "Error: saldo insuficiente de euros." << std::endl;
    return;
  }

  *euros -= cantidad_a_vender;
  *dolares += cantidad_a_vender * precio_compra;
  
  std::cout << "Operacion realizada con exito." << std::endl;
  std::cout << "Saldo despues: $" << *dolares << " | €" << *euros << std::endl;
}

int main() {
  const float PrecioCompra = 1.08f;
  const float PrecioVenta = 1.12f;
  Cliente cliente = {1000.00f, 500.00f};
  float cantidad = 0;

  consultar_divisa(PrecioCompra, PrecioVenta);

  std::cout << "Cantidad de euros a comprar: ";
  std::cin >> cantidad;

  comprar_euros(cliente.saldo_dolares, cliente.saldo_euros, PrecioVenta, cantidad);

  std::cout << "Cantidad de euros a vender: ";
  std::cin >> cantidad;

  vender_euros(&cliente.saldo_euros, &cliente.saldo_dolares, PrecioCompra,  cantidad);

  return 0;
}
