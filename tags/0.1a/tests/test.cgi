#!/Users/pcontezini/devel/pshell/pshell
print("Content-type: text/html\r\n\r\n");
html = new XML();
html.setName("html");
body = html.newElement("body");
h1 = body.newElement("h1");
h1.setValue("teste de tag");
print(html.dumpTree());
