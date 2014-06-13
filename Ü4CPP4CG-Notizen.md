# Ü4 CPP4CG

Fehler:
-------

>engine.cpp
>gamemodel() & gamelogik()
>const & nicht-const Versionen
Referenz auf Argumente muss entfernt werden, also das "&" entfernen.

## Vorbereitungen

Modularität:

View: GlRenderer, AlRenderer
Controller: Logic
--> interpretieren bzw. aktualisieren das Modell lediglich


MVC-Pattern

view: lesend auf model zugreifen
controller: lese- und schreibzugriff


controller::glutEngine verbindet Modell und Delegierte

model::Game und model::GameObject speichern Zustand des Spiels und der
darin enthaltenen Objekte.

Entscheidung: eigenen Vektorklasse oder Eigen 3

## Modell, Komponenten und deren Delegierte

model::Game stellt Schnitstelle zwischen View und Controller dar.


## 4.1 Umbau der Engine

\maketick

## 4.2 Factory Klasse zur Erzeugung von Delegierten

TODO: Delegates für alles implementieren 

## 4.3 Nutzung von Delegierten

## 4.4 Integration einer einfachen Spiellogik

Aufteilungsmöglichkeit:

TODO: Audio / Physik









