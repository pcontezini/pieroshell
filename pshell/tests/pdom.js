myXML = new XML();
print("creating XML");
myXML.setName("test");
myXML.setAttribute("firstAttribute","firstAttributeValue");
firstElement = myXML.newElement("firstElement");
firstElement.setValue("firstElementValue");
firstElement.setAttribute("firstAttribute","firstAttributeValue");
secondElement = myXML.newElement("secondElement");
secondElement.setValue("secondElementValue");
secondElement.setAttribute("secondAttribute","secondAttributeValue");
print("elementCount: " + myXML.getChildrenCount());
vector = myXML.getChildren(); // falta o size
for(i = 0; i <  myXML.getChildrenCount(); i++) {
	print("elementName: " + vector[i].getName() + " elementvalue: " + vector[i].getValue());
}
attrVector = myXML.getAttributes();
print("attributeCount: " + myXML.getAttributeCount());
for(a = 0; a < myXML.getAttributeCount(); a++) {
	print("attributeName: " + attrVector[a].getName() + " attributevalue: " + attrVector[a].getValue());
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

attrVector = myLoadedXML.getAttributes();
print("attributeCount: " + myLoadedXML.getAttributeCount());
for(a = 0; a < myLoadedXML.getAttributeCount(); a++) {
	print("attributeName: " + attrVector[a].getName() + " attributevalue: " + attrVector[a].getValue());
}
