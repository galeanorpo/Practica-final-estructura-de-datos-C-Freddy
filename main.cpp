#include <iostream>
#include <sstream>
#include <list> // libreria para listas simples
#include <queue> // librería para colas
#include <stack> //libreria para las pilas

using namespace std;

class Cliente{	
	public:
		std::string id;
		std::string nombre;
		int estratoSocial;
		std::string ciudad;
		bool activo;
		
		
		Cliente() {
        	
    	}
    	
		Cliente(std::string id, std::string nombre,int estratoSocial,std::string ciudad, bool activo) {
        	this->id = id;
			this->nombre = nombre;
        	this->estratoSocial = estratoSocial;
			this->ciudad = ciudad;
			this->activo = activo;
    	}
		
		void imprimirInformacion() {
			std::cout << "Id: " << id << std::endl;
	        std::cout << "Nombre: " << nombre << std::endl;
	        std::cout << "Estrato social: " << estratoSocial << std::endl;
			std::cout << "Ciudad: " << ciudad << std::endl;
			std::cout << "Activo: " << (activo ? "Si" : "No") << std::endl;
    	}
    	
    	friend std::ostream& operator<<(std::ostream& os, const Cliente& cliente) {
	        os << "Id: " << cliente.id << ", Nombre: " << cliente.nombre
	           << ", Estrato: " << cliente.estratoSocial << ", Ciudad: " << cliente.ciudad
	           << ", Activo: " << (cliente.activo ? "Si" : "No");
	        return os;
    	}		
		
	std::string toString() {
	    std::ostringstream oss;
	    oss << "Id: " << id << "\n";
	    oss << "Nombre: " << nombre << "\n";
	    oss << "Estrato social: " << estratoSocial << "\n";
	    oss << "Ciudad: " << ciudad << "\n";
	    oss << "Activo: " << (activo ? "Si" : "No") << "\n";
	    return oss.str();
	}
				
};

class Cuenta{
	public:
		string numeroCuenta;
		string identificacion;
		int saldo;
		bool activo;
		
		Cuenta(){
			
		}
		
		Cuenta(string numeroCuenta, string identificacion, int saldo, bool activo){
			this->numeroCuenta = numeroCuenta;
			this->identificacion = identificacion;
			this->saldo = saldo; 
			this->activo = activo;
		}
		
		friend std::ostream& operator<<(std::ostream& os, const Cuenta& cuenta) {
	        os << "Numero de Cuenta: " << cuenta.numeroCuenta << "\n";
	        os << "Identificacion: " << cuenta.identificacion << "\n";
	        os << "Saldo: " << cuenta.saldo << "\n";
	        os << "Activo: " << (cuenta.activo ? "Si" : "No") << "\n";
        return os;
    }
    
    std::string toString() {
	    std::ostringstream oss;
	    oss << "Numero de Cuenta: " << numeroCuenta << "\n";
	    oss << "Identificacion: " << identificacion << "\n";
	    oss << "Saldo: " << saldo << "\n";
	    oss << "Activo: " << (activo ? "Si" : "No") << "\n";
	    return oss.str();
	}
};

class Operaciones{
	public:
		string numeroCuenta;
		string fecha;
		int valor;
		string tipoTransaccion;
		bool activo;
		
	Operaciones(){
		
	}
	
	Operaciones(string numeroCuenta, string fecha, int valor, string tipoTransaccion, bool activo){
		this->numeroCuenta = numeroCuenta;
		this->fecha = fecha;
		this->valor = valor;
		this->tipoTransaccion = tipoTransaccion;
		this->activo = activo;
	}
	
	 friend std::ostream& operator<<(std::ostream& os, const Operaciones& operacion) {
        os << "Número de Cuenta: " << operacion.numeroCuenta << "\n";
        os << "Fecha: " << operacion.fecha << "\n";
        os << "Valor: " << operacion.valor << "\n";
        os << "Tipo de Transacción: " << operacion.tipoTransaccion << "\n";
        os << "Activo: " << (operacion.activo ? "Si" : "No") << "\n";
        return os;
    }
};

