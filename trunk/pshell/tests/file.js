file = new File("teste.file");
if(!file.Exists()) {
	print("Criando arquivo: " + file.Create());
} else {
	print("Arquivo ja existe, truncando ele:" + file.Truncate());
}
print("Escrevendo dados no arquivo:");
print(file.Write("teste de escrita"));
print("Voltando pro inicio do arquivo: " + file.Seek(0));
print("Lendo do arquivo: " + file.Read());
print("Removendo: " + file.Remove());
