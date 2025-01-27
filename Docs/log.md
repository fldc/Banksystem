# 2025-01-27 
## (Tillfälle 3 av boilerroom uppgiften)

Idag har vi påbörjat att skapa en logger klass som ska hantera hur vi loggar saker. Detta blir en **singelton**, vilket innebär att en stor del av metoderna är statiska och konstruktorn är privat. 

![Logger](Assets/LoggerUML.svg)
Understruket betyder att metoden är statisk.

Fördelen med att klassen är en singelton är att alla trådar kan komma åt den. 