bool verificarIdentidad(string identidad, list<Cliente> listClients){
	bool encontrado = false;
	for (std::list<Cliente>::iterator it = listClients.begin(); it != listClients.end(); ++it) {
        	Cliente& elemento = *it; 
			if(elemento.id == identidad){
				encontrado = true;	
				break;
		}
	}
    return encontrado;
}

bool verificarNumeroCuenta(string nCuenta, list<Cuenta> listCuentas){
	bool encontrado = false;
	for (std::list<Cuenta>::iterator it = listCuentas.begin(); it != listCuentas.end(); ++it) {
        	Cuenta& elemento = *it; 
			if(elemento.numeroCuenta == nCuenta){
				encontrado = true;	
				break;
		}
	}
    return encontrado;
}

Operaciones getInfoOp(list<Cuenta> listCuentas){
	string numeroCuenta, fecha, tipoTransaccion;
	int valor, opTipoTransaccion;
	do{
		std::cout << "Ingresa el numero de cuenta: ";
    	std::cin >> numeroCuenta;
		if(!listCuentas.empty()){
			if(verificarNumeroCuenta(numeroCuenta, listCuentas)){
				std::cout << "Ingrese la fecha de la operacion: " << std::endl;
				std::cin >> fecha;
				std::cout << "Ingrese el valor de la operacion: " << std::endl;
				std::cin >> valor;
				std::cout << "Ingrese el tipo de transaccion, seleccione una opcion:" << std::endl;
				std::cout << "1. Credito" << std::endl;
				std::cout << "2. Prestamo" << std::endl;
				std::cout << "3. Deposito" << std::endl;
				std::cin >> opTipoTransaccion;
				if(opTipoTransaccion == 1){
					tipoTransaccion = "Credito";
				}else if(opTipoTransaccion == 2){
					tipoTransaccion = "Prestamo";
				}else if(opTipoTransaccion == 3){
					tipoTransaccion = "Deposito";
				}else{
					tipoTransaccion = "NA";
				}
				Operaciones op1(numeroCuenta, fecha, valor, tipoTransaccion, true);
				std::cout << "Operacion registrada correctamente..." << std::endl;
				return Operaciones();
			}else{
				std::cout << "No esta registrado en el sistema la cuenta " <<numeroCuenta <<" Ingresa otro o registralo en el sistema" << std::endl;
				return Operaciones();
			}
		}else{
			std::cout << "De momento no hay cuentas registradas... Ingresa primero una cuenta" << std::endl;
			return Operaciones();
		}
	}while(verificarNumeroCuenta(numeroCuenta, listCuentas));
}

Cuenta getInfoCuenta(list<Cliente> listClients, list<Cuenta> listCuentas, stack<Cuenta>& pilaCuentas){
	string nCuenta, identificacion;
	int saldoI;
	bool flagSaldo = false;
	 do{
		std::cout << "Ingresa tu numero de cuenta: ";
    	std::cin >> nCuenta;
		if(verificarNumeroCuenta(nCuenta, listCuentas)){
			std::cout << "El numero de cuenta ya esta registrado... intenta con otro" << std::endl;
		}
	}while(verificarNumeroCuenta(nCuenta, listCuentas));
    do{
    	std::cout << "Ingresa tu identificacion: ";
    	std::cin >> identificacion;
    	if(!listClients.empty()){
    		if(!verificarIdentidad(identificacion, listClients)){
				std::cout << "No hay ningun id de cliente para poder registrar una cuenta..." << std::endl;
			}
		}else{
				std::cout << "No hay ningun cliente registrado aun... ingresa primero clientes para poder registrar cuentas..." << std::endl;
				return Cuenta();
		}
		
	}while(!verificarIdentidad(identificacion, listClients));
    do{
    	std::cout << "Ingresa tu saldo inicial: ";
    	std::cin >> saldoI;
    	if(saldoI < 100000){
    		std::cout << "El saldo inicial debe ser mayor a 100.000: " << std::endl;
    		flagSaldo = true;
		}else{
			flagSaldo = false;
		}
	}while(flagSaldo);
	Cuenta cuenta(nCuenta, identificacion, saldoI, true);
	if(saldoI >= 5000000){
		pilaCuentas.push(cuenta);
	}
	std::cout << "Cuenta registrada con exito..."  << std::endl;
    return cuenta;
}

