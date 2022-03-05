load "httplib.ring"

oClient = new Client("localhost:8080")
? oClient.download("/one")
? oClient.download("/two")
