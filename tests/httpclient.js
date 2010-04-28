httpClient = new HTTPClient();
print("getting google main page: "  + httpClient.get("http://www.google.com"));
print("contents:");
print(httpClient.getData());
