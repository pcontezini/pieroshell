soapLoader = new SOAP("http://www.positiva.tv:8080/service/MobusServer?WSDL");
services = soapLoader.listServices();
print(services);
for(i = 0; i < services.length; i++) {
	print("service name: " + services[i]);
}

service = soapLoader.getService(services[0]);
operations = service.listOperations();
print(operations);

data = service.Authenticate("terminal","terminal");

print(data.dumpTree());