Cliente getInfoClient(list<Cliente> listClients, queue<Cliente>& clientesCola){
	string id, nombre, ciudad;
	int estratoSocial;
	bool activo;
    do{
    	std::cout << "Ingresa tu id: ";
    	std::cin >> id;
		if(verificarIdentidad(id, listClients)){
			std::cout << "El id ya esta registrado... intenta con otro" << std::endl;
		}
	}while(verificarIdentidad(id, listClients));
    std::cout << "Ingresa tu nombre: ";
    std::cin >> nombre;
    std::cout << "Ingresa tu estrato social: ";
    std::cin >> estratoSocial;
    std::cout << "Ingresa tu ciudad: ";
    std::cin >> ciudad;
    Cliente cliente(id, nombre, estratoSocial, ciudad, true);
    if(estratoSocial >= 4){
    	if(ciudad == "cali" || ciudad == "Cali"){
    		clientesCola.push(cliente);
		}
	}
    std::cout << "Cliente registrado con exito..."  << std::endl;
    return cliente;
}

int menu(){
		int op = 0;
		std::cout << "BIENVENIDO AL SISTEMA" << std::endl;
		std::cout << "Seleccione una opcion" << std::endl;
		std::cout << "1. Gestion de clientes" << std::endl;
		std::cout << "2. Gestion de cuentas" << std::endl;
		std::cout << "3. Operaciones" << std::endl;
		std::cout << "4. Consultas" << std::endl;
		std::cin >> op;
		return op;
}



