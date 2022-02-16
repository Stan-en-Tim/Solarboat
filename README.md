# Solarboat
Dit is de plek waar alle code en andere bestanden staan voor het profielwerkstuk over de solarboat.

De VEDirect library is een aangepaste versie van deze library: https://www.github.com/winginitau/VictronVEDirectArduino

Onder het mapje code staat de code die wij hebben gebruikt voor het testen. Deze code hebben wij ofwel aangepast ofwel volledig zelf geschreven (Dit staat ook aangegeven in comments in de code)

Het bestand ReadVEDirect.ino is gebruikt om met de MPPT's te communiceren.

Het bestand SoftwareSerialExampleMotor.ino is gebruikt om de motor verbinding af te luisteren.

In het mapje filmpjes staan een paar filmpjes die zijn gemaakt tijdens de testen, omdat github stom is moet je de filmpjes eerst downloaden voordat je ze kan bekijken.

slave_sender.ino is het programma voor de arduino wat is gebruikt om data te versturen naar een raspberry pi over i2c. Het is gebaseerd op een voorbeeld van wire.

i2c_Receiver.py is het programma voor de raspberry pi om data te ontvangen over i2c.
