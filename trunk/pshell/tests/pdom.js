myXML = new XML();
print("creating XML");
myXML.setName("test");
firstElement = myXML.newElement("firstElement");
firstElement.setValue("firstElementValue");
firstElement.setAttribute("firstAttribute","firstAttributeValue");
secondElement = myXML.newElement("secondElement");
secondElement.setValue("secondElementValue");
secondElement.setAttribute("secondAttribute","secondAttributeValue");
print("elementCount: " + myXML.getChildrenCount());
vector = myXML.getChildren();
for(i = 0; i <  myXML.getChildrenCount(); i++) {
	print("elementName: " + vector[i].getName() + " elementvalue: " + vector[i].getValue());
}

myXML.write("test.xml");

myLoadedXML = new XML();
if(myLoadedXML.load("test.xml")!=true) {
	print("erro carregando XML!!");
} else {
	print("XML carregado com sucesso!!");
}
print("dump:" + myLoadedXML.dumpTree());

loadedVector = myLoadedXML.getChildren();
print("ChildrenCount: " + myLoadedXML.getChildrenCount());
for(i = 0; i < myLoadedXML.getChildrenCount(); i++) {
	print("elementName: " + loadedVector[i].getName() + "elementvalue: " + loadedVector[i].getValue());
}