int main(int argc, char** argv) {
	std::list<Cliente> listaClientes; //lista simple de clientes
	std::list<Cuenta> listaCuentas; //lista simple de cuentas
	std::list<Operaciones> listaOperaciones; //lista simple de operaciones 
	std::queue<Cliente> clientesCola; //cola para los clientes
	std::stack<Cuenta> pilaCuentas; //pila para las cuentas
	bool flag = true;
	Cliente cliente1;
	Cuenta cuenta1;
	Operaciones op1;
	while(flag){
		bool flagCuenta = true;
		bool flagClients = true;
		bool flagOp = true;
		bool flagConsultas = true;
		switch(menu()){
			case 1:
				system("cls"); 
				while(flagClients){
					std::string idClient = ""; 
					int opGestionClientes = 0;
					bool encontrado;
					std:: string idN, nombreN, ciudadN;
					int estratoSocialN;
					std::cout << "Bienvenido a la gestion de clientes..." << std::endl;
		            std::cout << "Ingrese una opcion: " << std::endl;
		        	std::cout << "1. Ingresar cliente" << std::endl;
		        	std::cout << "2. Listar clientes" << std::endl;
		        	std::cout << "3. Modificar cliente" << std::endl;
		        	std::cout << "4. Anular o desanular cliente" << std::endl;
		        	std::cout << "5. Salir de la gestion de usuarios" << std::endl;
		        	std::cin >> opGestionClientes;
		        	system("cls"); 
					switch(opGestionClientes){
		        		case 1:
		        			cliente1 = Cliente(getInfoClient(listaClientes, clientesCola));
		        			listaClientes.push_back(cliente1);//añadiendo un cliente a la lista simple
		        			system("PAUSE"); 
							system("cls"); 
		        			break;
		        		case 2:
		        			std::cout << "Clientes registrados:" << std::endl;
							for (std::list<Cliente>::const_iterator it = listaClientes.begin(); it != listaClientes.end(); ++it) {
							    const Cliente& elemento = *it;
							    std::cout << elemento << std::endl;
							}	
							std::cout << std::endl;
							system("PAUSE"); 
							system("cls"); 
		        			break;
		        		case 3:
		        			idClient = "";
		        			idN = "", nombreN = "", estratoSocialN = 0, ciudadN = "";
							std::cout << "Ingrese el id del cliente que desea modificar:" << std::endl;
		        			std::cin >> idClient;
		        			encontrado = false;
		        			for (std::list<Cliente>::iterator it = listaClientes.begin(); it != listaClientes.end(); ++it) {
        						Cliente& elemento = *it; 
								if(elemento.id == idClient){
									encontrado = true;
									std::cout << "Cliente encontrado..." << std::endl;    
								    do{
								    	std::cout << "Ingresa tu id modificado: ";
								    	std::cin >> idN;
										if(verificarIdentidad(idN, listaClientes)){
											std::cout << "El id ya esta registrado... intenta con otro" << std::endl;
										}
									}while(verificarIdentidad(idN, listaClientes));
								    std::cout << "Ingresa tu nuevo nombre modificado: ";
								    std::cin >> nombreN;
								    std::cout << "Ingresa tu nuevo estrato social: ";
								    std::cin >> estratoSocialN;
								    std::cout << "Ingresa tu nueva ciudad: ";
								    std::cin >> ciudadN;
								    elemento.id = idN;
								    elemento.nombre = nombreN;
								    elemento.estratoSocial = estratoSocialN;
								    elemento.ciudad = ciudadN;
									std::cout << "Cliente modificado correctamente... " << std::endl;
									break;
								}
							}
							if (!encontrado) {
        						std::cout << "Cliente no encontrado." << std::endl;
    						}						
							system("PAUSE"); 
							system("cls"); 
		        			break;
		        		case 4:
		        			idClient = "";
							std::cout << "Ingrese el id del cliente que desea cambiar de estado:" << std::endl;
		        			std::cin >> idClient;
		        			encontrado = false;
		        			for (std::list<Cliente>::iterator it = listaClientes.begin(); it != listaClientes.end(); ++it) {
        						Cliente& elemento = *it; 
								if(elemento.id == idClient){
									int opEstadoClient = 0;
									encontrado = true;
									std::cout << "Cliente encontrado..." << std::endl;
									std::cout << "Ingrese una opcion: " << std::endl;
									std::cout << "1. Anular " << std::endl;
									std::cout << "2. Desanular " << std::endl;
									std::cin >> opEstadoClient;
									if(opEstadoClient == 1){
										elemento.activo = false;
										std::cout << "Cliente anulado con exito..." << std::endl;
									}else if(opEstadoClient == 2){
										elemento.activo = true;
										std::cout << "Cliente desanulado con exito..." << std::endl;
									}
									break;
								}
							}
							if (!encontrado) {
        						std::cout << "Cliente no encontrado." << std::endl;
    						}						
							system("PAUSE"); 
							system("cls"); 
		        			break;
		        		case 5:
		        			flagClients = false;
							break;
					}
				}
            
            break;
			case 2:
				system("cls"); 
				while(flagCuenta){
					bool cuentaEncontrada;
					int opGestionCuenta = 0;
					string numeroC = "", numeroCuenEliminar = "";
					std::cout << "Bienvenido a la gestion de cuentas..." << std::endl;
					std::cout << "Seleccione una opcion: " << std::endl;
					std::cout << "1. Ingresar cuenta" << std::endl;
					std::cout << "2. Ver cuentas ingresadas" << std::endl;
					std::cout << "3. Adicionar cuenta" << std::endl;
					std::cout << "4. Eliminar cuenta" << std::endl;
					std::cout << "5. Salir" << std::endl;
					std::cin >> opGestionCuenta;
					system("cls"); 
					switch(opGestionCuenta){
						case 1:
							cuenta1 = Cuenta(getInfoCuenta(listaClientes, listaCuentas,pilaCuentas));
							listaCuentas.push_back(cuenta1);//añadiendo una cuenta a la lista simple
							system("PAUSE"); 
							system("cls"); 
							break;
						case 2:
							std::cout << "Cuentas registradas:" << std::endl;
							for (std::list<Cuenta>::const_iterator it = listaCuentas.begin(); it != listaCuentas.end(); ++it) {
							    const Cuenta& elemento = *it;
							    std::cout << elemento << std::endl;
							}	
							std::cout << std::endl;
							system("PAUSE"); 
							system("cls"); 
							break;
						case 3:
								cuentaEncontrada = false;
								std::cout << "Ingrese el numero de cuenta al cual le desea adicionar dinero: " << std::endl;
								std::cin >> numeroC;
								for (std::list<Cuenta>::iterator it = listaCuentas.begin(); it != listaCuentas.end(); ++it) {
        						Cuenta& elemento = *it; 
								if(elemento.numeroCuenta == numeroC){
									cuentaEncontrada = true;
									int montoAdd = 0;
									std::cout << "Ingrese el monto que desea adicionar a la cuenta: " << std::endl;
									std::cin >> montoAdd;
									elemento.saldo += montoAdd;
									std::cout << "Se incremento el monto ingresado a la cuenta correctamente: " << std::endl;
									break;
								}
							}
							if (!cuentaEncontrada) {
        						std::cout << "Numero de cuenta no encontrada." << std::endl;
    						}
							system("PAUSE"); 
							system("cls"); 
							break;
						case 4:
							cuentaEncontrada = false;
							std::cout << "Ingrese el numero de cuenta al cual le desea eliminar: " << std::endl;
							std::cin >> numeroCuenEliminar;
							for (std::list<Cuenta>::iterator it = listaCuentas.begin(); it != listaCuentas.end(); ++it) {
        						Cuenta& elemento = *it; 
								if(elemento.numeroCuenta == numeroCuenEliminar){
									cuentaEncontrada = true;
									it = listaCuentas.erase(it);
									std::cout << "La cuenta ha sido eliminada correctamente: " << std::endl;
									break;
								}
							}
							if (!cuentaEncontrada) {
        						std::cout << "Numero de cuenta no encontrada." << std::endl;
    						}
							system("PAUSE"); 
							system("cls");
							break;
						case 5:
							flagCuenta = false;
							break;
					}
				}
			break;	
			case 3:
				system("cls"); 
				while(flagOp){
					int opGestioOp = 0;
					string nCuenta, nCuentaRetirar;
					bool cuentaEncontrada;
					int valorConsignacion, valorRetiro;
					std::cout << "Bienvenido a la gestion de operaciones..." << std::endl;
					std::cout << "Seleccione una opcion: " << std::endl;
					std::cout << "1. Ingresar una operacion" << std::endl;
					std::cout << "2. Consignar" << std::endl;
					std::cout << "3. Retirar" << std::endl;
					std::cout << "4. Salir" << std::endl;
					std::cin >> opGestioOp;
					system("cls");
					switch(opGestioOp){
						case 1:
							op1 = Operaciones(getInfoOp(listaCuentas));
							listaOperaciones.push_back(op1);
							system("PAUSE"); 
							system("cls");
							break;
						case 2:
							if(!listaOperaciones.empty()){
								std::cout << "Ingrese la cuenta a la cual le desea consignar..." << std::endl;
								std::cin >> nCuenta;
								for (std::list<Cuenta>::iterator it = listaCuentas.begin(); it != listaCuentas.end(); ++it) {
	        						Cuenta& elemento = *it; 
									if(elemento.numeroCuenta == nCuenta){
										cuentaEncontrada = true;
										std::cout << "La cuenta tiene un saldo de "<< elemento.saldo << std::endl;
										std::cout << "Ingrese el valor de la consignacion: " << std::endl;
										std::cin >> valorConsignacion;
										elemento.saldo += valorConsignacion;
										std::cout << "Se le ha consignado el dinero correctamente a la cuenta " << nCuenta << std::endl;
										std::cout << "La cuenta quedo con un saldo de: "<< elemento.saldo << std::endl;
										break;
									}
								}
								if (!cuentaEncontrada) {
	        						std::cout << "Numero de cuenta no encontrada." << std::endl;
	    						}
							}else{
								std::cout << "Primero debes ingresar una operacion al sistema para poder consignar dinero..." << std::endl;	
							}
							system("PAUSE"); 
							system("cls");
							break;
						case 3:
							if(!listaOperaciones.empty()){
								std::cout << "Ingrese su numero de cuenta para retirar..." << std::endl;
								std::cin >> nCuentaRetirar;
								for (std::list<Cuenta>::iterator it = listaCuentas.begin(); it != listaCuentas.end(); ++it) {
	        						Cuenta& elemento = *it; 
									if(elemento.numeroCuenta == nCuentaRetirar){
										cuentaEncontrada = true;
										std::cout << "En su cuenta bancaria tiene disponible "<<elemento.saldo <<" cuanto desea retirar?" << std::endl;
										std::cout << "Ingrese el valor que desea retirar..." << std::endl;
										std::cin >> valorRetiro;
										if(valorRetiro < elemento.saldo){
											elemento.saldo -= valorRetiro;
											std::cout << "Se ha retirado el dinero correctamente" << nCuenta << std::endl;
											std::cout << "Saldo disponible: "<<elemento.saldo << nCuenta << std::endl;
										}else{
											std::cout << "No tienes fondos suficientes para retirar esa cantidad de dinero..." << nCuenta << std::endl;
											std::cout << "Saldo disponible: "<<elemento.saldo << nCuenta << std::endl;
										}
										break;
									}
								}
								if (!cuentaEncontrada) {
	        						std::cout << "Numero de cuenta no encontrada." << std::endl;
	    						}
							}else{
								std::cout << "Primero debes ingresar una operacion al sistema para poder retirar dinero..." << std::endl;	
							}
							system("PAUSE"); 
							system("cls");
							break;
						case 4:
							flagOp = false;
							break;
					}
				}
				break;	
				case 4:
					system("cls"); 
					int opGestionConsultas;
					int totalCuentas = 0;
					while(flagConsultas){
						std::cout << "Bienvenido a la gestion de consultas..." << std::endl;
						std::cout << "Seleccione una opcion: " << std::endl;
						std::cout << "1. Ver cola" << std::endl;
						std::cout << "2. Ver pila" << std::endl;
						std::cout << "3. Salir" << std::endl;
						std::cin >> opGestionConsultas;
						system("cls");
						switch(opGestionConsultas){
							case 1:
								std::cout << "Elementos en la cola: "<<std::endl;
								std::cout << "Aca se mostraran los registros de los clientes de la ciudad de Cali que son estrato cuatro o superior " <<std::endl;
							    while (!clientesCola.empty()) {
							        std::cout << clientesCola.front() << std::endl;
							        clientesCola.pop();
							    }
							    std::cout << std::endl;
								system("PAUSE"); 
								system("cls");
								break;
							case 2:
								std::cout << "Elementos en la pila: " << std::endl;
								std::cout << "Aca se mostrara las cuentas cuyo saldo es mayor de 5.000.000 pesos y la suma de todas las cuentas" << std::endl;
								while (!pilaCuentas.empty()) {
							        std::cout << pilaCuentas.top() <<std::endl;
									Cuenta cuenta = pilaCuentas.top();
									totalCuentas += cuenta.saldo; 			        
									pilaCuentas.pop();
								}
							    std::cout << std::endl;
								std::cout << "La suma total de las cuentas es de: " << totalCuentas << std::endl;
							    system("PAUSE"); 
								system("cls");
								break;
							case 3:
								flagConsultas = false;
								break;
						}	
					}
					break;	
		}
	}
	return 0;
}


